#include<iostream>
#include<fstream>
#include <time.h>
#include <stdlib.h>
#include "record.h" 
#define N 30   
#define SIZE 512   //the number of records that one block can contain
using namespace std;

class Heap{
private:
	record heap[8*SIZE];
	int n;  // number of elements now in the heap
public:
	Heap(){
		n=0;
	}
	
	void insert(record temp){
		int cur=n++;
		heap[cur].set_all(temp);
		while((cur!=0)&&(prior))
	}
	
	void build_heap(){
		;
	}
};
