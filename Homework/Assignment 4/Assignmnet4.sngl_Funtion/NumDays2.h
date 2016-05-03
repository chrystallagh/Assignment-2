/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumDays.h
 * Author: chrystallahavadjia
 *
 * Created on May 1, 2016, 3:34 PM
 */

#ifndef NUMDAYS2_H
#define NUMDAYS2_H

class NumDays2 {
    private:
        float hours; //hours worked 
    public:
        NumDays2();  //constructor
        void usrInp();
        void setHours(float); //set hours
        float getHours() const; 
        float getDays() const;  
        void prnt() const;
};

#endif /* NUMDAYS_H */


