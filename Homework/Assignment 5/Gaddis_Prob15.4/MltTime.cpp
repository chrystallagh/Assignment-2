/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MltTime.cpp
 * Author: chrystallahavadjia
 * 
 * Created on May 24, 2016, 3:28 PM
 */

#include <iostream>

using namespace std;

#include "MltTime.h"

MltTime::MltTime(){//default constructor
    milHour=0;
    milSec=0;
}
//mutator functions
void MltTime::setTime(int h, int s){
     if(h>1259)
        {hour=(h-1200)/100;} 
     else
         hour=h/100;
     min=h-(h/100)*100;
     sec=s;
     milHour=h;
     milSec=s;
}
int MltTime::getHour() const{
    return milHour;
}
int MltTime::getStndHr() const{
    return hour*100+min;
}
