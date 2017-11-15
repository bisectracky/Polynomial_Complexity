#include<iostream>
#include<fstream>
#include <time.h>
#include <stdlib.h>
#define N 30  
#define SIZE 512   //the number of records that one block can contain
using namespace std;

float rand_float(){
	return (double)(rand())/115;
}

int rand_int(){
	return rand()%3000;
}

int main(){
	srand((unsigned)time(NULL)); 
	fstream f;
	int id;
	float key;
	f.open("records.dat",ios::out|ios::binary);
	for(int i=0;i<8*N*SIZE;i++){
		id=rand_int();
		key=rand_float();
		f.write((char*)(&id),4);
		f.write((char*)(&key),4);
	}
	f.close();	
	cout<<"creat the file successfully!";
	return 0;
}
