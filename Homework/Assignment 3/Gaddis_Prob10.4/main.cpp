/*
 * Problem 10.4
 *Write a function that accepts a pointer to a C-string 
 * as an argument and returns the number of words contained
 *  in the string. For instance, if the string argument is
 *  “Four score and seven years ago” the function should 
 * return the number 6. Demonstrate the function in a 
 * program that asks the user to input a string and then
 *  passes it to the function. The number of words in 
 * the string should be displayed on the screen. 
 * Modify the program you wrote for Problem 3 (Word Counter),
 * so it also displays the average number of letters in each
 *  word.
 */

/* 
 * File:   main.cpp
 * Author: chrystalla havadjia
 * Created on March 30, 2016, 2:26 PM
 */


 //user library 
#include <iostream>
#include <string>

using namespace std;

 // global constants

// function prototype
int wordCount(char *, int);
int findAv(char *, int, int);


int main() 
{
    // declare variables
    int size = 50;
    char phrase[size];
    int number = 0;
    int average = 0;

    
    cout << "..This program counts the letters in a phrase of your choice, counts"
            "the number of words and finds the average amount of letters per "
            "word\n";
    cout << "--------------------------------------------------------------\n";
    
    //obtain user input
    cout << "Enter a your favorite phrase\n";
    cin.getline(phrase,size);
    cin.ignore();
      
    // call function and return result
    number = wordCount(phrase,size);
    average = findAv(phrase,size, number);
    
    //display result
    cout << "The number of words in this sentence is " <<number <<endl;
    cout << "The average number of letters is " << average;
    
    return 0;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                           
//Inputs
//     pointer c-string
//     Size of the pointer
//Return
//     numbers of words in phrase
////////////////////////////////////////////////////////////////////////////////
int wordCount(char *phrase, int max){
    
    int count=0;

   // test each character is it is a space
    for(int i=0; i < max; i++){
        if (phrase[i] == ' ')
            count++;   // count spaces
    }
    
   return count+1;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//  
//Inputs
//     pointer c-string
//     Size of the pointer
//     number of words
//Return
//     average number of letters
////////////////////////////////////////////////////////////////////////////////
int findAv(char *phrase, int max, int number){
    
    //declared variables in function
    int counter = 0;
    int letters =0;
    int total = 0;
    int average = 0;
    
    //test each character until 
    for(int i=0; i < max; i++){
      if (phrase [i] != '\0' && phrase[i] != ' ')
            counter++;
    }
    
    cout << "The total letters in this sentence is " << counter << endl;
    
    average = counter/number;
       
    return average;
}
