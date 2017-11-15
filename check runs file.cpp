#include<iostream>
#include<fstream>
#include <time.h>
#include <stdlib.h>
#include<stdio.h>
#define N 20  
#define SIZE 2   //the number of records that one block can contain
using namespace std;

int main(){
	fstream f,ft;
	int id;
	float key;
	f.open("run file.dat",ios::in|ios::binary);
	ft.open("temporary.txt",ios::in);
	int num;
	ft>>num;
	int length[num],pos[num];
	for(int i=0;i<num;i++){
		ft>>length[i];
	}
	cout<<"the number of the runs is "<<num<<endl;
	for(int i=1;i<num+1;i++){
		cout<<"the length of the "<<i<<"th run£º"<<endl;
		for(int j=0;j<length[i-1];j++){
			f.read((char*)(&id),4);
			f.read((char*)(&key),4);
			cout<<id<<"   "<<key<<endl;		
		}			
	}
	f.close();	
	return 0;
}
