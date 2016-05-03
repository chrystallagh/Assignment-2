/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 14.4
 * File:   main.cpp
 * Author: chrystallahavadjia
 * Created on April 30, 2016, 8:27 PM
 */

//system libraries
#include <iostream>

using namespace std;

//user libraries
#include"NumDays.h"

//global constants
//function prototypes
int main(int argc, char** argv) {
    
    NumDays frst, scnd, cmbned, pstfx; //declare instances
    float hours;
    
    cout <<"This function takes the number of hours and converts them to days"
            "where 8 hours is 1 day\n";
    cout << "_____________________________________________\n";
    cout <<"Enter the following information\n";
    //obtain user input
    cout <<"Number of hours: 1:\n";
    do{
        cout <<"Enter a positive number\n";
        cin >> hours;
    }while(hours<0);
    frst.setHours(hours); //store in object
    //obtain user input
    cout <<"Number of hours: 2:\n";
    do{
        cout <<"Enter a positive number\n";
        cin >> hours;
    }while(hours<0);
    scnd.setHours(hours); //store in object
    
    cout << "Number of days: 1: ";
    cout << frst.getDays();
    cout << endl;
    cout << "Number of days: 2: ";
    cout << scnd.getDays();
    cout << endl;
    
    //assign first+second to combined
    cmbned = frst + scnd;
    //display
    cout << "Hours: 1+2: ";
    cout << cmbned.getHours();
    cout << endl;
    
    //assign first-second to combined
    cmbned = frst - scnd;
    //display
    cout << "Hours: 1-2: ";
    cout << cmbned.getHours();
    cout << endl;
    
    // prefix ++ operator
    cmbned = ++frst;
    pstfx = ++scnd;
    cout <<"\nPrefix operator ++ demonstration\n";
    cout << "Hours: 1: ";
    cout << frst.getHours() << endl;
    cout << "Days:  1: ";
    cout << frst.getDays() << endl;
    cout << "Hours: 2: ";
    cout << scnd.getHours() << endl;
    cout << "Days: 1:  ";
    cout << scnd.getDays() << endl << endl; 

   
    //postfix ++ operator
    cmbned = frst++;
    pstfx = scnd++;
    
    cout <<"Postfix operator ++ demonstration\n";
    cout << "Hours: 1: ";
    cout << frst.getHours() << endl;
    cout << "Days:  1: ";
    cout << frst.getDays() << endl;
    cout << "Hours: 2: ";
    cout << scnd.getHours() << endl;
    cout << "Days:  1: ";
    cout << scnd.getDays() << endl;    
    
    // prefix -- operator
    cmbned = --frst;
    pstfx = --scnd;
    
    cout <<"\nPrefix operator -- demonstration\n";
    cout << "Hours: 1: ";
    cout << frst.getHours() << endl;
    cout << "Days:  1: ";
    cout << frst.getDays() << endl;
    cout << "Hours: 2: ";
    cout << scnd.getHours() << endl;
    cout << "Days:  1: ";
    cout << scnd.getDays() << endl<< endl;  

    //postfix ++ operator
    cmbned = frst--;
    pstfx = scnd--;
    cout <<"Postfix operator -- demonstration\n";
    cout << "Hours: 1:  ";
    cout << frst.getHours() << endl;
    cout << "Days:  1:  ";
    cout << frst.getDays() << endl;
    cout << "Hours: 2:  ";
    cout << scnd.getHours() << endl;
    cout << "Days:  1:  ";
    cout << scnd.getDays() << endl;  

    return 0;
}

