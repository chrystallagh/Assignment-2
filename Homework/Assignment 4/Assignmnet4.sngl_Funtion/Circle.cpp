/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Circle.cpp
 * Author: chrystallahavadjia
 * 
 * Created on April 28, 2016, 9:17 PM
 */

#include "Circle.h"

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