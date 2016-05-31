/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ShiftSup.cpp
 * Author: chrystallahavadjia
 * 
 * Created on May 23, 2016, 7:07 PM
 */

#include "ShiftSup.h"

ShftSprvzr::ShftSprvzr() {
    salary=0;
    prdBns=0;
}
//mutator functions
void ShftSprvzr::setSalary(int s){
    if(s>0)
        salary = s;
    else 
        throw InvdVlu();
}
void ShftSprvzr::setPrdBns(int p) {
    prdBns = p;
}
//accessor functions
int ShftSprvzr::getSalary() const{
    return salary;
}
int ShftSprvzr::getPrdBns() const{
    return prdBns;
}