#ifndef HINTS_H
#define HINTS_H

#include<iostream>
using namespace std;
#include"UsrInpt.h"

class Hints: public UsrInpt { //Hints is a UsrInpt, demonstrates inheritance
    private: //UsrInpt is the base class and Hints is the derived class
       char hnt1; // if correct color and right spot
       char hnt2;// if correct color but not correct spot
       bool hintR; //exit hint when false
    public: 
        Hints(); // default constructor
        //mutator functions
        void disHnt(); //display user input for hint, demonstrates polymorphism
        void setHntr(bool hr); //store in object
        //acessor functions
        char getHnt1() const; //retrieve information in object
        char getHnt2() const; //retrieve information in object
        bool getHintR() const;// retriever information in object
};
#endif /* HINTS_H */