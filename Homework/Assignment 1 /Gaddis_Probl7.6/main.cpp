/* 
 * File:   newmain.cpp
 * Author: chrystallahavadjia
 * Purpose: Temperature conversions
 * 7.6
 */

//System Libraries
#include <iostream>
#include<fstream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here
int main() 
{   
    const int MONTH = 3;
    const int DAYS = 30;
    int rainy = 0;
    int cloudy = 0;
    int sunny = 0;
    int rainyTot = 0;
    int cloudyTot=0;
    int sunnyTot = 0;
    int wettestMonth = -1;
    int month = 0;
 
    
    char metereologyData[MONTH][DAYS];
    ifstream weather;
    
    //OPEN file
    weather.open("/Users/chrystallahavadjia/Desktop/rainyfile.txt");
    if (!weather)
        cout << "fail" <<endl;
    
    //write file information in array
    for (int m = 0; m < MONTH; m++)
    {
        for (int d = 0; d < DAYS; d++)
        {
            weather >> metereologyData[m][d]; 
	}
    }
    
    // calculate how many days were rainy,cloudy or sunny
     cout << "Days of each type for each month:";
    for (int i=0; i < MONTH; i++)
    {
        rainy = 0;
        sunny = 0;
        cloudy = 0;
        
        for(int d = 0; d < DAYS; d++)
        { 
            
            if (metereologyData[i][d] == 'R' || metereologyData[i][d] == 'r')
             rainy++;
            else if (metereologyData[i][d] == 'C' || metereologyData[i][d] == 'c')
             cloudy++;
            else if (metereologyData[i][d] == 'S' || metereologyData[i][d] == 's' )
              sunny++;
            
        }
        if (rainy > wettestMonth)
        {
            wettestMonth >> rainy;
            month >> i;
        }
        
        //to find total rainy days of all months
        rainyTot = rainyTot + rainy;
        cloudyTot = cloudyTot+ cloudy;
        sunnyTot = sunnyTot + sunny;
                          
       
        cout <<  "\n Month " << i+1 << " :\n"<< endl;
        cout << " rainy " << rainy << endl << " cloudy " << cloudy << endl << " sunny " << sunny << endl;
    }
     
     cout << "Total days of rain: " << rainyTot << endl;
     cout << "Total cloudy days:  " << cloudyTot << endl;
     cout << "Total sunny days:   " << sunnyTot <<endl;
     
     cout << "The months with the most rainy days is: Month " << month + 1 << endl;

    weather.close();
    return 0;
} 