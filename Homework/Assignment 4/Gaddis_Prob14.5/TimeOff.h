/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TimeOff.h
 * Author: chrystallahavadjia
 *
 * Created on May 1, 2016, 3:36 PM
 */

#ifndef TIMEOFF_H
#define TIMEOFF_H

#include<string>
#include"NumDays.h"
using namespace std;

class TimeOff { 
    private:
        string emplName;  // employs name;
        int idnNum;  //employs identification number 
        int hrs;
        NumDays maxSckDys; // max number of days of sick leave allowed
        NumDays sckTaken; // num of days of sick leave taken
        NumDays maxVction; //max num of paid vacation days allowed
        NumDays vacTkn;  // num of of paid vacation days taken
        NumDays maxUpd; // max number of unpaid vacation days allowed
        NumDays unpdTken; // num of unpaid vacation days taken
    public:
        TimeOff();
        void setEmplName(string);
        void setIdnNum(int);
        void setMxScD(NumDays);
        string getEmlName() const;
        int getIdnNum() const; 
        NumDays getMxScD () const;
};

#endif /* TIMEOFF_H */

