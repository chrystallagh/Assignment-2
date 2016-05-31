/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Absolut.h
 * Author: chrystallahavadjia
 *
 * Created on May 27, 2016, 6:41 PM
 */

#ifndef ABSOLUT_H
#define ABSOLUT_H

template <class T> //declare template 

class Absolut {
    private:
        T abst;
    public:
        Absolut(T a){
            abst = a;
        }
        T getA() const{
            return abst;
        }
        T FndAbs(){
            if(abst < 0)
                return -1*abst;
            else 
                return abst;
        }        
};

#endif /* ABSOLUT_H */

