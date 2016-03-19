/*
 * File:   newmain.cpp
 * Author: chrystallahavadjia
 * Created on February 22, 2016, 8:42 PM
 * Purpose: Percent increase of population
 * 5.11
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void validation(int nOrganism,int avPopulation,int nDays);
//Execution Begins Here
int main()
{
    int nOrganism = 0;
    int avePopulation = 0;
    int nDays = 0;
    float populationSize = 0;
    
    cout << "Enter the starting number of your organizations population" << endl;
    cin >> nOrganism;
    cout << "Enter the average daily increase of your organism in percent form." << endl;
    cin >> avePopulation;
    cout << "Enter for how many days your organism is increasing." << endl;
    cin >> nDays;
    
    //validation of numbers
    validation (nOrganism, avePopulation, nDays);
    populationSize = nOrganism;
    cout << "Population increase:" << endl;
    cout << "Day 1" << ":" << populationSize << endl;
    for (int i=1; i < nDays; i++)
    {
        //calculating the population increase
        populationSize *= (1+static_cast<float>(avePopulation)/100);
        //     populationSize += static_cast<float>(nOrganism*(avePopulation/100)/);
        cout << "Day " << i+1 << ":" << static_cast<int>(populationSize) << endl;
    }
    
    return 0;
}
void validation(int nOrganism,int avePopulation,int nDays)
{
    while(nOrganism < 2 )
    {
        cout << "Invalid entry for starting population number. Please enter a number above 2."<< endl;
        cin >> nOrganism;
    }
    while(avePopulation < 0)
    {
        cout << "Invalid entry for the daily population increase. Please enter a positive number."<< endl;
        cin >> avePopulation;
    }
    while (nDays < 1)
    {
        cout << "Invalid entry for starting population number. Please enter a number above 1."<< endl;
        cin >> nDays;
    }
}