/*
 * 13.1
 * Design a class called Date. The class should store a date in three 
 * integers: month, day, and year. There should be member functions 
 * to print the date in the following forms:
 * 12/25/2014 December 25, 2014 25 December 2014
 * Demonstrate the class by writing a complete program implementing it.
 * Input Validation: Do not accept values for the day greater than 31 or
 * less than 1. Do not accept values for the month greater than 12 or
 * less than 1.
 */

/* 
 * File:   main.cpp
 * Author: chrystallahavadjia
 *
 * Created on April 23, 2016, 1:02 PM
 */

//system libraries
#include<iostream>
#include<string>
using namespace std;

//user libraries
class Date
{
    private:
        int day;
        int month;
        int year;
    public:
        void setDay(int);
        void setMonth(int);
        void setYear(int);
        void dsplDate();
        int getDay() const;
        int getMonth() const;
        int getYear() const;
};


//function prototypes 

//setDate assigns a value to day
void Date::setMonth(int m){
    month = m;
}
//setMonth assigns a value to month
void Date::setDay(int d){
    day = d;
}
//setYear assigns a value to year
void Date::setYear(int y){
    year = y; 
}
//**********************************
//getDay returns the value in the day member
int Date::getDay() const{
    return day;
}
//getMonth returns the value in the month member
int Date::getMonth() const{
    return month;
}
//getYear returns the value in the Year member
int Date::getYear() const{
    return year;
}

void Date::dsplDate(){
    
    string sMonth[] = {"January","February","March","April","May","June","July",
                        "August","September","October","November","December"};
    
    cout << "\n_______________________________\n";
    cout <<  "Here is the date in three different forms:\n";
    for(int i = 0; i<12;i++){
        if (i == month-1){
            cout << "\t" <<month<<"/"<<day<<"/"<<year;
            cout << endl;
            cout << "\t" << sMonth[i] << "  " << day<< ",  " << year;
            cout << endl;
            cout << "\t" << day << "  " << sMonth[i] << " " << year;
            cout << endl;
        }
    }
    
}

//global constants

//execution begins here
int main() {
    Date theDate; //define class instant
    int theMonth= 0; // declare local variable
    int theDay=0;    // declare local variable
    int theYear=0;  // declare local variable
    
    //get user input
    cout << "This program will display the date in three different forms\n";
    cout << "________________________________________________________\n";
    cout <<"Please enter the day of the month: ";
    do{
      cout << "\nEnter a number between 1 and 31: ";
      cin >> theDay;
    }while(theDay < 1 || theDay > 31);
    cout << "Please enter the month in number form: ";
    do{
      cout << "\nEnter a number between 1 and 12: ";
      cin >> theMonth;
    }while(theMonth < 1 || theMonth > 12);
    
    cout << "Please enter all four digits of the year: ";
    do{
      cout << "\nEnter a for digit number: ";
      cin >> theYear;
    }while(theYear < 1000 || theYear > 9999);
    
    //store information back into class variables
    theDate.setDay(theDay);
    theDate.setYear(theYear);
    theDate.setMonth(theMonth);
       
    // call display function
    theDate.dsplDate();
    
    return 0;
}
