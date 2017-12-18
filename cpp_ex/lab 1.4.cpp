//
//  main.cpp
//  lab 1.4
//
//  Created by Johoric on 18/12/2017.
//  Copyright © 2017 Zihao Ding. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class EmployeeRole
{
protected:
    int No = 0;
    string name;
    float salary = 0.0;
    string role;
    static int totalNo;
public:
    EmployeeRole()
    {
        No = ++totalNo;
        salary = 0;
    }
    ~EmployeeRole() { totalNo--; }
    virtual void pay() = 0;
    virtual void display() const = 0;
};
class ManagerRole :public EmployeeRole
{
public:
    ManagerRole()
    {
        role = "Manager";
        cout << "Please input the " << role << "'s name:";
        cin >> name;
    }
    void pay() override;
    void display() const override;
};
class TechnicianRole :public EmployeeRole
{
protected:
    int hours = 0;
public:
    TechnicianRole()
    {
        role = "Technician";
        cout << "Please input the " << role << "'s name:";
        cin >> name;
        cout << "Please input the service hours of " << name << '(' << role << "):";
        cin >> hours;
    }
    void pay() override;
    void display() const override;
};
class SalesRole :public EmployeeRole
{
protected:
    float salesnum = 0.0;
public:
    SalesRole()
    {
        role = "Sales";
        cout << "Please input the " << role << "'s name:";
        cin >> name;
        cout << "Please input the total sales of " << name << '(' << role << "):";
        cin >> salesnum;
    }
    void pay() override;
    void display() const override;
};
class Employee
{
private:
    EmployeeRole &role;
public:
    Employee(const EmployeeRole &r) :role(const_cast<EmployeeRole &>(r)) {}
    void pay();
    void display();
};
void Employee::pay()
{
    role.pay();
}
void Employee::display()
{
    role.display();
}
void ManagerRole::pay()
{
    salary = 8000;
}
void ManagerRole::display() const
{
    cout << name << '(' << role << ")," << No << ',' << salary << endl;
}
void TechnicianRole::pay()
{
    salary = 50 * hours;
}
void TechnicianRole::display() const
{
    cout << name << '(' << role << ")," << No << ',' << salary << endl;
}
void SalesRole::pay()
{
    salary = 0.03*salesnum;
}
void SalesRole::display() const
{
    cout << name << '(' << role << ")," << No << ',' << salary << endl;
}
int EmployeeRole::totalNo = 0;

int main()
{
    const ManagerRole manager;
    const TechnicianRole technician;
    const SalesRole sales;
    Employee *emp[] = { new Employee(manager), new Employee(technician), new Employee(sales) };
    for (auto e : emp)
        e->pay();
    cout << "\nHere goes the pays\n===================" << endl;
    for (auto e : emp)
        e->display();
    return 0;
}

