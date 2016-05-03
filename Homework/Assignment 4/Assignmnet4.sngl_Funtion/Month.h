/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Month.h
 * Author: chrystallahavadjia
 *
 * Created on May 1, 2016, 11:21 PM
 */

#ifndef MONTH_H
#define MONTH_H

#include <string>

class Month {
    private:
        int mnthNum;
        //definition of static member variables 
         std::string month; 
         
       std::string months[14];
    public:
        Month(){
            mnthNum = 1;
            month ="January";
        }
        Month(std::string);
        Month(int);
        void setName(std::string s){
            month =s;
        }
        void setNum(int n){
            mnthNum = n;
        }
        std::string getName() const{
            return months[mnthNum-1];
        }
        int getNum() const{
            return mnthNum;
        }
         //overloaded operator functions
        Month operator ++ (int); //overload prefix ++
        Month operator ++ (); //overload postfix ++      
        Month operator -- (int); //overload prefix --
        Month operator -- (); //overload postfix --     
};

#endif /* MONTH_H */

