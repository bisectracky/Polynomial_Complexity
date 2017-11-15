#include<iostream>
#include<fstream>
#include <time.h>
#include <stdlib.h>
#include "buffer.h"
#include "RAM.h" 
#define N 30
#define SIZE 512   //the number of records that one block can contain
using namespace std;


int main(){
	srand((unsigned)time(NULL)); 
	clock_t start,finish;
	RAM ram;
	input_buffer input;
	output_buffer output;
	start=clock();
	fstream fr,fw;   //the record file
	fr.open("records.dat",ios::in|ios::binary);	 
	if(fr.fail()){
		cout<<"fail to open the file!"<<endl;
		exit(1);
	}
	fw.open("run file.dat",ios::out|ios::binary);
	for(int i=0;i<8;i++){
		input.read_in_one_block(fr);
		for(int i=0;i<SIZE;i++){
			record temp=input.get_one_record();
			ram.append_a_record(temp);
		}
	}
	int length[N+10];
	for(int i=0;i<N+10;i++){
		length[i]=0;
	}
	int count=1;
	while(fr.peek()!=EOF||input.get_cur()!=SIZE){
		ram.build_heap();
		while(ram.get_last()!=-1){
			record min=ram.get_record(0);
			output.append_a_record(min);
			length[count]++;
			if(output.get_cur()==SIZE)	output.write_one_block(fw);
			if(input.get_cur()<SIZE){
				record temp=input.get_one_record();
				if(temp.get_id()>min.get_id()) ram.put_to_root(temp);
				else	ram.put_to_last(temp);				
			}
			else{
				if(fr.peek()!=EOF){
					input.read_in_one_block(fr);
					record temp=input.get_one_record();
					if(temp.get_id()>min.get_id()) ram.put_to_root(temp);
					else	ram.put_to_last(temp);					
				}
				else{
					ram.last_to_root();
				}
			}
		}				
		count+=1;
	}
	if((ram.get_flag()!=-1)&&(ram.get_flag()!=8*SIZE)){
		ram.move_to_front();
		ram.build_heap();
		while(ram.get_last()!=-1){
			record min=ram.get_record(0);
			output.append_a_record(min);
			length[count]++;
			if(output.get_cur()==SIZE)	output.write_one_block(fw);	
			ram.last_to_root();	
		}
		count++;
	}	
//	cout<<--count<<endl;
	count--;
/*	for(int i=1;i<=count;i++){
		if(length[i]!=0)	cout<<"第"<<i<<"条run的长度是："<<length[i]<<endl; 
	}*/ 
	fr.close();
	fw.close();
	finish=clock();
	fstream ft,fs;
	ft.open("temporary.txt",ios::out);
	ft<<count<<endl;
	for(int i=1;i<=count;i++){
		ft<<length[i]<<endl;
	}
	fs.open("statistics file.txt",ios::app|ios::out);
	fs<<"In this test, N= "<<N<<", SIZE= "<<SIZE<<endl;
	fs<<"The number of runs is "<<count<<endl;
	for(int i=1;i<=count;i++){
		if(length[i]!=0)	fs<<"the length of the "<<i<<"th run is："<<length[i]<<endl; 
	} 
	fs<<"The time taken to do the replacement selection is "<<(double)(finish - start) / CLOCKS_PER_SEC<<"s"<<endl;
	ft.close();
	fs.close();
	return 0;
} 
