/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DysOfYr.h
 * Author: chrystallahavadjia
 *
 * Created on April 30, 2016, 2:44 PM
 */


#ifndef DYSOFYR_H
#define DYSOFYR_H

#include<string>
#include<iostream>
using namespace std;

class DysOfYr {
    private:
        int days;
        static string month[12];
    public:
        DysOfYr();
        void Print(int);
};

#endif /* DYSOFYR_H */

