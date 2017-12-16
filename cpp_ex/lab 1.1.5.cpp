//
//  main.cpp
//  lab1.5
//
//  Created by Johoric on 14/12/2017.
//  Copyright © 2017 Zihao Ding. All rights reserved.
//

#include <iostream>

using namespace std;

class Date; //forward declaration of class Date
class Time; //forward declaration of class Time

void display(Date &d, Time &t);


class Time{
public:
    Time(int, int, int);
    //constructor
    
    friend void display(Date &d, Time &t);
    
private:
    int hour; int minute; int sec;
};

class Date{
public:
    Date(int, int, int);
    friend void display(Date &d, Time &t);
    
private:
    int month; int day; int year;
};


Time::Time(int h, int m, int s){
    hour = h;
    minute = m;
    sec = s;
}


Date::Date(int m, int d, int y){
    month = m;
    day = d;
    year = y;
}


void display(Date &d, Time &t){
    cout << d.month << "/" << d.day << "/" << d.year << endl;
    cout << t.hour << ":" << t.minute << ":" << t.sec << endl;
}
//display is a  function whose parameter is a reference of class Date and Time



int main(int argc, const char * argv[]) {
    Time t1(10, 13, 56);
    Date d1(12, 25, 2004);
    display(d1, t1);
    return 0;
}
