/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 14.5
 * File:   main.cpp
 * Author: chrystallahavadjia
 *
 * Created on May 1, 2016, 2:11 PM
 */
//system libraries
 #include <iostream>
#include"NumDays.h"
#include"TimeOff.h"

 using namespace std;
 //user libraries

 //global constants
 //function prototypes

 //execution begins here
 int main() 
 {
     //create timeoff instance
     TimeOff tmOf;
     //declare variables
    string emplName;  // employs name;
    int idnNum;  //employs identification number 
    // declared instances
    NumDays maxSckDys; // instance containing total sick days allowed
    NumDays sckTaken; // num of days of sick leave taken
    NumDays maxVction; //max num of paid vacation days allowed
    NumDays vacTkn;  // num of of paid vacation days taken
    NumDays maxUpd; // max number of unpaid vacation days allowed
    NumDays unpdTken; // num of unpaid vacation days taken
    
    
    cout << "This program demonstrates Aggregation, class containing another"
            "class instant.\n";
    cout << "------------------------------------\n";
    //user input
    cout <<"Enter the following information\n";
    cout << "Employ Name: ";
    getline(cin,emplName);
    tmOf.setEmplName(emplName);
    cout << "Id Number:   ";
    cin >> idnNum;
    tmOf.setIdnNum(idnNum);
    
    //obtain hours for each instance.
    cout << "Number of sick leave days allowed: ";
    maxSckDys.usrInp();    
    cout << "Number of sick leaves taken by employee: ";
    sckTaken.usrInp();
    do{
        cout << "Number of paid vacation days allowed: ";
        cout << "\nMust be below 240: ";
        maxVction.usrInp();
    }while(maxVction.getHours() > 240);
    cout << "Number of paid vacations taken: ";
    vacTkn.usrInp();
    cout << "Number of unpaid vacations allowed: ";
    maxUpd.usrInp();
    cout << "Number of unpaid vacations taken: ";
    unpdTken.usrInp();
    cout << endl;
    
    //display information 
    cout << "________________________________\n";
    cout << "Employee information: \n";
    cout << "Name: " << emplName << endl;
    cout << "Id #: " << idnNum << endl;
    cout << "Sick leave days allowed: \n";
    maxSckDys.prnt();
    cout << "Sick leave days taken: \n";
    sckTaken.prnt();
    cout << "Paid vacations allowed: \n";
    maxVction.prnt();
    cout << "Paid vacations taken: \n";
    vacTkn.prnt();
    cout << "Unpaid vacations allowed: \n";
    maxUpd.prnt();
    cout << "Unpaid vacations taken: \n";
    unpdTken.prnt();
    
    
    cout << endl; 
    
    return 0; 
 }
 
