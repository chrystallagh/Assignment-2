/*
 * 15.5
 * inputing validations in class??
 */

/* 
 * File:   main.cpp
 * Author: chrystallahavadjia
 *
 * Created on May 24, 2016, 5:50 PM
 */
#include <iostream>

#include "TimeClock.h"

using namespace std;

int main(int argc, char** argv) {
        //declare instance
    TimeClock mTime;
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

    return 0;
}

