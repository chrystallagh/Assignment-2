/*
 */

/* 13.5
 * File:   main.cpp
 * Author: chrystallahavadjia
 *
 * Created on April 23, 2016, 9:20 PM
 */

//system libraries
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

//user libraries
#include"RetailItem.h"


// global constants

//function prototypes 
// execution begins here
int main(int argc, char** argv) {
    
    RetailItem item[3] = { 
                RetailItem("Jacket ", 12, 59.95), 
                RetailItem("Designer Jeans ", 40, 34.95),
                RetailItem("Shirt ", 20, 24.95)}; //initialize instances 
    
    cout << "\tDescription \t Units on Hand \t  Price\n";
    for(int i =0; i < 3; i++){
        //display stored information 
        cout << "Item " <<i+1<<": \n";
        cout << setw(20) << right << item[i].getDscrptn() << " \t\t ";
        cout  << item[i].getUnstOnHand() << "       "; 
        cout  << item[i].getPrice() << endl;
    }

    return 0;
}

