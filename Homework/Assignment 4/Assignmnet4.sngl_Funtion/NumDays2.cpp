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
#include "NumDays2.h"

using namespace std;

//constructor
NumDays2::NumDays2() {
    hours = 0; 
}
//mutator functions
void NumDays2::setHours(float h){
    hours = h;
}
//accessor functions
float NumDays2::getHours() const{
    return hours;
}
float NumDays2::getDays() const{
    return hours/8;
}
void NumDays2::prnt() const{
    cout << "Hours: " << hours << endl;
    cout << "Days:  " << getDays() << endl;
}
void NumDays2::usrInp(){
  
    //obtain user input
    cout <<"\nEnter a positive number:\n";
    do{
        cout <<"Hours:       ";
        cin >> hours;
    }while(hours<0);
}
