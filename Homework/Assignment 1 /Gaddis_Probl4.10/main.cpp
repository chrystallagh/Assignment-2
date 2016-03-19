/*
 * File:   newmain.cpp
 * Author: chrystallahavadjia
 * Created on February 22, 2016, 8:42 PM
 * Purpose: Days in a month
 * 4.10
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void validation(int month);
void determineLeapYear(int year);
//Execution Begins Here
int main()
{
    int  month = 0;
    int year = 0;
    
    //Display
    cout << " 1. January \n 2. February \n 3. March \n 4. April \n 5. May \n 6. June ";
    cout << "\n 7. July \n 8. August \n 9. September \n 10. October \n 11. November \n 12. December" << endl;
    
    // Obtain user impute
    cout << "Enter the number corresponding to the month you wish to know the number of days" << endl;
    cin >> month;
    
    //validation of entry
    validation(month);
    
    // obtain year form user
    cout << "Enter the year this month is in." << endl;
    cin >> year;
    
    //determine number of days in month
    switch (month)
    {
        case 1 : case 3: case 5: case 7: case 8: case 10: case 12:
            cout << "This month has 31 days." << endl;
            break;
            
        case 4: case 6: case 9: case 11:
            cout << "This month has 30." << endl;
            break;
            
            // if February call function to determine if leap year.
        default: (month == 2);
            determineLeapYear(year);
            
            
    }
    return 0;
}
void validation(int month)
{
    while (month < 1 || month >12)
    {
        cout << "Invalid entry. Please enter a number between 1 and 12."<< endl;
        cin >> month;
    }
}
void determineLeapYear(int year)
{
    //cout << "this is working";
    if (year%100 == 0)
    {
        if (year%400 == 0)
        {
            cout << "The year you selected is a leap year" << endl;
            cout << "The number of days in this month is 29" << endl;
        }
        else
        {
            cout << "The year you selected is not a leap year." << endl;
            cout << "The number of days in this month is 28." << endl;
        }
    }
    else if (year%4 == 0)
    {
        cout << "The year you selected is a leap year." << endl;
        cout << "The number of days in this month is 29" << endl;
    }
    else
    {
        cout << "The year you selected is not a leap year." << endl;
        cout << "The number of days in this month is 28." << endl;
    }
}
