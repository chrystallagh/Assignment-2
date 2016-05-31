/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Time.h
 * Author: chrystallahavadjia
 *
 * Created on May 24, 2016, 3:02 PM
 */

#ifndef TIME_H
 #define TIME_H


class Time {
    protected:
        int hour;
        int min;
        int sec; 
    public:
        // Default constructor 
         Time()
           { hour = 0; min = 0; sec = 0; }
        // Constructor
        Time(int h, int m, int s)
          { hour = h; min = m; sec = s; }
        // Accessor functions 
        int getHour() const
            { return hour; }
        int getMin() const 
            { return min; }
        int getSec() const 
            { return sec; }        
}; 

#endif 