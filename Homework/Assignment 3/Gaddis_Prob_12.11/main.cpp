/*
 * 12.11
 * Write a program that uses a structure to store the following data on a 
 * company division:
 * Division Name (such as East, West, North, or South) Quarter (1, 2, 3, or 4)
 * Quarterly Sales
 * The user should be asked for the four quarters’ sales figures for the East,
 *  West, North, and South divisions. The data for each quarter for each 
 * division should be written to a file.
 * Input Validation: Do not accept negative numbers for any sales figures.
 */

/* 
 * File:   main.cpp
 * Author: chrystallahavadjia
 *
 * Created on April 3, 2016, 9:58 PM
 */

//user libraries
#include <iostream>
#include<fstream>
#include<string>

using namespace std;

//global constants

//function prototypes


struct Corporate
{
   string name; 
   int quarter;
   int sales;
};

int main(int argc, char** argv) {
    
   // define structure variable 
    const int NUM = 4;
    Corporate division[NUM][NUM];
    
    //declared variables
    string fileName;
    ofstream outFile;
    
    

    cout << "... This program stores information into a file about the divisions"
            "(such as East, West, North, or South) and the sales they had for "
            "each Quarter" << endl;
    cout << "--------------------------------------\n"; 
    
    //get user input for an input file name
        cout << "Enter a file name to store the quarter sales for one "
                "of the divisions" << endl;
        //  cin.ignore();
        getline(cin,fileName); 
        outFile.open(fileName.c_str());
        
    // get user input for each district and each quarter
    for(int i=0 ; i< NUM ; i++){
        
        cout << "Name of division: " ;
        cin >> division[i][i].name;
        cout << endl;
       
        cout << "Enter the amount of sales for each quarter" << endl; 
        for (int k=0 ; k <NUM ; k++){
            cout << "Quarter: ";
            cin >> division[i][k].quarter; 
            
            cout << "Quarterly Sales: ";
            cin >> division[i][k].sales;
            
            while(division[i][k].sales < 0){
                cout << "Enter a positive number for Quarterly Sales\n";
                cout << "Quarterly Sales: ";
                cin >> division[i][k].sales;
            }   
        }
        cout << endl;
 
    } 
         
    // input information in file
    for(int i=0 ; i< NUM ; i++){
        
        outFile << "Division: " ;
        outFile<< division[i][i].name << endl;
        for (int k=0 ; k <NUM ; k++){
            outFile << "Quarter: ";
            outFile << division[i][k].quarter << endl;
            outFile << "Quarterly Sales: ";
            outFile << division[i][k].sales << endl;
        }
        outFile << endl;
    }   
     cout << endl; 
     
    return 0;
}

