#include<iostream>
#include "record.h"
using namespace std;
//finish
bool prior(record a,record b){
	if(a.get_id()<=b.get_id()){
		return true;
	}
	else return false;
}
