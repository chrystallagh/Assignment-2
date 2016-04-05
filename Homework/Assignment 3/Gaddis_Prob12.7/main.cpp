/*
 * 12.7
 * Write a program that asks the user for two file names. The first file will be 
 * opened for input and the second file will be opened for output. (It will be 
 * assumed that the first file contains sentences that end with a period.) The
 * program will read the contents of the first file and change all the letters 
 * to lowercase except the first letter of each sentence, which should be made 
 * uppercase. The revised contents should be stored in the second file.
 */

/* 
 * File:   main.cpp
 * Author: chrystallahavadjia
 *
 * Created on April 3, 2016, 1:48 PM
 */

#include<iostream>
#include <fstream>
#include<string>
#include<cctype>

using namespace std;

 // global constants

// function prototype

int main()
{
    
    string fileName;
    string outputName;
    char ch[50];
    ifstream inputFile; 
    ofstream outFile;
   
    cout << "..This program changes all letters after a period to uppercase"
            << endl;
    cout << "--------------------------------------------------------"<< endl;
     //get user input for an input file name
    cout << "Enter a file name you would like to read from" << endl;
    getline(cin,fileName);
    inputFile.open(fileName.c_str());
     // get user input for an output file name
    cout << "Enter a file name you would like to save the revised"
                   "version " << endl;
    cin >> outputName;
    outFile.open(outputName.c_str());
    
    
    //make sure file opens
    if(inputFile)
    {
        //read a line up to 50 characters 
        
        inputFile.getline(ch,50);
       
        
        //continue obtaining input
        while(inputFile){
            ch[0]=toupper(ch[0]);
            
            for(int i=1; i <strlen(ch); i++){
                if(ch[i-1]=='.')ch[i]= toupper(ch[i]); 
                else
                    ch[i] =tolower(ch[i]);   
            }
            
            outFile<<ch;
            outFile<<endl;
 
            //continue obtaining input
            inputFile.getline(ch,50);     
        }
       //close files
        inputFile.close();
        outFile.close();
        cout << "Letter conversions are done" << endl;
    }
   // if file does not successfully open
    else {
        cout << "File opening failed" << endl;
        cout << fileName << endl << outputName << endl;
    }
   
    return 0;
}
