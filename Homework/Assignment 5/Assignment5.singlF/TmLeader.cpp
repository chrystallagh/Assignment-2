/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TmLeader.cpp
 * Author: chrystallahavadjia
 * 
 * Created on May 23, 2016, 10:59 PM
 */

#include "TmLeader.h"

TmLeader::TmLeader() {
     mnthBonus =0; //fixed monthly bonus pay
     reqHours =0; //required umber of trained hours he/she must attend
     attHours =0;
}
//mutator functions
void TmLeader::setMnthBonus(int m){
    mnthBonus = m;
}
void  TmLeader::setReqHours(int r){
    reqHours=r;
}
void TmLeader::setAttHours(int a){
    attHours = a;
}
//accessor functions
int TmLeader::getMnthBonus() const{
    return mnthBonus;
}
int TmLeader::getReqHours() const{
    return reqHours;
}
int TmLeader::getAttHours() const{
    return attHours;
}