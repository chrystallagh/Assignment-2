/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Number.h
 * Author: chrystallahavadjia
 *
 * Created on April 29, 2016, 3:29 PM
 */

#include<iostream>
#ifndef NUMBER_H
#define NUMBER_H

class Number {
    private:
        int num;
        static string lessThan10[10];
    public: 
        Number();
        void Print(int);   
};

#endif /* NUMBER_H */

