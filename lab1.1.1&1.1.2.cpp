//
//  main.cpp
//  lab1
//
//  Created by Johoric on 15/11/2017.
//  Copyright © 2017 Zihao Ding. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>

#define N 10

using namespace std;

class Person{
public:
    /*constructors & destructor*/
    Person() {
        cout << "construct a Person first way (calling the default constructor)" << endl;
    }//default constructor
    
    Person(string n): name(n){
        cout << "construct a Person second way" << endl;
    }//construct by providing a name
    
    Person(string n, int a, string ad): name(n), age(a), address(ad){
        cout << "construct a Person third way" << endl;
    }//construct by providing a name, age and address
    
    Person(Person& p){
        name = p.name;
        address = p.address;
        age = p.age;
        cout << "construct a Person fourth way (calling the copy constructor)" << endl;
    }//construct by providing a name, age and address in standard iuput/output stream
    
    ~Person(){
        cout << "destruct a Person" << endl;
    }//destructor
    
    /*public interface function*/
    string getName();
    int getAge();
    string getAddress();
    void read();//read a person's information by standard input
    void print();//print a person's information by standard output

    friend class Team;
private:
    string name = "Zhang San";
    string address = "LAB";
    int age = 20;
};


class Team{
public:
    Team(){
        cout << "construct a Team first way (calling the default constructor)" << endl;
    };//default constructor
    
    void read();//read a Team's information by standard input
    void print();//print a Team's information by standard output
    
private:
    Person p[N];
    int num;
};


void Team::read(){
    char temp;
    for(int i=0; i<N; i++){
        switch (i) {
            case 0:
                cout << "Provide the first person's name" << endl;
                cin >> this->p[i].name;
                cout << "Provide the first person's age" << endl;
                cin >> this->p[i].age;
                cout << "Provide the first person's address" << endl;
                cin >> this->p[i].address;
                break;
            case 1:
                cout << "Provide the second person's name" << endl;
                cin >> this->p[i].name;
                cout << "Provide the second person's age" << endl;
                cin >> this->p[i].age;
                cout << "Provide the second person's address" << endl;
                cin >> this->p[i].address;
                break;
            case 2:
                cout << "Provide the third person's name" << endl;
                cin >> this->p[i].name;
                cout << "Provide the third person's age" << endl;
                cin >> this->p[i].age;
                cout << "Provide the third person's address" << endl;
                cin >> this->p[i].address;
                break;
            default:
                cout << "Provide the " << i+1 << "-th " << "person's name" << endl;
                cin >> this->p[i].name;
                cout << "Provide the " << i+1 << "-th " << "person's age" << endl;
                cin >> this->p[i].age;
                cout << "Provide the " << i+1 << "-th " << "person's address" << endl;
                cin >> this->p[i].address;
                break;
        }
        this->num++;
        cout << "Any more person in this team? (Y/N)" << endl;
        cin >> temp;
        if(temp == 'Y')
            continue;
        else{
            return;
        }
    }
    return;
}


void Team::print(){
    cout << "The team has " << this->num << " members." << endl;
    for(int i=0; i<this->num; i++){
        switch (i) {
            case 0:
                cout << "The first person's name is " << this->p[i].name << endl;
                cout << "The first person's age is " << this->p[i].age << endl;
                cout << "The first person's address is " << this->p[i].address << endl;
                break;
            case 1:
                cout << "The second person's name is " << this->p[i].name << endl;
                cout << "The second person's age is " << this->p[i].age << endl;
                cout << "The second person's address is " << this->p[i].address << endl;
                break;
            case 2:
                cout << "The third person's name is " << this->p[i].name << endl;
                cout << "The third person's age is " << this->p[i].age << endl;
                cout << "The third person's address is " << this->p[i].address << endl;
                break;
            default:
                cout << "The " << i+1 << "-th " << "person's name is " << this->p[i].name << endl;
                cout << "The " << i+1 << "-th " << "person's age " << this->p[i].age << endl;
                cout << "The " << i+1 << "-th " << "person's address " << this->p[i].address << endl;
                break;
        }
    }
}

string Person::getName(){
    return name;
}//return name
int Person::getAge(){
    return age;
}//return age
string Person::getAddress(){
    return address;
}//return address


void Person::read(){
    cout << "Provide a person's name" << endl;
    cin >> this->name;
    cout << "Provide a person's age" << endl;
    cin >> this->age;
    cout << "Provide a person's address" << endl;
    cin >> this->address;
    return;
}

void Person::print(){
    cout << "The person's name is " << getName() << endl;
    cout << "The person's age is " << getAge() << endl;
    cout << "The person's address is " << getAddress() << endl;
    return;
}


int main(int argc, const char * argv[]) {
    /**************************************************
     Note: This part is for testing section 1 of exp 1
     **************************************************/
    Person a;
    //test default construction
    a.print();
    
    Person b("Ding");
    //test construction by providing a name
    b.print();
   
    Person c("Zihao", 20, "UESTC");
    //test construction by providing a name, age and address
    c.print();
    
    Person d;
    d.read();
    d.print();
    
    Team e;
    e.read();
    e.print();
    /**************************************************
     Note: This part is for testing section 2 of exp 1
     **************************************************/
    
    return 0;
}
