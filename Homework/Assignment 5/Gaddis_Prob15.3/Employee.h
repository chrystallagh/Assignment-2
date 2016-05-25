/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Employee.h
 * Author: chrystallahavadjia
 *
 * Created on May 23, 2016, 5:39 PM
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H


#include<string>

using namespace std;

class Employee {
    private: 
        string name; //employee name
        int number; //employees number
        int hrDate; //hire date
    public:
        Employee(); //default constructor
        void setName(string); //set object
        void setNum(int); //set object
        void setHrDate(int);//set object 
        string getName() const;
        int getNum() const;
        int getHrDate() const;
};

#endif /* EMPLOYEE_H */

