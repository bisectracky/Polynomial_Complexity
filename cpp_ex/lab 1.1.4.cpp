//
//  main.cpp
//  lab1.4
//
//  Created by Johoric on 14/12/2017.
//  Copyright © 2017 Zihao Ding. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Box{
private:
    int length; int width; int height;
    
public:
    Box(int l, int w, int h): length(l), width(w), height(h){
        cout << "Construct a box" << endl;
    }
   
    ~Box(){
        cout << "Destruct a box" << endl;
    }
    
    int get_volume() const {
        int vol_temp = length * width * height;
        return vol_temp;
    }
    
    int get_surface_area() const{
        int sur_temp = 2 * ( length * width + width * height + height * length );
        return sur_temp;
    }

};

int main(int argc, const char * argv[]) {
    int volume, surface;
    Box b(10,20,30);
    volume = b.get_volume();
    surface = b.get_surface_area();
    cout << "The volume of this box is " << volume << ", the surface of this box is " << surface << endl;
    return 0;
}
