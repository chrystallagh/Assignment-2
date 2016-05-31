/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ShiftSup.h
 * Author: chrystallahavadjia
 *
 * Created on May 23, 2016, 7:07 PM
 */

#ifndef SHIFTSUP_H
#define SHIFTSUP_H

#include"Employee.h"

class ShftSprvzr :public Employee { //ShftSprvzr is a Employee
    //Employee is the base class and ShftSprvzr is the derived class
    private:
        int salary; //annual salary of supervisor 
        int prdBns; //annual production bonus of supervisor
    public:
        //exception class 
        class InvdVlu
            {}; // empty class declaration
        ShftSprvzr(); //default constructor 
        void setSalary(int); //set object
        void setPrdBns(int); //set object 
        int getSalary() const;
        int getPrdBns() const;
};

#endif /* SHIFTSUP_H */

