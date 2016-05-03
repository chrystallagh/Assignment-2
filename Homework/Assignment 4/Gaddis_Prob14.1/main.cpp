/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 14.1
 * File:   main.cpp
 * Author: chrystallahavadjia
 *
 * Created on April 29, 2016, 3:28 PM
 */

#include <iostream>
using namespace std;

//user libraries
#include"Number.h"

//global constants
//function prototypes
//execution begins here
int main(int argc, char** argv) {
    
    Number num;
    int nums;
    
    cout << "This program takes a number and writes it in English form "
            "to demonstrate static strings\n";
    cout << "_________________________________\n";
    //user input
    do{
       cout <<"Enter the a number between 0 and 9999:\n";
       cin >> nums;   
    }while(nums < 0  ||  nums > 9999);
    num.Print(nums);
    
    return 0;
}

