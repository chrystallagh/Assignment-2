/*
 * 15.3
 * is this how polymorphism is done?
 */

/* 
 * File:   main.cpp
 * Author: chrystallahavadjia
 *
 * Created on May 23, 2016, 10:58 PM
 */

//system libraries 
#include <iostream>

using namespace std;
//user libraries
#include"TmLeader.h"
#include "Employee.h"

//function prototypes 
//global constants

//execution begins here
int main(int argc, char** argv) {
    cout << "This problem demonstrates polymorphism:\n";
    //declare instances
    TmLeader l;
    //declared variables 
    int mnthBonus = 300; //fixed monthly bonus pay
    l.setMnthBonus(mnthBonus);
    int reqHours = 52; //required number of trained hours he/she must attend
    l.setReqHours(reqHours);
    int attHours = 32;//attended hours
    l.setAttHours(attHours);
    
    //pass l by reference 
    PrdctWrkr *leader1= &l;
    leader1->setHrDate(2004);
    leader1->setName("Chrystalla");
    leader1->setNum(1234);
    leader1->setPayRate(23.4);
    leader1->setShift(1);
    
    //dysplay information
    cout << "Team Leader Information:\n ************* \n";
    cout << "Name:\t\t\t    ";
    cout << l.getName();
    cout << endl;
    cout << "ID number:\t\t    ";
    cout << l.getNum();
    cout << endl;
    cout << "Year Hired:\t\t    ";
    cout << l.getHrDate();
    cout << endl;
    cout << "Pay rate: \t\t    ";
    cout <<l.getPayRate();
    cout <<endl;
    cout << "Shift (1=day 2=night):      ";
    cout << l.getShift();
    cout <<endl;
    cout << "Monthly Bonus pay:\t    ";
    cout << l.getMnthBonus();
    cout<< endl;
    cout<< "Required hours of training: ";
    cout << l.getReqHours();
    cout <<endl;
    cout << "Attended hours till today:  ";
    cout << l.getAttHours();
    
            
    return 0;
}

