#pragma once
#include<iostream>
using namespace std;
//finish
class record{
private:
	int id;
	float key;
public:
	record(){
		;
	}
	record(int id,float key){
		this->id=id;
		this->key=key;
	}
	void set_id(int id){
		this->id=id;
	}
	void set_key(float key){
		this->key=key;
	}
	int get_id(){
		return id;
	}
	float get_key(){
		return key;
	}
	void set_all(record temp){
		set_id(temp.get_id());
		set_key(temp.get_key());
		return;
	}
};
