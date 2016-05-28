/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UsrInpt.h
 * Author: chrystallahavadjia
 *
 * Created on May 18, 2016, 7:06 PM
 */

#ifndef USRINPT_H
#define USRINPT_H

#include<iostream>
#include<string>

using namespace std;

class UsrInpt{
    private:
        int mxPlys; //user inputs of number of plays
        int hint; //user input of which hint to output
        static string order[4]; //display the order of colors, ex. "first color"
    public:
        UsrInpt(); //Constructor
        void setMxPlys(int);// set user input in object
        void setHint(int); //set user input in object
        void prntOrder(int); //print user color order
        int getMxPlys() const; //get object
        int getHint() const; //get object
        UsrInpt operator ++ (); //overload postfix ++ 
       // UsrInpt operator ++ (int); //overload prefix ++
};

#endif /* USRINPT_H */

