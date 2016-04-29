/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chrystallahavadjia
 *
 * Created on April 28, 2016, 6:12 PM
 */

//system libraries
#include <iostream> 

using namespace std;

//user libraries
//#include "Circle.h"

//global constants
//function prototype 
//execution begins here
class Circle
{
    private:
        float radius;
        float pi;
    public:
        Circle(); // default constructor 
        Circle(float); // 2nd constuctor
        void setRadius(float);
        float getRadius() const;
        float getArea() const;
        float getDmeter() const;
        float getCrcmfrence() const;
};
//default constructor
Circle::Circle(){
    radius = 0.0; // initialize variable 
    pi= 3.14159;
}
// Construct #2
Circle::Circle(float r){
    radius = r; // initialize variable 
}

void Circle::setRadius(float k){
    radius = k;
}
//**********************************
//accessor functions 
//return value in a member
float Circle::getRadius() const{
    return radius;
}
//return value in a member 
float Circle::getArea() const{
    return radius * pi * radius;
}
//return value in a member 
float Circle::getDmeter() const{
    return radius * 2;
}
//return value in a member 
float Circle::getCrcmfrence() const{
    return 2* pi*radius ;
}

int main(int argc, char** argv) {
    
    Circle crcle; //define class
    //declare variable
    float radius =0.0;  // radius of circle 
    
    cout << "This program asks the user for a radius and calculates its "
            "diameter, circumference and its area\n";
    cout << "________________________________________________________\n";
    cout << "Enter the following information: \n";
    do{
      cout << "Enter a positive number:\n";      
      cout << "Radius of circle:        ";
      cin >> radius; //obtain user input
    }while(radius < 0);
    crcle.setRadius(radius); //store in object 
    
    
    cout << "********************************************\n";    
    cout <<"Output:\n"; // display results
    cout << "Radius:        ";
    cout << crcle.getRadius();
    cout << endl;
    cout << "Diameter:      ";
    cout << crcle.getDmeter();
    cout << endl;  
    cout << "Area:          ";
    cout << crcle.getArea(); 
    cout << endl;
    cout << "Circumference: "; 
    cout << crcle.getCrcmfrence(); // display in object
    cout << endl;    
    
    cout << "********************************************\n"; 
    
    return 0;
}
