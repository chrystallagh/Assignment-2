/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DysOfYr.cpp
 * Author: chrystallahavadjia
 * 
 * Created on April 30, 2016, 2:44 PM
 */


#include "DysOfYr.h"

DysOfYr::DysOfYr() {
    days =0;
}
//definition of static member variables 
string DysOfYr::month[12] = {"January", "February", "March", "April", "May",
                    "June", "July", "August", "September", "October", "November",
            "December"};
void DysOfYr::Print(int n){
    days = n;
    int mnth = 0;
    int day = 0;
    
    int year[12]={31,28,31,30,31,30,31,31,30,31,30,31};

    if(days > 0 && days < 32)
        cout << month[0] << " " << days;    
    if(days >= 32 && days < 60)
        cout << month[1] << " " << days-31;
    if(days >= 60 && days < 91)
        cout << month[2] << " " << days-59;
    if(days >= 91 && days < 121)
        cout << month[3] << " " << days-90;
    if(days >= 121 && days < 152)
        cout << month[4] << " " << days-120;
    if(days >= 152 && days < 182)
        cout << month[5] << " " << days-151;
    if(days >= 182 && days < 213)
        cout << month[6] << " " << days-181;
    if(days >= 213 && days < 244)
        cout << month[7] << " " << days-212;
    if(days >= 244 && days < 274)
        cout << month[8] << " " << days-243;
    if(days >= 274 && days < 305)
        cout << month[9] << " " << days-273;
    if(days >= 305 && days < 335)
        cout << month[10] << " " << days-304;
    if(days >= 335 && days < 366)
        cout << month[11] << " " << days-334;
}
