//Chrystalla Havadjia
//Class that stores user inputs
#ifndef USRINPT_H
#define USRINPT_H

#include<iostream>
#include<string>

using namespace std;

class UsrInpt{
    protected:
        int mxPlys; //user inputs of number of plays
        int hint; //user input of which hint to output
        int pos; //user inputs position of color in bonus game
        int num; // bonus question, user inputs number of colors to be generated
        char ans; //user inputs of yes or no form.
        static string order[8]; //display the order of colors, ex. "first color"
    public:
        //exception class
        class ExptClass //Empty class declaration
            {};
        UsrInpt();//{ //default constructor
        //mutator functions      
        void setMxPlys(int);// set user input in object
        void setHint(int);//set user input in object
        void setPos(int);//set user input in object
        void setNum(int);//set user input in object
        void setAns(char);//set user input in object
        //print function
        void prntOrder(int); //print user color order
        //acessor functions
        int getMxPlys() const; //get object
        int getHint() const; //get object
        int getPos() const; //get object
        int getNum() const; //get object
        char getAns() const; //get object 
        UsrInpt operator ++ (); //overload postfix ++ 
};

#endif /* USRINPT_H */