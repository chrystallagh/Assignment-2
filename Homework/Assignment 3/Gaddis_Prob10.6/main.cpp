/*
 * Problem 10.6
 * Write a function that accepts a pointer to a C-string as its argument. 
 * The function should count the number of vowels appearing in the string and 
 * return that number.
 * Write another function that accepts a pointer to a C-string as its argument. 
 * This function should count the number of consonants appearing in the string
 * and return that number.
 * Demonstrate these two functions in a program that performs the following 
 * steps:
 * 1. The user is asked to enter a string.
 * 2. The program displays the following menu:
 * A) Count the number of vowels in the string
 * B) Count the number of consonants in the string
 * C) Count both the vowels and consonants in the string D) 
 * Enter another string
 * E) Exit the program
 * 3. The program performs the operation selected by the user and repeats
 *  until the user selects E to exit the program.
 */

/* 
 * File:   main.cpp
 * Author: chrystalla havadjia
 * Created on Arpil 1, 2016, 2:26 PM
 */

 //user library 
#include <iostream>
#include <string>


using namespace std;

 // global constants

// function prototype
int finVowel(char *);
int findCons(char *);

int main() 
{
    //declared variables
    int size = 50;
    int menuNum = 0;
    int cons = 0;
    int vowel = 0;
    char str[size];
    

     do{         
        // menu
        cout << "... MENU: \n";
        cout << "Enter 1 to count the number of vowels in the string"<< endl;
        cout << "Enter 2 to count the number of consonants in the string"<< endl;
        cout << "Enter 3 to count both the vowels and consonants in the string"
                <<endl;
        cout << "Enter 4 to exit the program" << endl;
        cout << "-----------------------------------\n";
        
        cout << "Enter your choice" <<endl;
        cin >> menuNum;
        cin.ignore();
        while(menuNum <= 0 || menuNum > 4){
            cout << "Invalid: Please enter a number from the list" << endl;
            cin >> menuNum;
            cin.ignore();
        }   
        
        if (menuNum != 4){
            // obtain user input
            cout << "Enter a string to count the vowels and consonants" << endl;
            cin.getline(str,size);
        }

        switch(menuNum){ 
        
           case 1: 
               vowel = finVowel(str); 
               cout << "The number of vowels is " << vowel << endl; 
               break;
           case 2: 
               cons = findCons(str);
               cout << "The number of consonants is " << cons << endl;
               break;
           case 3:
               for(int i=0;i<strlen(str);i++)cout<<str[i];
               cout<<endl;
               vowel = finVowel(str); 
               cons = findCons(str);
               cout << "The number of vowels is " << vowel << endl;
               cout << "The number of consonants is " << cons << endl;
               break;
           case 4: return 0; break; 
           default:
               cout <<"Invalid entry" << endl;
               break;
         }
        cout << endl;
        
    }while(menuNum != 4 );
    
    return 0;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                           
//Inputs
//     Size of the pointer
//     Pointer
//Return
//     numbers of consonants in string
////////////////////////////////////////////////////////////////////////////////
int findCons(char *phrase){
    
    int cons = 0;
    
    // check if letter is space null of vowel and increment if it is not
    for(int i=0; i < strlen(phrase); i++){
     if (phrase [i] != '\0' && phrase[i] != ' ')
        if(phrase[i] != 'a'&& phrase[i] !='e'&& phrase[i] !='i'&&
           phrase[i]!='o'&& phrase[i] != 'u')
             cons++;
    }
    
   return cons;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                           
//Inputs
//     Size of the pointer
//     Pointer
//Return
//     number of vowels in string
////////////////////////////////////////////////////////////////////////////////
int finVowel(char *phrase){
    
    int vowel=0;
  
    // test if letter is a vowel and increment vowel if it is
    for(int i=0; i < strlen(phrase); i++){
     if (phrase [i] != '\0' && phrase[i] != ' ')
        if(phrase[i] == 'a'|| phrase[i] =='e'||phrase[i] =='i'||
           phrase[i]=='o'||phrase[i] == 'u')
             vowel++;
     }
    return vowel;
}
