//
//  main.cpp
//  lab 1.3
//
//  Created by Johoric on 18/12/2017.
//  Copyright © 2017 Zihao Ding. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    string name = "";
    int age = 0;
    char gender = '\0';
    static int counter;
public:
    Person();
    Person(string s, int i, char c) :name(s), age(i), gender(c) { counter++; }
    ~Person();
    void set(string s, int i, char c);//³õÊ¼»¯ÁÐ±íÖ»ÄÜÓÃÓÚ¹¹Ôìº¯ÊýÂð
    void show() const;
    static int get_counter();
};
class Teacher:public Person
{
private:
    string workno = "";
    string rank = "";
public:
    Teacher() = default;//even default, will invoke Person's constructor, will increase the counter
    Teacher(string s1, int i, char c, string s2, string s3) :Person(s1, i, c), workno(s2), rank(s3) {}
    ~Teacher() = default;//even default, will invoke Person's destructor, will decrease the counter
    void show() const;
    void set(string s1, int i, char c, string s2, string s3);
    static int get_counter();
};
class Undergraduate :protected Person
{
private:
    string stuno = "";
    string dept = "";
public:
    Undergraduate() = default;
    Undergraduate(string s1, int i, char c, string s2, string s3) :Person(s1, i, c), stuno(s2), dept(s3) {}
    ~Undergraduate() = default;
    void set(string s1, int i, char c, string s2, string s3);
    void show() const;
    static int get_counter();
};
class Postgraduate :private Person
{
private:
    string stuno = "";
    string dept = "";
    string mentor = "";
public:
    Postgraduate() = default;
    Postgraduate(string s1, int i, char c, string s2, string s3, string s4) :Person(s1, i, c), stuno(s2), dept(s3), mentor(s4) {}
    ~Postgraduate() = default;
    void set(string s1, int i, char c, string s2, string s3, string s4);
    void show() const;
    static int get_counter();
};
int Person::counter = 0;
Person::Person()//¹¹Ôìº¯ÊýÎÞ·µ»ØÀàÐÍ
{
    counter++;
}
Person::~Person()
{
    counter--;
}
void Person::set(string s, int i, char c)
{
    name = s;
    age = i;
    gender = c;
}
void Person::show() const
{
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Gender:" << gender << endl;
}
int Person::get_counter()
{
    return counter;
}
void Teacher::show() const
{
    Person::show();
    cout << "Work number: " << workno << endl;
    cout << "Rank: " << rank << endl << endl;
}
void Teacher::set(string s1, int i, char c, string s2, string s3)
{
    Person::set(s1, i, c);
    workno = s2;
    rank = s3;
}
int Teacher::get_counter()
{
    return Person::get_counter();
}
void Undergraduate::set(string s1, int i, char c, string s2, string s3)
{
    Person::set(s1, i, c);
    stuno = s2;
    dept = s3;
}
void Undergraduate::show() const
{
    Person::show();
    cout << "Student number: " << stuno << endl;
    cout << "Department: " << dept << endl << endl;
}
int Undergraduate::get_counter()
{
    return Person::get_counter();
}
void Postgraduate::set(string s1, int i, char c, string s2, string s3, string s4)
{
    Person::set(s1, i, c);
    stuno = s2;
    dept = s3;
    mentor = s4;
}
void Postgraduate::show() const
{
    Person::show();
    cout << "Student number: " << stuno << endl;
    cout << "Department: " << dept << endl;
    cout << "Mentor: " << mentor << endl << endl;
}
int Postgraduate::get_counter()
{
    return Person::get_counter();
}

int main()
{
    Teacher t1("David", 48, 'M', "1001", "Professor"), t2("Linda", 32, 'F', "1002", "Lecturer");
    Undergraduate s1("Julio", 18, 'M', "153330101", "Computer"), s2("Jenko", 22, 'M', "112220503", "Software");
    Postgraduate p1("Nadonna", 22, 'F', "153450121", "Computer", "David"), p2("Li meimei", 24, 'F', "132450209", "Software", "Kevin");
    t1.show();
    t2.show();
    s1.show();
    s2.show();
    p1.show();
    p2.show();
    cout << "Total of faculty & student: " << Person::get_counter() << endl;
    return 0;
}

