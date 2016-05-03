/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RetailItem.h
 * Author: chrystallahavadjia
 *
 * Created on April 28, 2016, 5:41 PM
 */

#ifndef RETAILITEM_H
#define RETAILITEM_H

#include<string>
using namespace std;


//user libraries
class RetailItem
{
    private:
        string dscrptn; // variable with a brief description of the item.
        int untsOnHand; // number of units currently in inventory.
        float price;      //holds the item’s retail price.
    public:
        RetailItem(string, int, float);
        void setDscrptn(string);
        void setUnstOnHand(int);
        void setPrice(float);
        string getDscrptn() const;
        int getUnstOnHand() const;
        float getPrice() const;
};

#endif /* RETAILITEM_H */

