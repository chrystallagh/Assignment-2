/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Invtry.h
 * Author: chrystallahavadjia
 *
 * Created on April 25, 2016, 3:22 PM
 */

#ifndef INVTRY_H
#define INVTRY_H

//user libraries 
class Invtry
{
    private:
        int itmNum; // holds the item's item number
        int qnty; // holds quantity of item 
        float cost;  //per-unit cost

    public:
        Invtry();   // default constructor
        Invtry(int, int , float); // second constructor 
        void setItmNum(int);
        void setQnty(int);
        void setCost(float);
        int getItmNum() const;
        int getQnty() const;
        float getCost() const;
        float getTotCost() const;
};

#endif /* INVTRY_H */

