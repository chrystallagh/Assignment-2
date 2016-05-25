
/* 
 * File:   main.cpp
 * Author: chrystallahavadjia
 * 15.1
 * Created on May 23, 2016, 5:38 PM
 */

//system libraries
#include <iostream>
#include<string>
//user libraries
#include"PrdctWrkr.h"

using namespace std;

//function prototypes
//Global constants

//execution begins here
int main(int argc, char** argv) {
    PrdctWrkr wrkr; //define an instant 
    //declare variables 
    string name;  //employee's name
    int num=0;     // id number
    int hrDate=0;  //hire date
    int shift=0;  ///shift employee works
    int payRate=0; //hourly pay rate
    
    cout << "Please enter the following information.\n";
    cout << "Enter the employee's name.\n";
    getline(cin,name);
    wrkr.setName(name); //store in object in employee class
    cout << "Enter the employee's id number.\n";
    cin >> num;
    wrkr.setNum(num); //stored in object in employee class
    cout << "Enter the employee's hire date(enter the four digit year employee was hired)\n";
    cin >> hrDate;
    wrkr.setHrDate(hrDate); // stored in object in employee class
    cout << "Enter the shift the employee works in (1=day, 2=night)\n";
    cin >> shift;
    wrkr.setShift(shift);//stored in object in prdctWrkr class
    cout<<"Enter the employee's pay rate for each hour.\n";
    cin >> payRate;
    wrkr.setPayRate(payRate); //stored in object in prdctWrkr clss
    
    //DYSPLAY USER INPUT 
    cout << "\nEmployee information.\n ********************\n";
    cout << "Name:                ";
    cout << wrkr.getName();
    cout <<endl;
    cout << "ID number:           ";
    cout<< wrkr.getNum();
    cout <<endl;
    cout << "Hire date(year):     ";
    cout << wrkr.getHrDate();
    cout <<endl;
    cout<< "Shift(1=day 2=night): ";
    cout<<wrkr.getShift();
    cout <<endl;
    cout << "Pay rate:            ";
    cout <<wrkr.getPayRate();
    cout <<endl;
   
    return 0;
}

