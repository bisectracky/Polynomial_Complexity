#pragma once
#include<iostream>
#include<fstream>
#include "record.h"
#define N 30  
#define SIZE 512   //the number of records that one block can contain
using namespace std;

class input_buffer{
private:
	record array[SIZE];
	int cur;
public:
	input_buffer(){
		cur=0;
	}
	void read_in_one_block(fstream& f){
		cur=0;
		int id;
		float key;
		for(int i=0;(i<SIZE)&&(!f.eof());i++){
			f.read((char*)(&id),4);
			f.read((char*)(&key),4);
			array[i].set_id(id);
			array[i].set_key(key);
		}
		return;
	}
	record get_one_record(){
		return array[cur++];
	}
	int get_cur(){
		return cur;
	}
};

class output_buffer{
private:
	record array[SIZE];
	int cur;
public:
	output_buffer(){
		cur=0;
	}
	void append_a_record(record t){
		array[cur].set_all(t);
		cur++;
		return;
	}
	int get_cur(){
		return cur;
	}
	void write_one_block(fstream& f){
		int id;
		float key;
		for(int i=0;i<SIZE;i++){
			id=array[i].get_id();
			key=array[i].get_key();
			f.write((char*)(&id),4);
			f.write((char*)(&key),4);
		}
		cur=0;
		return;
	}
};
