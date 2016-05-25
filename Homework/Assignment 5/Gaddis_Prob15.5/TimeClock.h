 /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TimeClock.h
 * Author: chrystallahavadjia
 *
 * Created on May 24, 2016, 5:55 PM
 */

#ifndef TIMECLOCK_H
#define TIMECLOCK_H

#include <iostream>

using namespace std;

#include "MltTime.h"

class TimeClock: public MltTime {
    private:
        int strTime; //starting time
        int endTime; //end time
    public:
        TimeClock()
            {strTime=0; endTime=0;}
        void setTimeC1()
            {     
                do{
                    cout << "Enter the starting time in military form:(Must be between 2359 and 0000).\n ";
                    cin >> strTime;
                 }while(strTime>2359||strTime<0000);
            }
        void setTimeC2(){
            do{
                cout << "Enter the ending time in military form:(Must be between 2359 and 0000).\n ";
                cin >> endTime;
            }while(endTime>2359||endTime<0000);
            //endTime=s;
        }
        int getElapse(){
                {return (endTime-strTime)/100;}
        }      
            
};

#endif /* TIMECLOCK_H */

