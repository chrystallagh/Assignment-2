/*
 * Problem 9.6
 *Modify Program 9-19 (the United Cause case study program) so it can be used 
 * with any set of donations. The program should dynamically allocate
 *  the donations array and ask the user to input its values.
 */

/* 
 * File:   main.cpp
 * Author: chrystalla havadjia
 *Modify Problem from book to use dynamic arrays
 * Created on March 17, 2016, 5:26 PM
 */

 //user library 
#include<iostream> 

using namespace std;

// global constants

 // Function prototypes  
void sortArr(int *[], int);
void displayArray(const int [], int);
void displaySortedArr(int *[], int);


int main(int argc, char** argv) {

 
 int numDontations = 0;

// Declare pointer.
int *donations; 
 
// Dynamically allocate pointer.
donations = new int[numDontations];

//Ask user for number of donations
cout <<"Enter the number of donations that were done" << endl;
cin >> numDontations;

// Ask user to input amount of each donation.
cout << "Enter the donation amounts" << endl;
for(int i=0; i<numDontations; i++)
{   
    cin >> donations[i];
}
 // An array of pointer.
 int *arrPtr[numDontations];
 
 
 // reference each value for the donation pointer to the pointer array
 for (int count = 0; count < numDontations; count++)
    arrPtr[count] = &donations[count];

 // Sort the donation values.
 sortArr(arrPtr, numDontations);

 
 // Display the sorted values of the donations using the pointer array
 cout << "These are the donations that are sorted in ascending order: \n";
 // call function that sorts the values
 displaySortedArr(arrPtr, numDontations);

 // Display of the donations in their original order they were inputed.
 cout << "The donations in the order they were inputed: \n";
 displayArray(donations, numDontations);
 
 //free memory
 delete []donations;
   
 return 0;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                           
//Inputs
//     Size of the pointer array
//     Pointer array
//Output
//     a->The sorted array
////////////////////////////////////////////////////////////////////////////////
 void sortArr(int *a[], int size)
 {
    int beginScan;
    int minIndex; 
    int *minElem;

    for (beginScan = 0; beginScan < (size - 1); beginScan++) 
    {
        minIndex = beginScan;
        minElem = a[beginScan];
        for(int index = beginScan + 1; index < size; index++)
        {
            if (*(a[index]) < *minElem) 
            {    
                minElem = a[index];
                minIndex = index;
            }
        }
        a[minIndex] = a[beginScan];
        a[beginScan] = minElem;
    }
 }
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                           
//Inputs
//     Size of the pointer array
//     Pointer array
//Output
//     a-> Display values of donations as they were inputed
////////////////////////////////////////////////////////////////////////////////
 void displayArray(const int arr[], int size)
  {
     for (int count = 0; count < size; count++)
     cout << arr[count] << " ";
     cout << endl;
  }
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                           
//Inputs
//     Size of the pointer array
//     Pointer array
//Output
//     a->Display values of donations in a sorted order
////////////////////////////////////////////////////////////////////////////////
void displaySortedArr(int *a[], int size)
 {
    for (int count = 0; count < size; count++) 
        cout << *(a[count]) << " ";
    cout << endl;
 }
