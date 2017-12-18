//
//  main.cpp
//  lab1.2
//
//  Created by Johoric on 15/12/2017.
//  Copyright © 2017 Zihao Ding. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

class myComplex{
private:
    double real;
    double imag;
    
public:
    myComplex(): real(0), imag(0){
        cout << "Calling default constructor" << endl;
    }
    
    myComplex(double a):real(a),imag(0){
        cout << "Construct a complex number with only real part" << endl;
    }
    
    myComplex(double a, double b):real(a),imag(b){
        cout << "Construct a complex number with both real and imaginary part" << endl;
    }
    
    myComplex(const myComplex& v){
        real = v.real;
        imag = v.imag;
        cout << "Calling copy constructor" << endl;
    }
    
    double getReal() const{
        return real;
    }
    
    double getImaginary() const {
        return imag;
    }
    
    double getModulus() const{
        return sqrt(imag * imag + real * real);
    }
    
    myComplex& operator=(const myComplex& rhs){
        real = rhs.real;
        imag = rhs.imag;
        return *this;
    }//return a reference, which means what is returned is a left value
    
    myComplex& operator+=(myComplex& rhs){
        real += rhs.real;
        imag += rhs.imag;
        return *this;
    }
    
    myComplex& operator-=(myComplex& rhs){
        real -= rhs.real;
        imag -= rhs.imag;
        return *this;
    }
    
    myComplex& operator*=(myComplex& rhs){
        double r = real * rhs.real - imag * rhs.imag;
        double i = real * rhs.imag - imag * rhs.real;
        double m = rhs.real * rhs.real + rhs.imag * rhs.imag;
        real = r / m;
        imag = i / m;
        return *this;
    }
    
    myComplex& operator/=(myComplex& rhs){
        if(fabs(rhs.getModulus()) < 1E-8)
            throw "divided by zero";
        
        double r = real * rhs.real + imag * rhs.imag;
        double i = real * rhs.imag - imag * rhs.real;
        double m = rhs.real * rhs.real + rhs.imag * rhs.imag;
        real = r / m;
        imag = i / m;
        
        return *this;
    }
    
    friend myComplex operator+(const myComplex &oprd1, const myComplex &oprd2);
    friend myComplex operator-(const myComplex &oprd1, const myComplex &oprd2);
    friend myComplex operator*(const myComplex &oprd1, const myComplex &oprd2);
    friend myComplex operator/(const myComplex &oprd1, const myComplex &oprd2);
    
    
    friend ostream& operator<<(ostream& os, const myComplex c);
    friend istream& operator<<(istream& is, myComplex& c);
    
};


//overloaded as non-member function
myComplex operator+(const myComplex &oprd1, const myComplex &oprd2){
    myComplex temp;
    temp.real = oprd1.real + oprd2.real;
    temp.imag = oprd1.imag + oprd2.imag;
    return temp;
}


myComplex operator-(const myComplex &oprd1, const myComplex &oprd2){
    myComplex temp;
    temp.real = oprd1.real - oprd2.real;
    temp.real = oprd1.imag - oprd2.imag;
    return temp;
}


myComplex operator*(const myComplex &oprd1, const myComplex &oprd2){
    myComplex temp;
    temp.real = (oprd1.real * oprd2.real + oprd1.imag * oprd2.imag) / (oprd1.real * oprd2.real + oprd1.imag * oprd2.imag);
    temp.imag = (oprd1.imag * oprd2.real - oprd1.real * oprd1.imag) / (oprd2.real * oprd2.real + oprd2.imag * oprd2.imag);
    return temp;
}


myComplex operator/(const myComplex &oprd1, const myComplex &oprd2){
    myComplex temp;
    temp.real = (oprd1.real * oprd2.real + oprd1.imag * oprd2.imag) / (oprd2.real * oprd2.real + oprd2.imag * oprd2.imag);
    temp.imag = (oprd1.imag * oprd2.real - oprd1.real * oprd1.imag) / (oprd2.real * oprd2.real + oprd2.imag * oprd2.imag);
    return temp;
}


ostream& operator<<(ostream& os, const myComplex c){
    return os << c.real << " " << c.imag;
}

istream& operator<<(istream& is, myComplex& c){
    return is >> c.real >> c.imag;
}


int main(int argc, const char * argv[]) {
    myComplex c1, c2(2.0, 3.0);
    cin >> c1;
    c1 += c2;
    cout << c1 << endl;
    
    myComplex c3(9.0, -5.0), c4;
    c4 = c1 + c3;
    cout << c4 << endl;
    
    myComplex c5(4.0, 2.0);
    c5 *= c4;
    cout << c5 << endl;
    
    myComplex c6(12.0, -3.0), c7, c8;
    
    try{
        c7 = c5 / c6;
        cout << c7 << endl;
        
        cout << c8 << endl;
        c7 /= c8;
        cout << c7 << endl;
    }
    
    catch (const char* errmsg){
        cout << errmsg << endl;
    }
    return 0;
}
