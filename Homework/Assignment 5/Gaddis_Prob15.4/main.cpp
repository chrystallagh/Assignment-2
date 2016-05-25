/*
 * 15.4
 * File:   main.cpp
 * Author: chrystallahavadjia
 *
 * Created on May 24, 2016, 3:02 PM
 */

//system libraries
#include <iostream>

using namespace std;

//user libraries
#include "Time.h"
#include "MltTime.h"
//function prototypes
//global constants

int main(int argc, char** argv) {
    //declare instance
    MltTime mTime;
    //declare variables
    int mHour=0;
    int mSec=0;
    cout << "This program converts time in military  format to the standard time format\n";
    cout  << " ******************\n";
    do{
        cout << "Enter the time in military form:(Must be between 2359 and 0000).\n ";
        cin >> mHour;
    }while(mHour>2359||mHour<0000);
    do{
        cout << "Enter the seconds:(Must be between 59 and 0)\n";
        cin >> mSec;
    }while(mSec>59||mSec<0);
    mTime.setTime(mHour,mSec);
    
    
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

    return 0;
}
