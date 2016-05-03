/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Invtry.cpp
 * Author: chrystallahavadjia
 * 
 * Created on April 25, 2016, 3:22 PM
 */

#include "Invtry.h"

//function prototypes 
//default constructor
Invtry::Invtry(){
    itmNum =0; // holds the item's item number
    qnty = 0;   // holds quantity of item 
    cost= 0.0; // cost of each item
}
// Construct #2
Invtry::Invtry(int iN, int q, float cst){
    itmNum = iN; 
    qnty = getQnty();  
    cost= getCost(); 
}
// mutator functions
//assigns a value to variable,
void Invtry::setItmNum(int i){
    itmNum = i;
}
//assigns a value to variable
void Invtry::setQnty(int q){
    qnty = q;
}
//assigns a value to variable
void Invtry::setCost(float c){
    
    cost = c; 
}

//**********************************
//accessor functions 
//return value in a member
int Invtry::getItmNum() const{
    return itmNum;
}
//return value in a member 
float Invtry::getCost() const{
    return cost;
}
//return value in a member 
int Invtry::getQnty() const{
    return qnty;
}
//return value in a member 
float Invtry::getTotCost() const{
    return cost * qnty ;
}

