/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Number.cpp
 * Author: chrystallahavadjia
 * 
 * Created on April 29, 2016, 3:29 PM
 */
#include<iostream>
#include<string>

using namespace std;

#include "Number.h"

Number::Number() {
    num = 0;  
}
//definition of static member
string Number::lessThan10[10] = {"Zero ", "One ", "Two ","Three ","Four ","Five ",
    "Six ","Seven ","Eight ","Nine "}; 

void Number::Print(int p) {
    num = p;
    // declared variables
     unsigned char n10000s, n1000s,n100s,n10s,n1s; //used to concert from 
                                        //numeric to english form on numbers
    //Conver to words
    //Calculate the number of 1000's,100's,10's,1's
    n10000s=(num-num%10000)/10000; //Number of 10000's
    num=(num-n10000s*10000);        //Subtract 10000's
    n1000s=(num-num%1000)/1000; //Number of 1000's
    num=(num-n1000s*1000);     //Subtract off 1000's
    n100s =(num-num%100)/100;  //Number of 100's
    num=(num-n100s*100);       //Subtract off 100's
    n10s  =(num-num%10)/10;  //Number of 10's 
    n1s   =(num-n10s*10);         //Subtract off 10's to get 1's
    
    
      //Output the 1000's  
      switch(n1000s){
        case 9:  cout<<"Nine Thousand ";break; 
        case 8:  cout<<"Eight Thousand ";break;
        case 7:  cout<<"Seven Thousand ";break;
        case 6:  cout<<"Six Thousand ";break;
        case 5:  cout<<"Five Thousand ";break;
        case 4:  cout<<"Four Thousand ";break;
        case 3:  cout<<"Three Thousand ";break;
        case 2:  cout<<"Two Thousand ";break;
        case 1:  cout<<"One Thousand ";break;
    }
      //Output the 100's             
    switch(n100s){
        case 9:  cout<<"Nine Hundred ";break; 
        case 8:  cout<<"Eight Hundred ";break;
        case 7:  cout<<"Seven Hundred ";break;
        case 6:  cout<<"Six Hundred ";break;
        case 5:  cout<<"Five Hundred ";break;
        case 4:  cout<<"Four Hundred ";break;
        case 3:  cout<<"Three Hundred ";break;
        case 2:  cout<<"Two Hundred ";break;
        case 1:  cout<<"One Hundred ";break;
    }

    //Output the 10's
    switch(n10s){
        case 9:  cout<<"Ninety ";break;
        case 8:  cout<<"Eighty ";break;
        case 7:  cout<<"Seventy ";break;
        case 6:  cout<<"Sixty ";break;
        case 5:  cout<<"Fifty ";break;
        case 4:  cout<<"Forty ";break;
        case 3:  cout<<"Thirty ";break;
        case 2:  cout<<"Twenty ";break;
        case 1:  {   if (n1s ==0){cout<<"Ten ";break;}       
                     if (n1s == 9){cout<<"Nineteen ";break;}
                     if (n1s == 8){cout<<"Eighteen ";break;}
                     if (n1s == 7){cout<<"Seventeen ";break;}
                     if (n1s == 6){cout<<"Sixteen ";break;}
                     if (n1s == 5){cout<<"Fifteen ";break;}
                     if (n1s == 4){cout<<"Fourteen ";break;}
                     if (n1s == 3){cout<<"Thirteen ";break;}
                     if (n1s == 2){cout<<"Twelve ";break;}
                     if (n1s == 1){cout<<"Eleven ";break;}
                }
    }
    
    //Output the 1's
    if(n10s!=1){
        for(int i = 0; i < 10; i++){
            if(n1s == i){   
                if(n10s == 1 && n1s == 1 || n10s == 1 && n1s == 2)
                    cout << "";
                else cout << lessThan10[i];           
            }
        }
    }
    
    cout << "Dollars" << endl;

}




