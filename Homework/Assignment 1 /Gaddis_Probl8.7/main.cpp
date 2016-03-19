/*
 * File:   newmain.cpp
 * Author: chrystallahavadjia
 * Purpose: array of names
 * 8.7
 */
//System Libraries
#include <iostream>
#include <cstring>
using namespace std;

//User Libraries

//Global Constants

//Functional Prototypes
void searchName(string[],int);
int nameOrder(string[],int,string);
string userInput();

//Execution Begins Here
int main(int argc, char** argv)
{

    //Determine and initialize the variables
    const int size=20;//Number allowed for array
    string names[size]=
    {"Collins,Bill", "Smith,Bart", "Allen,Jim", "Griffin,Jim", "Stamey,Marty",
     "Rose,Geri", "Taylor,Terri", "Johnson,Jill", "Allison,Jeff", "Looney,Joe",
     "Wolfe,Bill", "James,Jean", "Weaver,Jim", "Pore,Bob", "Rutherford,Greg", 
     "Javens,Renee", "Harrison,Rose", "Setzer,Cathy", "Pike,Gordon", "Holland,Beth"
    };
    
    string vaLue;//users unput
    int answer; 
    
    //call functions
    searchName(names,size);
    vaLue=userInput();
    answer=nameOrder(names,size,vaLue);
    
    //Output of results
    if(answer==-1)
    {
        cout<<"This name is not on our list."<<endl;
    }
    else   
    {
        cout<<names[answer]<<" is at "<<answer<<" place."<<endl;
    }
    cout<<endl<<endl;
}
// determins number of name, location of name in list
void searchName(string names[], int numName)
{
    //Determine and initialize the variables
    int i,find;
    string smallestVal;

    for(int find=0;find<(numName-1);find++)
    {
        i=find;
        smallestVal=names[i];
        for(int m =find+1; m <numName;m ++)
        {
            if (names[m]<smallestVal)
            {
                smallestVal=names[m];
                i=m;
            }  
        }
        string tem=names[find];
        names[find]=smallestVal;
        names[i]=tem;
    }
}
//obtain user input
string userInput()
{
    string name;
    cout << "What student are you searching for?"<<endl;
    getline(cin, name);
    return name;
}
// find the order of the names
int nameOrder(string names[], int size, string vaLue)
{
    //Declare and initialize variables
    int first=0, last=size-1, center, result=-1;			
    bool look=false;					
    while (!look && first<=last)
    {
        center=(first+last)/2;		
        if (names[center]==vaLue)			
        {
            look=true;
            result=center;
        }
        else if (names[center]>vaLue)
        {
            last=center-1;
        }
        else
        {
            first=center+1;
        }		
    }
    return result;
}