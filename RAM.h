#pragma once
#include<iostream>
#include<fstream>
#include "record.h"
#include "prior.h"
#define N 30   
#define SIZE 512   //the number of records that one block can contain
using namespace std;

void swap(record* array,int a,int b){
	record temp;
	temp.set_all(array[a]);
	array[a].set_all(array[b]);
	array[b].set_all(temp);
	return;
}

class RAM{
private:
	record array[8*SIZE];
	int n;  //number of elements in the heap
	int last;
	int cur;  // the current position in the array
	int flag;
	void siftdown(int pos){
		while(!isLeaf(pos)){
			int j=leftchild(pos);
			int rc=rightchild(pos);
			if((rc<n)&&prior(array[rc],array[j])){
				j=rc;
			}
			if(prior(array[pos],array[j]))	return;
			swap(array,pos,j);
			pos=j;
		}
	}
public:
	RAM(){
		cur=0;
		last=0;
		n=0;
		flag=-1;
	}
	int parent(int pos){
		return (pos-1)/2;
	}	
	bool isLeaf(int pos){
		return (pos>=n/2)&&(pos<n);
	}
	int leftchild(int pos){
		return 2*pos+1;
	}
	int rightchild(int pos){
		return 2*pos+2;
	}
	void append_a_record(record temp){
		array[cur].set_all(temp);
		cur++;
		return;
	}	
	void insert_to_heap(record temp){
		int curr=n++;
		array[curr].set_all(temp);
		while((curr!=0)&&(prior(array[curr],array[parent(curr)]))){
			swap(array,curr,parent(curr));
			curr=parent(curr);
		}
		return;
	}	
	void build_heap(){
		n=0;
		last=cur-1;
		for(int i=0;i<cur;i++){
			insert_to_heap(array[i]);
		//	cout<<array[i].get_id()<<endl;
		}
		return;
	}	
	int get_last(){
		return last;
	}	
	record get_record(int pos){
		return array[pos];
	}	
	void put_to_root(record t){
		array[0].set_all(t);
		siftdown(0);
		return;
	}
	void put_to_last(record t){
		array[0].set_all(array[last]);
		array[last].set_all(t);
		n--;
		last--;
		if(n>0) siftdown(0);
		return;
	}
	void last_to_root(){
		if(flag==-1) flag=last+1;
		array[0].set_all(array[last]);
		n--;
		last--;
		siftdown(0);
		return;
	}
	void show(){
		for(int i=0;i<cur;i++){
			cout<<array[i].get_id()<<endl;
		}
	}
	void move_to_front(){
		int count=8*SIZE-flag;
		int pos=flag;
		for(int i=0;i<count;i++){
			array[i].set_all(array[pos]);
			pos++;
		}
		cur=count;
	}
	void decrease_last(){
		last--;
	}
	int get_n(){
		return n;
	}
	int get_flag(){
		return flag;
	}
	int get_cur(){
		return cur;
	}
};
