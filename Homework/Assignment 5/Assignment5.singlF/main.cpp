/*
 * Assignment 5
 * Gaddis _8theddition
 * Author: chrystallahavadjia
 *
 * Created on May 27, 2016, 6:54 PM
 */

//system libraries
#include <iostream>
#include<string>
//user libraries
#include"PrdctWrkr.h"
#include "ShiftSup.h"
#include"TmLeader.h"
#include "Employee.h"
#include "Time.h"
#include "MltTime.h"
#include "TimeClock.h"
#include"Absolut.h"

//Global Constants 

//Function Prototypes 
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();

//Begin Execution
int main(int argv,char *argc[]){
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        case 5:    problem5();break;
        case 6:    problem6();break;
        default:   def(inN);}
    }while(inN>=1&&inN<=6);
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"Menu for Assignment 5"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

void problem1(){
        cout<<"In problem # 1"<<endl<<endl;
        cout << "Problem 15.1 Gaddis 8th edition\n\n";
     PrdctWrkr wrkr; //define an instant 
    //declare variables 
    string name;  //employee's name
    int num=0;     // id number
    int hrDate=0;  //hire date
    int shift=0;  ///shift employee works
    int payRate=0; //hourly pay rate
    bool vldtin=true; //validation, flag to re-input information
    cout <<"This program demonstrates inheritance and exceptions\n";
    cout << "Please enter the following information.\n";
    cout << "Enter the employee's name.\n";
    cin.ignore();
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
    while(vldtin){
        try{
            //store shift value in object
            wrkr.setShift(shift);//stored in object in prdctWrkr class
            //if valid entry set bool to false
            vldtin = false;
        }
        catch (PrdctWrkr::ExptClass){
            cout << "Invalid entry, please enter 1 or 2 for shift\n";
            cin>>shift;
        }
    }
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
    cout<<  "Shift(1=day 2=night):";
    cout<<wrkr.getShift();
    cout <<endl;
    cout << "Pay rate:            ";
    cout <<wrkr.getPayRate();
    cout <<endl;
    
    cout<< endl;
}

void problem2(){
        cout<<"In problem # 2"<<endl<<endl;
        cout << "Problem 15.2 Gaddis 8th\n\n";
        
    ShftSprvzr sWorker; //define an instant ShiftSup.h
    //declare variables 
    string name; //supervisors name
    int num;  //supervisors id
    int hrDate; //supervisors hire date
    int salary; //supervisors annual salary
    int pBonus; //supervisors annual production bonus
    bool invVlu =true; //flag if invalid entry
    cout <<"This program demonstrates inheritance and exceptions\n";
    cout << "Please enter the following information.\n";
    cout << "Enter the supervisor's name.\n";
    cin.ignore();
    getline(cin,name);
    sWorker.setName(name); //store in object in employee class
    cout << "Enter the supervisor's id number.\n";
    cin >> num;
    sWorker.setNum(num); //stored in object in employee class
    cout << "Enter the supervisor's hire date(enter the four digit year employee was hired)\n";
    cin >> hrDate;
    sWorker.setHrDate(hrDate); // stored in object in employee class
    cout << "Enter the supervisor's annual salary(enter a positive number)\n";
    cin >> salary;
     while(invVlu){
        try{
            sWorker.setSalary(salary);//stored in object in ShftSprvzr class
            invVlu=false;//if value entry exit while loop
        }
        catch(ShftSprvzr::InvdVlu){
            cout << "Invalid entry, please enter a positive number\n";
            cin >> salary;
        }
    }
    
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
    cout << endl;
}

void problem3(){
        cout<<"In problem # 3"<<endl<<endl;
        cout << "Problem 15.3 Gaddis 8th\n\n";
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
        cout<< endl<< endl;
}

void problem4(){
        cout<<"In problem # 4"<<endl<<endl;
        cout << "Problem 15.4 Gaddis 8th\n\n";
    //declare instance
    MltTime <int> mTime;
    //declare variables
    int mHour=0;
    int mSec=0;
    int mSec2=0;
    cout << "This program converts time in military  format to the standard time format\n";
    cout  << " ******************\n";
    do{
        cout << "Enter the time in military form:(Must be between 2359 and 0000).\n ";
        cin >> mHour;
    }while(mHour>2359||mHour<0000);
    cout << "This portion demonstrates templates\n************\n";
    cout <<"Here you can input two numbers for the seconds and the program will choose the largest number\n";
    do{
        cout << "Enter the seconds1:(Must be between 59 and 0)\n";
        cin >> mSec;
    }while(mSec>59||mSec<0);
   
    do{
        cout << "Enter the seconds2:(Must be between 59 and 0)\n";
        cin >> mSec2;
    }while(mSec>59||mSec<0);
    
     mTime.setTime(mHour,mSec,mSec2);
    
    cout << "Military time: ";
    if(mTime.getHour()==0)
        cout << "0000";
    else if(mTime.getHour()<900){
        cout << "0" << mTime.getHour();
    }
    else
     cout << mTime.getHour();

    cout <<endl;
    cout << "Standard time: ";
    if(mTime.getStndHr()==0)
        cout << "1200";
    else if(mTime.getStndHr()<900){
        cout << "0" << mTime.getStndHr();
    }
    else
     cout << mTime.getStndHr();
    
    cout<< "\nSeconds: ";
    cout << mTime.bigger();
    cout<< endl<<endl;
        
}

void problem5(){
        cout<<"In problem # 5"<<endl<<endl;
        cout << "Problem 15.5 Gaddis 8th\n\n";
     //declare instance
    TimeClock <int> mTime;
    //declare variables
    int sHour=0;
    int eHour=0;
    cout << "This program finds the elapsed time between a starting and ending time within the same day\n";
    cout  << " ******************\n";

    mTime.setTimeC1();

    mTime.setTimeC2();

    cout <<endl;
    cout << "Time elapse: ";
    cout<<mTime.getElapse();
    cout << endl<<endl;
}

void problem6(){
        cout<<"In problem # 6"<<endl<<endl;
        cout << "Problem 16.4 Gaddis 8th\n\n";
        
      //declare variable
    Absolut <int>abs1(-5); 
    Absolut <float> abs2(-4.3); //demonstrate templates using two different data types
    
    cout << "This program demonstrates Templates using different data types\n";
    cout <<"_________________________\n";
    cout << "This program returns the absolute value of a number inputed\n\n";
    
    cout << "The absolute value of " << abs1.getA() << " is " << abs1.FndAbs();
    cout << endl;
    cout << "The absolute value of " << abs2.getA() << " is " << abs2.FndAbs();
    cout<<endl<<endl;

}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}