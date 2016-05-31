#include<iostream>
using namespace std;
#include "Hints.h"

Hints::Hints(){ // default constructor
    hnt1='*';
    hnt2='#';
    hintR = true;
} 
//mutator functions
void Hints::disHnt(){ //display user input for hint, demonstrates polymorphism
    cout << "  You have entered " << hint << endl; 
} 
void Hints::setHntr(bool hr){ //store in object
    hintR=hr;
}
//acessor functions
char Hints::getHnt1() const{ //retrieve information in object
    return hnt1;
}
char Hints::getHnt2() const{ //retrieve information in object
    return hnt2;
}
bool Hints::getHintR() const{// retriever information in object
    return hintR;
} 