

/* 
 * File:   MltTime.h
 * Author: chrystallahavadjia
 *
 * Created on May 24, 2016, 3:22 PM
 */

#ifndef MLTTIME_H
#define MLTTIME_H

#include"Time.h"

template <class T> //define template

class MltTime: public Time { //MltTime is a Time
   private:
       int milHour; 
       T  milSec1;
       T milSec2;
    public:
        MltTime()
        { milHour=0;}
        void setTime(int h,T s, T s2){
            if(h>1259)
                {hour=(h-1200)/100;} 
            else
                hour=h/100;
            min=h-(h/100)*100;
            sec=s;
            milHour=h;
            milSec1=s;
            milSec2 =s2;
        }
        int getHour() const{
            return milHour;
        }
        int getStndHr() const{
            return hour*100+min;
        }
        T bigger(){
            if(milSec1>milSec2)
                return milSec1;
            else 
                return milSec2;
        }
};

#endif /* MLTTIME_H */

