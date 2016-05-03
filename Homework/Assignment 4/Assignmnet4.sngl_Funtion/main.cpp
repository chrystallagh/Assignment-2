//Chrystalla Havadjia
//assignment 4

//Library includes 
#include <iostream>
#include<string>
#include<iomanip>
using namespace std;

//user libraries
#include"Date.h"
#include "Info.h"
#include"RetailItem.h"
#include"Invtry.h"
#include "Circle.h"
#include"Number.h"
#include "DysOfYr.h"
#include"NumDays.h"
#include"NumDays2.h"
#include"TimeOff.h" 
#include"Month.h"

//Global Constants 

//Function Prototypes 
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
void problem10();


//Begin Execution Here!!!
int main(int argv,char *argc[]){
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        case 5:    problem5();break;
        case 6:    problem6();break;
        case 7:    problem7();break;
        case 8:    problem8();break;
        case 9:    problem9();break;
        case 10:    problem10();break;
        default:   def(inN);}
    }while(inN>=1&&inN<=10);
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"Menu for the Assignment 4"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type 3 for problem 7"<<endl;
    cout<<"Type 4 for problem 8"<<endl;
    cout<<"Type 5 for problem 9"<<endl;
    cout<<"Type 6 for problem 10"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}
//Gaddis_8th_Problem_13.1
void problem1(){
        cout<<"In problem # 1"<<endl<<endl;
        cout << "Gaddis_8th_Problem_13.1\n";
    Date theDate; //define class instant
    int theMonth= 0; // declare local variable
    int theDay=0;    // declare local variable
    int theYear=0;  // declare local variable
    
    //get user input
    cout << "This program will display the date in three different forms\n";
    cout << "________________________________________________________\n";
    cout <<"Please enter the day of the month: ";
    do{
      cout << "\nEnter a number between 1 and 31: ";
      cin >> theDay;
    }while(theDay < 1 || theDay > 31);
    cout << "Please enter the month in number form: ";
    do{
      cout << "\nEnter a number between 1 and 12: ";
      cin >> theMonth;
    }while(theMonth < 1 || theMonth > 12);
    
    cout << "Please enter all four digits of the year: ";
    do{
      cout << "\nEnter a for digit number: ";
      cin >> theYear;
    }while(theYear < 1000 || theYear > 9999);
    
    //store information back into class variables
    theDate.setDay(theDay);
    theDate.setYear(theYear);
    theDate.setMonth(theMonth);
       
    
    // call display function
    theDate.dsplDate();    
    cout << endl;
}
//Gaddis_8th_Problem_13.4
void problem2(){
        cout<<"In problem # 2"<<endl<<endl;
        cout << "Gaddis_8th_Problem_13.4\n";
    //declare local variables
    string name = " ";
    string address= " ";
    int age =0;
    int phnNum= 0;
    //define different instances
    Info personal;
    Info frend;
    Info famly;
    
    cout <<"This program obtains a specific user,the user's friend and a "
            "user's family member's personal information\n";
    cout << "_________________________________________________\n";
    // get users personal information, first instant
    cout << "Enter the following information about yourself: \n";
    cout << "Name:         ";
    cin.ignore();
    getline(cin, name); //obtain name
    personal.setName(name); //store in name object
    cout << "Address:      ";
    getline(cin, address);// obtain address
    personal.setAddress(address); //store in address object
    cout << "Age:          ";
    cin >> age;   // obtain age
    personal.setAge(age); // store in age object
    cout << "Phone Number: "; 
    cin >> phnNum;  //obtain phone number
    personal.setPhnNum(phnNum); // store in object
    cout << "_________________________________________________\n";
    //get second instant, information about user's friend
    cout << "Enter the following information about your friend:\n";
    cout << "Name:         ";
    cin.ignore();
    getline(cin, name); //obtain name
    frend.setName(name); //store in name object
    cout << "Address:      ";
    getline(cin, address);// obtain address
    frend.setAddress(address); //store in address object
    cout << "Age:          ";
    cin >> age;   // obtain age
    frend.setAge(age); // store in age object
    cout << "Phone Number: "; 
    cin >> phnNum;  //obtain phone number
    frend.setPhnNum(phnNum); // store in object
    cout << "_________________________________________________\n";
    //get third instant, information about user's family member
    cout << "Enter the following information about a family member:\n";
    cout << "Name:         ";
    cin.ignore();
    getline(cin, name); //obtain name
    famly.setName(name); //store in name object
    cout << "Address:      ";
    getline(cin, address);// obtain address
    famly.setAddress(address); //store in address object
    cout << "Age:          ";
    cin >> age;   // obtain age
    famly.setAge(age); // store in age object
    cout << "Phone Number: "; 
    cin >> phnNum;  //obtain phone number
    famly.setPhnNum(phnNum); // store in object
    cout << "_________________________________________________\n"; 
    cout << "********************************************\n";     
    
    cout << "Personal Informaiton:\n";
    cout << "Name:         ";
    cout << personal.getName(); //display name
    cout << endl;
    cout << "Address:      ";
    cout << personal.getAddress(); //display address object
    cout << endl;
    cout << "Age:          ";
    cout << personal.getAge(); //display age object
    cout << endl;
    cout << "Phone Number: "; 
    cout << personal.getPhnNum(); // display in object
    cout << endl;
    cout << "********************************************\n"; 
    
    cout << "User's Friend Informaion:\n";
    cout << "Name:         ";
    cout << frend.getName(); //display name
    cout << endl;
    cout << "Address:      ";
    cout << frend.getAddress(); //display address object
    cout << endl;
    cout << "Age:          ";
    cout << frend.getAge(); //display age object
    cout << endl;
    cout << "Phone Number: "; 
    cout << frend.getPhnNum(); // display in object
    cout << endl;    
    cout << "********************************************\n"; 
    cout << "User's Family Member Informaion:\n";
    cout << "Name:         ";
    cout << famly.getName(); //display name
    cout << endl;
    cout << "Address:      ";
    cout << famly.getAddress(); //display address object
    cout << endl;
    cout << "Age:          ";
    cout << famly.getAge(); //display age object
    cout << endl;
    cout << "Phone Number: "; 
    cout << famly.getPhnNum(); // display in object
    cout << endl;    
    
    cout << "********************************************\n";   
}
//Gaddis_8th_Problem_13.5
void problem3(){
        cout<<"In problem # 3"<<endl<<endl;
        cout << "Gaddis_8th_Problem_13.5\n";
        cout << "This program demonstrates constructors that with the following "
                "stored data\n";
        cout << "_____________________________\n";
        RetailItem item[3] = { 
            RetailItem("Jacket ", 12, 59.95), 
            RetailItem("Designer Jeans ", 40, 34.95),
            RetailItem("Shirt ", 20, 24.95)}; //initialize instances 

    cout << "\tDescription \t Units on Hand \t  Price\n";
    for(int i =0; i < 3; i++){
        //display stored information 
        cout << "Item " <<i+1<<": \n";
        cout << setw(20) << right << item[i].getDscrptn() << " \t\t ";
        cout  << item[i].getUnstOnHand() << "       "; 
        cout  << item[i].getPrice() << endl;
    }
}
//Gaddis_8th_Problem_13.6
void problem4(){
        cout<<"In problem # 4"<<endl<<endl;
        cout << "Gaddis_8th_Problem_13.6\n";
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
}
//Gaddis_8th_Problem_13.8
void problem5(){
        cout<<"In problem # 5"<<endl<<endl;
        cout << "Gaddis_8th_Problem_13.8\n";
    Circle crcle; //define class
    //declare variable
    float radius =0.0;  // radius of circle 
    
    cout << "This program asks the user for a radius and calculates its "
            "diameter, circumference and its area\n";
    cout << "________________________________________________________\n";
    cout << "Enter the following information: \n";
    do{
      cout << "Enter a positive number:\n";      
      cout << "Radius of circle:        ";
      cin >> radius; //obtain user input
    }while(radius < 0);
    crcle.setRadius(radius); //store in object 
    
    
    cout << "********************************************\n";    
    cout <<"Output:\n"; // display results
    cout << "Radius:        ";
    cout << crcle.getRadius();
    cout << endl;
    cout << "Diameter:      ";
    cout << crcle.getDmeter();
    cout << endl;  
    cout << "Area:          ";
    cout << crcle.getArea(); 
    cout << endl;
    cout << "Circumference: "; 
    cout << crcle.getCrcmfrence(); // display in object
    cout << endl;    
    
    cout << "********************************************\n"; 
}
//Gaddis_8th_Problem_14.1
void problem6(){
        cout<<"In problem # 6"<<endl<<endl;
        cout << "Gaddis_8th_Problem_14.1\n";
    Number num;
    int nums;
    
    cout << "This program takes a number and writes it in English form "
            "to demonstrate static strings\n";
    cout << "_________________________________\n";
    //user input
    do{
       cout <<"Enter the a number between 0 and 9999:\n";
       cin >> nums;   
    }while(nums < 0  ||  nums > 9999);
    num.Print(nums);
    
    cout << endl;
}
//Gaddis_8th_Problem_14.2
void problem7(){
        cout<<"In problem # 7"<<endl<<endl;
        cout << "Gaddis_8th_Problem_14.2\n";
        
    DysOfYr doy; //declare instance 
    int num=0;
    
    cout << "This program takes a number between 1 and 365 and tells the user"
            "what day of which month it is:\n";
    cout <<"This program assumes it is not a leap year\n";
    cout << "------------------------------------------\n";
    
    //user input
    do{        
        cout << "Enter a number between 1 and 365:\n";
        cin >> num;
    }while(num < 0 || num > 366);
    doy.Print(num); //print information stored
    
}
//Gaddis_8th_Problem_14.4
void problem8(){
        cout<<"In problem # 8"<<endl<<endl;
        cout << "Gaddis_8th_Problem_14.4\n";
        
    NumDays frst, scnd, cmbned, pstfx; //declare instances
    float hours;
    
    cout <<"This function takes the number of hours and converts them to days "
            "where 8 hours is 1 day\n";
    cout << "_____________________________________________\n";
    cout <<"Enter the following information\n";
    //obtain user input
    cout <<"Number of hours: 1:\n";
    do{
        cout <<"Enter a positive number\n";
        cin >> hours;
    }while(hours<0);
    frst.setHours(hours); //store in object
    //obtain user input
    cout <<"Number of hours: 2:\n";
    do{
        cout <<"Enter a positive number\n";
        cin >> hours;
    }while(hours<0);
    scnd.setHours(hours); //store in object
    
    cout << "Number of days: 1: ";
    cout << frst.getDays();
    cout << endl;
    cout << "Number of days: 2: ";
    cout << scnd.getDays();
    cout << endl;
    
    //assign first+second to combined
    cmbned = frst + scnd;
    //display
    cout << "Hours: 1+2: ";
    cout << cmbned.getHours();
    cout << endl;
    
    //assign first-second to combined
    cmbned = frst - scnd;
    //display
    cout << "Hours: 1-2: ";
    cout << cmbned.getHours();
    cout << endl;
    
    // prefix ++ operator
    cmbned = ++frst;
    pstfx = ++scnd;
    cout <<"\nPrefix operator ++ demonstration\n";
    cout << "Hours: 1: ";
    cout << frst.getHours() << endl;
    cout << "Days:  1: ";
    cout << frst.getDays() << endl;
    cout << "Hours: 2: ";
    cout << scnd.getHours() << endl;
    cout << "Days: 1:  ";
    cout << scnd.getDays() << endl << endl; 

   
    //postfix ++ operator
    cmbned = frst++;
    pstfx = scnd++;
    
    cout <<"Postfix operator ++ demonstration\n";
    cout << "Hours: 1: ";
    cout << frst.getHours() << endl;
    cout << "Days:  1: ";
    cout << frst.getDays() << endl;
    cout << "Hours: 2: ";
    cout << scnd.getHours() << endl;
    cout << "Days:  1: ";
    cout << scnd.getDays() << endl;    
    
    // prefix -- operator
    cmbned = --frst;
    pstfx = --scnd;
    
    cout <<"\nPrefix operator -- demonstration\n";
    cout << "Hours: 1: ";
    cout << frst.getHours() << endl;
    cout << "Days:  1: ";
    cout << frst.getDays() << endl;
    cout << "Hours: 2: ";
    cout << scnd.getHours() << endl;
    cout << "Days:  1: ";
    cout << scnd.getDays() << endl<< endl;  

    //postfix ++ operator
    cmbned = frst--;
    pstfx = scnd--;
    cout <<"Postfix operator -- demonstration\n";
    cout << "Hours: 1:  ";
    cout << frst.getHours() << endl;
    cout << "Days:  1:  ";
    cout << frst.getDays() << endl;
    cout << "Hours: 2:  ";
    cout << scnd.getHours() << endl;
    cout << "Days:  1:  ";
    cout << scnd.getDays() << endl;
        
}
//Gaddis_8th_Problem_14.5
void problem9(){
        cout<<"In problem # 9"<<endl<<endl;
        cout << "Gaddis_8th_Problem_14.5\n";
        
     //create timeoff instance
     TimeOff tmOf;
     //declare variables
    string emplName;  // employs name;
    int idnNum;  //employs identification number 
    // declared instances
    NumDays2 maxSckDys; // instance containing total sick days allowed
    NumDays2 sckTaken; // num of days of sick leave taken
    NumDays2 maxVction; //max num of paid vacation days allowed
    NumDays2 vacTkn;  // num of of paid vacation days taken
    NumDays2 maxUpd; // max number of unpaid vacation days allowed
    NumDays2 unpdTken; // num of unpaid vacation days taken
    
    
    cout << "This program demonstrates Aggregation,\n class containing another"
            "class instant.\n";
    cout << "------------------------------------\n";
    cout << "Input the number of hours for each of the instances below, 8 hours"
            " are equivalent to one day.\n";
    //user input
    cout <<"Enter the following information\n";
    cout << "Employ Name: ";
    cin.ignore();
    getline(cin,emplName);
    tmOf.setEmplName(emplName);
    cout << "Id Number:   ";
    cin >> idnNum;
    tmOf.setIdnNum(idnNum);
    
    //obtain hours for each instance.
    cout << "Number of sick leave days allowed: ";
    maxSckDys.usrInp();    
    cout << "Number of sick leaves taken by employee: ";
    sckTaken.usrInp();
    do{
        cout << "Number of paid vacation days allowed: ";
        cout << "\nMust be below 240: ";
        maxVction.usrInp();
    }while(maxVction.getHours() > 240);
    cout << "Number of paid vacations taken: ";
    vacTkn.usrInp();
    cout << "Number of unpaid vacations allowed: ";
    maxUpd.usrInp();
    cout << "Number of unpaid vacations taken: ";
    unpdTken.usrInp();
    cout << endl;
    
    //display information 
    cout << "________________________________\n";
    cout << "Employee information: \n";
    cout << "Name: " << emplName << endl;
    cout << "Id #: " << idnNum << endl;
    cout << "Sick leave days allowed: \n";
    maxSckDys.prnt();
    cout << "Sick leave days taken: \n";
    sckTaken.prnt();
    cout << "Paid vacations allowed: \n";
    maxVction.prnt();
    cout << "Paid vacations taken: \n";
    vacTkn.prnt();
    cout << "Unpaid vacations allowed: \n";
    maxUpd.prnt();
    cout << "Unpaid vacations taken: \n";
    unpdTken.prnt();
      
    cout << endl; 
}
//Gaddis_8th_Problem_14.7
void problem10(){
        cout<<"In problem # 10"<<endl<<endl;
        cout << "Gaddis_8th_Problem_14.7\n";
        
     int numM;
     string nme;
     Month cmbned, pstfx; //declare objects use to increment and 
                                        //decrement
     cout << "This program takes a number and converts it to the equivalent month"
             " and vise versa. Then it demonstrates increment and decrement "
             "functions\n";
     cout << "_____________________________________\n";
     cout << "Enter number of month: ";
     cin >> numM;
     
     Month mnt(numM);
     
     cout << mnt.getName() << endl;
     mnt++;
     cout << "Prefix ++ demonstration: ";
     cout << mnt.getName() << endl;
     ++mnt;
     cout << "Postfix ++ demonstration: ";
     cout << mnt.getName() << endl;    
     mnt--;
     cout << "Prefix -- demonstration: ";
     cout << mnt.getName() << endl;
     --mnt;
     cout << "Prefix -- demonstration: ";
     cout << mnt.getName() << endl;
     
    
     cout << "Enter the name of month (capital first letter): ";
     cin >> nme; 
     
     Month mnt2(nme);
     
     cout << mnt2.getNum() << endl;   
     mnt2++;
     cout << "Prefix ++ demonstration: ";
     cout << mnt2.getNum() << endl;
     ++mnt2;
     cout << "Postfix ++ demonstration: ";
     cout << mnt2.getNum() << endl;    
     mnt2--;
     cout << "Prefix -- demonstration: ";
     cout << mnt2.getNum() << endl;
     --mnt2;
     cout << "Prefix -- demonstration: ";
     cout << mnt2.getNum() << endl;
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

