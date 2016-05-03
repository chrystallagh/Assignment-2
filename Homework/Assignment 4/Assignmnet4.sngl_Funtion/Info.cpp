/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Info.cpp
 * Author: chrystallahavadjia
 * 
 * Created on April 25, 2016, 2:53 PM
 */

#include "Info.h"
using namespace std;

//function prototypes 

//assigns a value to variable, mutator functions
void Info::setName(string n){
    name = n;
}
//assigns a value to variable
void Info::setAddress(string ad){
    address = ad;
}
//assigns a value to variable
void Info::setAge(int ag){
    age = ag; 
}
//assigns a value to variable
void Info::setPhnNum(int p){
    phnNum = p; 
}
//**********************************
//return value in a member, accessor functions
string Info::getName() const{
    return name;
}
//return value in a member 
string Info::getAddress() const{
    return address;
}
//return value in a member 
int Info::getAge() const{
    return age;
}
//return value in a member 
int Info::getPhnNum() const{
    return phnNum; 
}