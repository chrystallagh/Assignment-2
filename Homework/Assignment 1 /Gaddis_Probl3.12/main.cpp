/* 
 * File:   newmain.cpp
 * Author: chrystallahavadjia
 * Created on February 22, 2016, 8:42 PM
 * Purpose: Convert Fahrenheit to Celsius
 * 3.12
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
    float degreesc=0;
    
    cout << "What are the degrees in Celsius outside right now?" << endl;
    cin  >> degreesc;
    cout << "The temperature in Fahrenheit is " << 9 * .2 * degreesc + 32 << " degrees.";
    
    return 0;
}