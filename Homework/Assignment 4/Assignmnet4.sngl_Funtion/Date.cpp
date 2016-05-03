/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Date.cpp
 * Author: chrystallahavadjia
 * 
 * Created on April 25, 2016, 2:44 PM
 */

#include "Date.h"
#include <iostream>
using namespace std;
//function prototypes 

//setDate assigns a value to day
void Date::setMonth(int m){
    month = m;
}
//setMonth assigns a value to month
void Date::setDay(int d){
    day = d;
}
//setYear assigns a value to year
void Date::setYear(int y){
    year = y; 
}
//**********************************
//getDay returns the value in the day member
int Date::getDay() const{
    return day;
}
//getMonth returns the value in the month member
int Date::getMonth() const{
    return month;
}
//getYear returns the value in the Year member
int Date::getYear() const{
    return year;
}
void Date::dsplDate(){
    
    string sMonth[] = {"January","February","March","April","May","June","July",
                        "August","September","October","November","December"};
    
    cout << "\n_______________________________\n";
    cout <<  "Here is the date in three different forms:\n";
    for(int i = 0; i<12;i++){
        if (i == month-1){
            cout << "\t" <<month<<"/"<<day<<"/"<<year;
            cout << endl;
            cout << "\t" << sMonth[i] << "  " << day<< ",  " << year;
            cout << endl;
            cout << "\t" << day << "  " << sMonth[i] << " " << year;
            cout << endl;
        }
    } 
}