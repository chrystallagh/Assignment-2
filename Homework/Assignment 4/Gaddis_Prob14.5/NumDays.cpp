/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumDays.cpp
 * Author: chrystallahavadjia
 * 
 * Created on May 1, 2016, 3:34 PM
 */

#include<iostream>
#include "NumDays.h"

using namespace std;

//constructor
NumDays::NumDays() {
    hours = 0; 
}
//mutator functions
void NumDays::setHours(float h){
    hours = h;
}
//accessor functions
float NumDays::getHours() const{
    return hours;
}
float NumDays::getDays() const{
    return hours/8;
}
void NumDays::prnt() const{
    cout << "Hours: " << hours << endl;
    cout << "Days:  " << getDays() << endl;
}
void NumDays::usrInp(){
  
    //obtain user input
    cout <<"\nEnter a positive number:\n";
    do{
        cout <<"Hours:       ";
        cin >> hours;
    }while(hours<0);
}
