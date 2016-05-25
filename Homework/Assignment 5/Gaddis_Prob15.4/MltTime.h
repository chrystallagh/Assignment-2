

/* 
 * File:   MltTime.h
 * Author: chrystallahavadjia
 *
 * Created on May 24, 2016, 3:22 PM
 */

#ifndef MLTTIME_H
#define MLTTIME_H

#include"Time.h"

class MltTime: public Time { //MltTime is a Time
   private:
       int milHour;
       int  milSec;
    public:
        MltTime();
        void setTime(int,int);
        int getHour() const;
        int getStndHr() const;
};

#endif /* MLTTIME_H */

