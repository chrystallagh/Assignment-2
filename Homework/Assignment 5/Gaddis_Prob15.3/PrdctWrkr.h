/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PrdctWrkr.h
 * Author: chrystallahavadjia
 *
 * Created on May 23, 2016, 5:40 PM
 */

#ifndef PRDCTWRKR_H
#define PRDCTWRKR_H
#include "Employee.h"

class PrdctWrkr: public Employee { //PrdctWrkr is a Employee base class access specification
    //Employee is the base class and PrdctWrkr is the derived class
    private: 
        int shift; //employee's shift
        float payRate; // employee's hour pay rate
    public:
        PrdctWrkr();
        void setShift(int); //set object
        void setPayRate(float);// set object  
        int getShift() const;
        float getPayRate() const;
};

#endif /* PRDCTWRKR_H */

