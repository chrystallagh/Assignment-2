/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Date.h
 * Author: chrystallahavadjia
 *
 * Created on April 25, 2016, 2:44 PM
 */

#ifndef DATE_H
#define DATE_H

//user libraries
class Date
{
    private:
        int day;
        int month;
        int year;
    public:
        void setDay(int);
        void setMonth(int);
        void setYear(int);
        void dsplDate();
        int getDay() const;
        int getMonth() const;
        int getYear() const;
};

#endif /* DATE_H */

