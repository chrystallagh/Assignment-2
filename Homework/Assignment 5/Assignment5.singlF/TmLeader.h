/*
 * 15.3
 */

/* 
 * File:   TmLeader.h
 * Author: chrystallahavadjia
 *
 * Created on May 23, 2016, 10:59 PM
 */

#ifndef TMLEADER_H
#define TMLEADER_H

#include "PrdctWrkr.h"

class TmLeader: public PrdctWrkr {
    private:
        int mnthBonus; //fixed monthly bonus pay
        int reqHours; //required umber of trained hours he/she must attend
        int attHours; // trained hours attended;
    public:
        TmLeader();
        void setMnthBonus(int);
        void setReqHours(int);
        void setAttHours(int);
        int getMnthBonus() const;
        int getReqHours() const;
        int getAttHours() const;
};

#endif /* TMLEADER_H */

