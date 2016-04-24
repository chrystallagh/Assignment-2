/*
 * 4. Personal Information Class
 * Design a class that holds the following personal data: name, address, age, 
 * and phone number. Write appropriate accessor and mutator functions. 
 * Demonstrate the class by writing a program that creates three instances 
 * of it. One instance should hold your information, and the other two should
 *  hold your friends’ or family members’ information.
 */

/* 
 * File:   main.cpp
 * Author: chrystallahavadjia
 *
 * Created on April 23, 2016, 3:40 PM
 */

//system libraries
#include <iostream> 
#include<string>

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

//global constants

//function prototypes 

//assigns a value to variable, mutator functions
void Info::setName(string n){
    name = n;
}
//assigns a value to variable
void Info::setAddress(string a){
    address = a;
}
//assigns a value to variable
void Info::setAge(int ag){
    age = ag; 
}
//assigns a value to variable
void Info::setPhnNum(int p){
    phnNum; 
}
//**********************************
//return value in a member, accessor functions
string Info::getName() const{
    return name;
}
//return value in a member 
string Info::getAddress() const{
    return address;
}
//return value in a member 
int Info::getAge() const{
    return age;
}
//return value in a member 
int Info::getPhnNum() const{
    return phnNum; 
}
int main() {
    
    //declare local variables
    string name;
    string address;
    int age;
    int phnNum;
    //define different instances
    Info personal;
    Info frend;
    Info famly;
    
    cout <<"This program obtains a specific user,the user's friend and a "
            "user's family member's personal information\n";
    cout << "_________________________________________________\n";
    // get users personal information, first instant
    cout << "Enter the following information about yourself: \n";
    cout << "Name: ";
    getline(cin, name); //obtain name
    personal.setName(name); //store in name object
    cout << "Address: ";
    cin.ignore();
    getline(cin, address);// obtain address
    personal.setAddress(address); //store in address object
    cout << "Age: ";
    cin >> age;   // obtain age
    personal.setAge(age); // store in age object
    cout << "Phone Number: "; 
    cin >> phnNum;  //obtain phone number
    personal.setPhnNum(phnNum); // store in object
    cout << "_________________________________________________\n";
    //get second instant, information about user's friend
    cout << "Enter the following information about your friend:\n";
    cout << "Name: ";
    cin.ignore();
    getline(cin, name); //obtain name
    frend.setName(name); //store in name object
    cout << "Address: ";
    cin.ignore();
    getline(cin, address);// obtain address
    frend.setAddress(address); //store in address object
    cout << "Age: ";
    cin >> age;   // obtain age
    frend.setAge(age); // store in age object
    cout << "Phone Number: "; 
    cin >> phnNum;  //obtain phone number
    frend.setPhnNum(phnNum); // store in object
    cout << "_________________________________________________\n";
    //get third instant, information about user's family member
    cout << "Enter the following information about a family member:\n";
    cout << "Name: ";
    cin.ignore();
    getline(cin, name); //obtain name
    famly.setName(name); //store in name object
    cout << "Address: ";
    cin.ignore();
    getline(cin, address);// obtain address
    famly.setAddress(address); //store in address object
    cout << "Age: ";
    cin >> age;   // obtain age
    famly.setAge(age); // store in age object
    cout << "Phone Number: "; 
    cin >> phnNum;  //obtain phone number
    famly.setPhnNum(phnNum); // store in object
    cout << "_________________________________________________\n";
    
    
    
    return 0;
}

