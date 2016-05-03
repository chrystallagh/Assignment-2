/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RetailItem.cpp
 * Author: chrystallahavadjia
 * 
 * Created on April 28, 2016, 5:41 PM
 */

#include "RetailItem.h"

//function prototypes 
// assigns a value to variable
void RetailItem::setDscrptn(string dsct){
     dscrptn = dsct;
}
// assigns a value to variable
void RetailItem::setUnstOnHand(int u){
    untsOnHand = u;
}
// assigns a value to variable
void RetailItem::setPrice(float p){
    price = p; 
}

//**********************************
// returns the value in a member
string RetailItem::getDscrptn() const{
    return dscrptn;
}
// returns the value in a member
int RetailItem::getUnstOnHand() const{
    return untsOnHand;
}
// returns the value in a member
float RetailItem::getPrice() const{
    return price;
}

//constructor accepting three objects
RetailItem::RetailItem(string d, int u, float p){
    dscrptn = d;
    untsOnHand = u;
    price = p;
}

