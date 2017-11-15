#include<iostream>
#include<fstream>
#include <time.h>
#include <stdlib.h>
#include<stdio.h>
#define N 20   
#define SIZE 512   //the number of records that one block can contain
using namespace std;

int main(){
	fstream f,ft;
	int id;
	float key;
	int count=0;
	cout<<"ID          key"<<endl;
	f.open("records.dat",ios::in|ios::binary);
	while(f.peek()!=EOF){
		f.read((char*)(&id),4);
		f.read((char*)(&key),4);
		cout<<id<<"   "<<key<<endl;
		count++;
	}
	f.close();	
	return 0;
}
