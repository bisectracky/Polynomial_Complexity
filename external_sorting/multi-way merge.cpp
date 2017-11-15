#include<iostream>
#include<fstream>
#include <time.h>
#include <stdlib.h>
#include "record.h"
#include "buffer.h"
#define N 30  
#define SIZE 512   //the number of records that one block can contain
using namespace std;

class work_area{
private:
	record array[8][SIZE];
	int cur[8];   //哪一个位置已经写入元素
	int has_read[8]; //哪一个位置的元素已经处理过 
public:
	work_area(){
		for(int i=0;i<8;i++){
			cur[i]=0;
			has_read[i]=0; 
		}
	}
	void initial(){
		for(int i=0;i<8;i++){
			cur[i]=0;
			has_read[i]=0; 
		}
	}
	void append(int x,int id,float key){
		array[x][cur[x]].set_id(id);
		array[x][cur[x]].set_key(key);
		cur[x]++;
		has_read[x]=0;
	}
	void show(){
		for(int i=0;i<8;i++){
			cout<<"第"<<i<<"个run，cur="<<cur[i]<<",";
			for(int j=0;j<cur[i];j++){
				cout<<array[i][j].get_id()<<"  ";
			} 
			cout<<endl;
		}
	}
	bool all_empty(int s){
		int sum=0;
		for(int i=0;i<s;i++){
			sum+=cur[i];
		}
		if(sum==0)	return true;
		else return false;
	}
	int get_id(int x){
		int s=has_read[x];
		return array[x][s].get_id();
	}
	record get(int x){
		int s=has_read[x];
		has_read[x]+=1;
		return array[x][s];
	}
	int get_have_read(int x){
		return has_read[x];
	}
	void set_cur(int x){
		cur[x]=0;
	}
	int get_cur(int x){
		return cur[x];
	}
};


int main(){
	srand((unsigned)time(NULL)); 
	clock_t start,finish;
	fstream ft;
	ft.open("temporary.txt",ios::in);
	if(ft.fail()){
		cout<<"fail to open the file!"<<endl;
		exit(1);
	}
	int num;
	ft>>num;
	int length[num],pos[num];
	for(int i=0;i<num;i++){
		ft>>length[i];
	}
	ft.close();
	for(int i=0;i<num;i++){
		if(i==0)	pos[i]=0;
		else	pos[i]=pos[i-1]+length[i-1];
	}

	
	
	//suppose that num<=64
	int pass;
	if(num<=8)	pass=0;
	else{
		pass=num/8;
		if(num%8!=0)	pass++;
	}	
	int op1=num%8;
	int op2=pass;
	
	int runs[pass];
	for(int i=0;i<pass;i++)	runs[i]=0; 
	
	
	start=clock();
	fstream fr,fw,fs;	
	work_area work;
	output_buffer output;
	int ccc=0;
	int id;
	float key;
	fr.open("run file.dat",ios::in|ios::binary);
	if(fr.fail()){
		cout<<"fail to open the file!"<<endl;
		exit(1);
	}
	fw.open("run file 2.dat",ios::out|ios::binary);
	fs.open("statistics file.txt",ios::app|ios::out);
	fs<<"the number of pass is "<<pass+1<<endl;
//	cout<<pass<<endl; 
	for(int pas=0;pas<pass;pas++){
		int cur[8];
		for(int i=0;i<8;i++){
			cur[i]=0;
		}
		int op;
		if(num<8)	op=num;
		else if(num==8)	op=8;
		else if(num>8){
			if(num%8==0){
				if(pas<pass)	op=8;
				else op=op2;
			}
			else{
				if(pas<pass-1)	op=8;
				else if(pas==pass-1)	op=op1;
				else op=op2;
			}
		} 
		fs<<"in the "<<pas+1<<"th pass, it merges "<<op<<" runs"<<endl;
	//	cout<<op<<endl;
		for(int i=0;i<op;i++){
			int t=pos[i+8*pas];
			fr.seekg(t*8,ios::beg);
			for(int j=0;j<SIZE;j++){
				fr.read((char*)(&id),4);
				fr.read((char*)(&key),4);
				work.append(i,id,key);
				cur[i]++;
			}
		}
		int k=1;
		int sum=0;
		for(int i=0;i<op;i++){
			sum+=length[i+8*pas];
		}
		runs[pas]=sum;
		while(k<=sum){
			int flag=-1;
			for(int i=0;i<op;i++){
				if(work.get_cur(i)!=0){
					flag=i;
					break;
				}
			}
			for(int i=flag+1;i<op;i++){
				if((work.get_cur(i)!=0)&&(work.get_id(i)<work.get_id(flag)))	flag=i;
			}
			record t;
			t.set_all(work.get(flag));
		//	cout<<k<<"   "<<flag<<"   "<<t.get_id()<<endl;
		//	cout<<work.get_have_read(flag)<<endl;
			if(work.get_have_read(flag)==work.get_cur(flag)){
				if(cur[flag]==length[flag+8*pas]){
					work.set_cur(flag);
				}
				else{
					work.set_cur(flag);
					int t=pos[flag+8*pas]+cur[flag];
					fr.seekg(t*8,ios::beg);
					for(int j=0;(j<SIZE)&&(cur[flag]<length[flag+8*pas]);j++){
						int id;
						float key;
						fr.read((char*)(&id),4);
						fr.read((char*)(&key),4);
						work.append(flag,id,key);
						cur[flag]++;
					}
				}
			}	
			output.append_a_record(t);
			if(output.get_cur()==SIZE)	output.write_one_block(fw);
			k++;
		}
		work.initial();
	}
	fr.close();
	fr.close();
	
	fstream fruns,final;
	if(num<=8)	fruns.open("run file.dat",ios::in|ios::binary);
	else	fruns.open("run file 2.dat",ios::in|ios::binary);
	final.open("records.dat",ios::out|ios::binary);
	int runspos[8];
	if(num>8){
		for(int i=0;i<pass;i++){
			if(i==0)	runspos[i]=0;
			else	runspos[i]=runspos[i-1]+runs[i-1];
		}
	}
	else{
		pass=num;
		for(int i=0;i<pass;i++){
			runspos[i]=pos[i];
			runs[i]=length[i];
		}
	}

		
	int cur[8];
	for(int i=0;i<8;i++){
		cur[i]=0;
	}
	int op=pass;
	if(num>8)	fs<<"in the "<<pass+1<<"th pass, it merges "<<op<<" runs"<<endl;	
	else	fs<<"in the "<<1<<"th pass, it merges "<<op<<" runs"<<endl;
	for(int i=0;i<op;i++){
		int t=runspos[i];
		fruns.seekg(t*8,ios::beg);
		for(int j=0;j<SIZE;j++){
			fruns.read((char*)(&id),4);
			fruns.read((char*)(&key),4);
			work.append(i,id,key);
			cur[i]++;
			}
	}
	int k=1;
	while(k<=8*N*SIZE){
		int flag=-1;
		for(int i=0;i<op;i++){
			if(work.get_cur(i)!=0){
				flag=i;
				break;
			}		
		}
		for(int i=flag+1;i<op;i++){
			if((work.get_cur(i)!=0)&&(work.get_id(i)<work.get_id(flag)))	flag=i;
		}
		record t;
		t.set_all(work.get(flag));
		if(work.get_have_read(flag)==work.get_cur(flag)){
			if(cur[flag]==runs[flag]){
				work.set_cur(flag);
			}
			else{
				work.set_cur(flag);
				int t=runspos[flag]+cur[flag];
				fruns.seekg(t*8,ios::beg);
				for(int j=0;(j<SIZE)&&(cur[flag]<runs[flag]);j++){
					int id;
					float key;
					fruns.read((char*)(&id),4);
					fruns.read((char*)(&key),4);
					work.append(flag,id,key);
					cur[flag]++;
				}
			}
		}	
		output.append_a_record(t);
		if(output.get_cur()==SIZE)	output.write_one_block(final);
		k++;
	}
	work.initial();
	fruns.close();
	final.close();
	finish=clock();
	fs<<"The time taken to do the multi-way merge is "<<(double)(finish - start) / CLOCKS_PER_SEC<<"s"<<endl;
	fs<<endl;
	fs.close();
	return 0;
} 
