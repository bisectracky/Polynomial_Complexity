//
//  main.cpp
//  lab1.3
//
//  Created by Johoric on 14/12/2017.
//  Copyright © 2017 Zihao Ding. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class salesclerk{
private:
    int num;    int quantity;   float price;
    static int total_quantity;
    static float total_income;
    
public:
    salesclerk(int n, int q, float p): num(n), quantity(q), price(p){
        cout << "Construct a salesclerk" << endl;
        total_quantity += q;
        float temp = q*p;
        total_income += temp;
    }
    ~salesclerk(){
        cout << "Destruct a salesclerk" << endl;
    }
    static void makeInventory(){
        cout << "Salesclerks have sold " << total_quantity << " pieces of product, with total income of " << total_income << "." << endl;
    }
};

int salesclerk::total_quantity = 0;
float salesclerk::total_income = 0.0;

int main(int argc, const char * argv[]) {
    salesclerk a(555, 3, 69.5);
    salesclerk b(556, 11, 70.0);
    salesclerk c(557, 50, 68.5);
    salesclerk::makeInventory();
    return 0;
}
