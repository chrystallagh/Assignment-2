/*
 * 15.2
 */

/* 
 * File:   main.cpp
 * Author: chrystallahavadjia
 *
 * Created on May 23, 2016, 6:59 PM
 */

//system libraries 
#include<iostream>
//user libraries 
#include "ShiftSup.h"

using namespace std;

//function prototypes 
//global constants
//execution begins here
int main(int argc, char** argv) {
    ShftSprvzr sWorker; //define an instant 
    //declare variables 
    string name; //supervisors name
    int num;  //supervisors id
    int hrDate; //supervisors hire date
    int salary; //supervisors annual salary
    int pBonus; //supervisors annual production bonus
    
    cout << "Please enter the following information.\n";
    cout << "Enter the supervisor's name.\n";
    getline(cin,name);
    sWorker.setName(name); //store in object in employee class
    cout << "Enter the supervisor's id number.\n";
    cin >> num;
    sWorker.setNum(num); //stored in object in employee class
    cout << "Enter the supervisor's hire date(enter the four digit year employee was hired)\n";
    cin >> hrDate;
    sWorker.setHrDate(hrDate); // stored in object in employee class
    cout << "Enter the supervisor's annual salary\n";
    cin >> salary;
    sWorker.setSalary(salary);//stored in object in ShftSprvzr class
    cout<<"Enter the supervisor's annual production bonus.\n";
    cin >> pBonus;
    sWorker.setPrdBns(pBonus); //stored in object in ShftSprvzr class
    
    //DYSPLAY USER INPUT 
    cout << "\nSupervisor information.\n ********************\n";
    cout << "Name:         \t\t ";
    cout << sWorker.getName();
    cout <<endl;
    cout << "ID number:     \t\t ";
    cout<< sWorker.getNum();
    cout <<endl;
    cout << "Hire date(year): \t ";
    cout << sWorker.getHrDate();
    cout <<endl;
    cout<< "Annual salary:    \t ";
    cout<<sWorker.getSalary();
    cout <<endl;
    cout << "Annual production bonus: ";
    cout <<sWorker.getPrdBns();
    cout <<endl;
    return 0;
}

