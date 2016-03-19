/*
 *  Problem 9.3
 *  Modify Problem 2 above so the lowest test score is dropped. 
 *  This score should not be included in the calculation of the average.
 *  Input Validation: Do not accept negative numbers for test scores.*/

/* /
 * File:   main.cpp
 * Author: chrystalla havadjia
 * Calculate Test average but dtop lowest score
 * Created on March 15, 2016, 1:52 PM
 */

 //user library 
#include<iostream> 
using namespace std;

// global constants

// function prototype
void markSrt(int *, int);
float calcAverage(int *,int);
void display(int *, int, float);


int main() {
    int *testScore;
    int size = 0;
    float average = 0;
    
    testScore = new int[size]; // dynamic array
    
    //user input
    cout << "Enter the number of test scores in this class" << endl;
    cin >> size;
    
    //user input
    cout << "Enter each test score individually" << endl;
    for (int i = 0; i < size; i++){
        
        cin >> testScore[i];
        while ( *(testScore+i) < 0){
            cout << "This is an invalid entry please enter a positive number"
                    << endl;
            cin >> testScore[i];  
        }
        
      }
    
    // sort the test scores
    markSrt(testScore, size);
    // calculate the average
    average = calcAverage(testScore, size);
    //display results
    display(testScore, size, average);
    
    
    // free memory
    delete []testScore;
    
    return 0;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                           
//Inputs
//     Size of the array
//     Array
//Output
//     a->The sorted array
////////////////////////////////////////////////////////////////////////////////
void markSrt(int *a, int n)
{   
    // sort the numbers
    for(int pos=0;pos<n-1;pos++){
        for(int row=pos+1;row<n;row++){
            if(*(a+pos)>*(a+row)){
                *(a+pos)=*(a+pos)^*(a+row);
                a[row]=a[pos]^a[row];
                *(a+pos)=*(a+pos)^*(a+row);
            }
        }
    }
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                           
//Inputs
//     Size of the array
//     Array
//Output
//     None
////////////////////////////////////////////////////////////////////////////////
float calcAverage( int *a ,int n){
    
    int average = 0;
    float total = 0;
    
    for(int i =1; i< n; i++){
        total += *(a+i);
    }
    
   return total/(n-1);
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                           
//Inputs
//     Size of the array
//     Array
//     Average
//Output
//     a-> Sorted list of grades
//     a-> The average of the class
////////////////////////////////////////////////////////////////////////////////
void display(int *a, int size, float average){
    
    cout << "Sorted list" << endl;
    
    for ( int i =0; i < size; i++){
        cout << "\t" << *(a+i) << endl;      
    }
    cout << "Average" << endl;
    average = calcAverage(a, size);
    cout << "\t" << average << endl;  
    cout << "The value that was droped is:\t" << *a << endl;
    
}

