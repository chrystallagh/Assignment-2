/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Month.cpp
 * Author: chrystallahavadjia
 * 
 * Created on May 1, 2016, 11:21 PM
 */

#include "Month.h"

#include<string>
#include <iostream>

//definition of static member variables 

//constroctor
Month::Month(std::string m){
    this->month=m;
     months[0]= "January";
     months[1]="February";
     months[2]= "March";
     months[3]= "April";
     months[4]= "May";
     months[5]= "June";
     months[6]= "July";
     months[7]= "August";
     months[8]= "September";
     months[9]= "October";
     months[10]= "November";
     months[11]= "December";
    for(int i =0; i < 14; i++){
        if(months[i]== m)
            mnthNum =i+1;
    }
     this->setNum(mnthNum);
}

 Month::Month(int n){
     this->mnthNum=n;
   
     months[0]= "January";
     months[1]="February";
     months[2]= "March";
     months[3]= "April";
     months[4]= "May";
     months[5]= "June";
     months[6]= "July";
     months[7]= "August";
     months[8]= "September";
     months[9]= "October";
     months[10]= "November";
     months[11]= "December";
     months[12]= "January";
     months[13]="February";

    for (int i = 0; i<14; i++){
        if(n==i+1)
            month = months[i];      
    }
     this->setName(month);
}
//overload postfix and prefix operators
Month Month::operator++(){
    ++mnthNum;
//    if(mnthNum == 12) mnthNum=0;
    getName();
    return *this;
}
Month Month::operator ++(int){
    Month temp;
    mnthNum++;
    temp.setNum(mnthNum);
    return temp;          
}
//overload postfix and prefix operators
Month Month::operator--(){
    ++mnthNum;
    getName();
    return *this;
}
Month Month::operator--(int){
    Month temp;
    temp.setNum(mnthNum);
    mnthNum--;
    temp.getName();
    return temp;       
}