/*
 * File:   newmain.cpp
 * Author: chrystallahavadjia
 * Created on February 22, 2016, 8:42 PM
 * Purpose: Convert U.S. dollars to Yen and Euro
 * 3.13
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here
int main()
{
    const float YEN_PER_DOLLAR = 114.02, EUROS_PER_DOLLAR = 0.92;
    float dollars = 0, yen = 0, euro = 0;
    
    cout << "What is the amount of U.S dollars you wish to convert?\n";
    cin >> dollars;
    
    yen = YEN_PER_DOLLAR * dollars;
    euro = EUROS_PER_DOLLAR * dollars;
    
    cout << "The amount of money you will receive in yen and in euros is:" << endl;
    cout << "\tYen: " << yen << "\n\tEuros: " << euro;
    
    return 0;
}