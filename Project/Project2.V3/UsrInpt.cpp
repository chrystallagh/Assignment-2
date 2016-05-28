/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UsrInpt.cpp
 * Author: chrystallahavadjia
 * 
 * Created on May 18, 2016, 7:06 PM
 */

#include<iostream>
using namespace std;
#include "UsrInpt.h"

//definition of static variable
string UsrInpt::order[4]={"First","Second","Third","Fourth"};

//default constructor
UsrInpt::UsrInpt() {
    mxPlys=0;
    hint=0;
}
//mutator functions
void UsrInpt::setMxPlys(int m){//assigns value to variable
    mxPlys = m;
}
void UsrInpt::setHint(int h){//assigns value to variable 
    hint = h;
}
//acessor functions
int UsrInpt::getMxPlys() const{
    return mxPlys; //returns value in member
}
int UsrInpt::getHint() const{
    return hint;
}
//print funtion
void UsrInpt::prntOrder(int j){
    for(int i=0;i<4;i++){
        if(i==j)
            cout << order[i];
    }    
}
//overload postfix and prefix operators
UsrInpt UsrInpt::operator++(){
    ++mxPlys;
    getMxPlys();
    return *this;
}
