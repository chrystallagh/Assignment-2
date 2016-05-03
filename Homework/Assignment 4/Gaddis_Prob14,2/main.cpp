/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 14.2
 * File:   main.cpp
 * Author: chrystallahavadjia
 *
 * Created on April 30, 2016, 2:39 PM
 */

//system libraries
#include <iostream>

using namespace std;

//user libraries
#include "DysOfYr.h"
//global constants
//function prototypes

int main(int argc, char** argv) {
    
    DysOfYr doy; //declare instance 
    int num=0;
    
    cout << "This program takes a number between 1 and 365 and tells the user"
            "what day of which month it is:\n";
    cout <<"This program assumes it is not a leap year\n";
    cout << "------------------------------------------\n";
    
    //user input
    do{        
        cout << "Enter a number between 1 and 365:\n";
        cin >> num;
    }while(num < 0 || num > 366);
    doy.Print(num); //print information stored
    return 0;
}

