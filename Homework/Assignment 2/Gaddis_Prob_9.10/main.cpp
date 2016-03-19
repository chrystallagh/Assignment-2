/*
 * Problem 9.10
 * Write a function that accepts an int array and the array’s size as arguments.
 * The function should create a copy of the array, except that the element 
 * values should be reversed in the copy. The function should return a pointer
 *  to the new array. Demonstrate the function in a complete program.
 */

/* 
 * File:   main.cpp
 * Author: chrystalla havadjia
 * flip numbers in array
 * Created on March 17, 2016, 10:38 PM
 */

 //user library 
#include<iostream> 
#include <cstdlib>

using namespace std;

// global constants

 // Function prototypes
int *flipArray(int a[], int n);

int main(int argc, char** argv) {
    
    int *reverse;
    int size;
    int array[size];
    
    // obtain user input for size of array
    cout << "Enter the amount of number you would like to be on this list:"
            <<endl;
    cin >> size;
    
    // obtain user input for each value in the list
    cout <<"Enter the number you would like to see in reversed order:" <<endl;
    for ( int j=0; j< size; j++)
        cin >> array[j];
    
    reverse = flipArray(array, size);
    
    cout <<"This is they array copied into the pointer in reverse order: \n";
     for (int i = 0; i < size; i++){
         cout << *(reverse+i) <<endl;             
     }
    
    return 0;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                           
//Inputs
//     Size of the array
//     Array
//Output
//     a->The sorted array pass into pointer in reverse order
////////////////////////////////////////////////////////////////////////////////
int *flipArray(int a[], int n){

    int *pointer;
    
    pointer = new int[n];
   
    int first = 0;
    
    // copy values in array into a pointer in reverse 
    for (int i =0; i < n; i++){
       // save value of array
      first = a[i];
      //copy last value of array into first value of pointer
      pointer[i] = a[n-i-1];
     // assign the fist number of the array into the last 
       a[n-i-1] = first;
    }
    
    // free memory
    delete []pointer;
    return pointer;
}

