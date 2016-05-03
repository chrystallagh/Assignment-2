/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TimeOff.cpp
 * Author: chrystallahavadjia
 * 
 * Created on May 1, 2016, 3:36 PM
 */

#include<iostream>
#include "TimeOff.h"

using namespace std;

//constructor 
TimeOff::TimeOff() {
    emplName = "";
    idnNum = 0;
    maxSckDys.setHours(hrs);
    sckTaken.setHours(hrs); 
    maxVction.setHours(hrs); 
    vacTkn.setHours(hrs);  
    maxUpd.setHours(hrs); 
    unpdTken.setHours(hrs); 
}
//mutator functions
void TimeOff::setEmplName(string n){
    emplName = n;   
}
void TimeOff::setIdnNum(int i){
    idnNum = i;
}
//accessore functions
string TimeOff::getEmlName() const{
    return emplName;
}
int TimeOff::getIdnNum() const{
    return idnNum;
}
