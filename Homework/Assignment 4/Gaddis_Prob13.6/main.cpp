
/* 13.6
 * File:   main.cpp
 * Author: chrystallahavadjia
 *
 * Created on April 24, 2016, 11:39 AM
 */

//system libraries
#include <iostream> 

using namespace std;

//user libraries
#include"Invtry.h"

//global constants
//function prototype 
//execution begins here
int main(int argc, char** argv) {
    
    Invtry info; //define class
    //declare variable
    int itmNum; // holds the item's item number
    int qnty; // holds quantity of item 
    float cost;  //per-unit cost
    float totCost ; // total inventory cost (quantity*times)
    
    cout << "This program obtains the item number, quantity of an item, "
            "cost of the item and calculates the total cost of all the items\n";
    cout << "________________________________________________________\n";
    cout << "Enter the following information: \n";
    do{
      cout << "Enter a positive number:\n";      
      cout << "Item Number:        ";
      cin >> itmNum; //obtain item number
    }while(itmNum < 0);
    info.setItmNum(itmNum); //store in  object 
    
    do{
      cout << "Enter a positive number:\n";   
      cout << "Quantity of items:  ";
      cin >> qnty;
    }while(qnty<0);
    info.setQnty(qnty); //store in object
    do{
      cout << "Enter a positive number:\n";   
      cout << "Cost:               ";
      cin >> cost;   // obtain
    }while(cost<0);
    info.setCost(cost); // store in object
    
    cout << "********************************************\n";    
    cout <<"This is the information you have imputed including the total cost\n";
    cout << "Item Number:        ";
    cout << info.getItmNum();
    cout << endl;
    cout << "Quantity of items:  ";
    cout << info.getQnty();
    cout << endl;  
    cout << "Cost:               ";
    cout << info.getCost(); //display age object
    cout << endl;
    cout << "Total Cost:         "; 
    cout << info.getTotCost(); // display in object
    cout << endl;    
    
    cout << "********************************************\n"; 
    
    return 0;
}

