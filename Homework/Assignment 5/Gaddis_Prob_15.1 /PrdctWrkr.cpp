/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PrdctWrkr.cpp
 * Author: chrystallahavadjia
 * 
 * Created on May 23, 2016, 5:40 PM
 */

#include "PrdctWrkr.h"

PrdctWrkr::PrdctWrkr() {
    shift = 0;
    payRate = 0.0;
}
//mutator functions
void PrdctWrkr::setShift(int s){
    shift = s;
}
void PrdctWrkr::setPayRate(float p){
    payRate= p;
}
//accessor functions
int PrdctWrkr::getShift() const{
    return shift;
}
float PrdctWrkr::getPayRate() const{
    return payRate;
}