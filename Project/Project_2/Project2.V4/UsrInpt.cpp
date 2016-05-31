 #include<iostream>
using namespace std;
#include "UsrInpt.h"

//definition of static variable
string UsrInpt::order[4]={"First","Second","Third","Fourth"};

//default constructor
UsrInpt::UsrInpt() {
    mxPlys=0;
    hint=0;
    pos=0;
    num=0;
}
//mutator functions
void UsrInpt::setMxPlys(int m){//assigns value to variable
    if (m>0)
        mxPlys = m; //assigns value to variable
    else
        throw ExptClass(); //demonstrates exceptions
}
void UsrInpt::setHint(int h){//assigns value to variable 
    if(h==1|| h==2 || h==0)
        hint = h;//assigns value to variable 
    else
        throw ExptClass(); // demonstrates exceptions
}
void UsrInpt::setPos(int p){//assigns value to variable
    if(p>0 && p<num+1)
        pos=p; //assigns value to variable
    else
        throw ExptClass(); //demonstrates exception
}
void UsrInpt::setNum(int n){//assigns value to variable
     num=n;
}
void UsrInpt::setAns(char a){//assigns value to variable
    if(a=='y'|| a=='n')
        ans=a; //assigns value to variable
    else
        throw ExptClass(); //demonstrates exception
}
//print function 
void UsrInpt::prntOrder(int j){
    for(int i=0;i<4;i++){
        if(i==j)
            cout << order[i];
    }    
}
//acessor functions
int UsrInpt::getMxPlys() const{
    return mxPlys; //returns value stored in member
}
int UsrInpt::getHint() const{
    return hint; //returns value stored in member 
}
int UsrInpt::getPos() const{
    return pos; //returns value stored in member
}
int UsrInpt::getNum() const{
    return num;//returns value stored in member
}
char UsrInpt::getAns() const{
    return ans;//returns value store in member
}
//overload postfix and prefix operators
UsrInpt UsrInpt::operator++(){
    ++mxPlys;
    getMxPlys();
    return *this;
}