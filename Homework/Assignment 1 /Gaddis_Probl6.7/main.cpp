/* 
 * File:   newmain.cpp
 * Author: chrystallahavadjia
 * Purpose: Temperature conversions
 * 6.7
 */
//System Libraries
#include <iostream>
#include<iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
float celsius(int fahrenheit);
//Execution Begins Here
int main() 
{   
    
    cout << "Equivalent temperatures between Celcius and Fahrenheit." << endl;
    cout << "Fahrenheit  \t Celsius:" << endl;
    
    for (int fahrenheit = 0 ; fahrenheit < 20; fahrenheit++)
    { 
      cout << fahrenheit << "\t\t" << celsius(fahrenheit) << endl;       
    }
     
    return 0;
}  
//convert fahrenheit to celcius 
float celsius(int fahrenheit)
{   
    float celsius = 0;
    cout << fixed << showpoint << setprecision(2);
    celsius = 5*(static_cast<float>(fahrenheit)-32)/9;
    return celsius;
}