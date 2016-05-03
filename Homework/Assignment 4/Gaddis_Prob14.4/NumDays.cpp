/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumDays.cpp
 * Author: chrystallahavadjia
 * 
 * Created on April 30, 2016, 8:28 PM
 */

#include "NumDays.h"

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
//overload functions
NumDays NumDays::operator +(const NumDays&right)
{
    NumDays temp;
    
    temp.hours = hours +right.hours ;
    return temp;
}
NumDays NumDays::operator -(const NumDays&right)
{
    NumDays temp;
    
    temp.hours = hours - right.hours ;
    return temp;
}
//overload postfix and prefix operators
NumDays NumDays::operator++(){
    ++hours;
    getDays();
    return *this;
}
NumDays NumDays::operator ++(int){
    NumDays temp;
    temp.setHours(hours);
    hours++;
    temp.getDays();
    return temp;          
}
//overload postfix and prefix operators
NumDays NumDays::operator--(){
    --hours;
    getDays();
    return *this;
}
NumDays NumDays::operator--(int){
    NumDays temp;
    temp.setHours(hours);
    hours--;
    temp.getDays();
    return temp;          
}
