/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumDays.h
 * Author: chrystallahavadjia
 *
 * Created on April 30, 2016, 8:28 PM
 */

#ifndef NUMDAYS_H
#define NUMDAYS_H

class NumDays {
    private:
        float hours; //hours worked 
    public:
        NumDays();  //constructor
        void setHours(float); //set hours
        float getHours() const; 
        float getDays() const;  
        //overloaded operator functions
        NumDays operator + (const NumDays &); //overload +
        NumDays operator - (const NumDays &); //overload -
        NumDays operator ++ (int); //overload prefix ++
        NumDays operator ++ (); //overload postfix ++      
        NumDays operator -- (int); //overload prefix --
        NumDays operator -- (); //overload postfix --        
};

#endif /* NUMDAYS_H */

