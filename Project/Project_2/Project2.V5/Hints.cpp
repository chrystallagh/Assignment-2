//Chrystalla Havadjia
#include<iostream>
using namespace std;
#include "Hints.h"

Hints::Hints(){ // default constructor
    hnt1='*';
    hnt2='#';
    hintR = true;
    hintD1= true;
    hintD2=true;
} 
//mutator functions
void Hints::disHnt(){ //display user input for hint, demonstrates polymorphism
    cout << "  You have entered " << hint << endl; 
} 
void Hints::setHntr(bool hr){ //store in object
    hintR=hr;
}
void Hints::setHntD1(bool h1){//store in object
    hintD1=h1;
}
void Hints::setHntD2(bool h2){//store in object
    hintD2=h2;
}
//acessor functions
char Hints::getHnt1() const{ //retrieve information in object
    return hnt1;
}
char Hints::getHnt2() const{ //retrieve information in object
    return hnt2;
}
bool Hints::getHintR() const{// retrieve information in object
    return hintR;
} 
bool Hints::getHintD1() const{//retrieve information in object
    return hintD1;
}
bool Hints::getHintD2() const{//retrieve information in object 
    return hintD2;
}