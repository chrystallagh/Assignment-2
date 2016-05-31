/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Employee.cpp
 * Author: chrystallahavadjia
 * 
 * Created on May 23, 2016, 5:39 PM
 */

#include "Employee.h"
#include<string>
using namespace std;

Employee::Employee() {//default constructor 
    name = " ";
    number = 0;
    hrDate= 0;
}
//mutator funtions
void Employee::setName(string n){
     name = n;
}
void Employee::setNum(int m){
    number = m;
}
void Employee::setHrDate(int h){
    hrDate=h;
}
//accessor funtions
string Employee::getName() const{
    return name;
}
int Employee::getNum() const{
    return number;
}
int Employee::getHrDate() const{
    return hrDate;
}

