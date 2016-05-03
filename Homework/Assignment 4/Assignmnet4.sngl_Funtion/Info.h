/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Info.h
 * Author: chrystallahavadjia
 *
 * Created on April 25, 2016, 2:53 PM
 */

#ifndef INFO_H
#define INFO_H
#include <string>
using namespace std;
//user libraries 
class Info
{
    private:
        string name;
        string address;
        int age;
        int phnNum;
    public:
        void setName(string);
        void setAddress(string);
        void setAge(int);
        void setPhnNum(int);
        string getName() const;
        string getAddress() const;
        int getAge() const;
        int getPhnNum() const;
};

#endif /* INFO_H */

