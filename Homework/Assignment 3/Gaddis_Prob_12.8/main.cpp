/*
 * 12.8
 * Write a function named arrayToFile. The function should accept three 
 * arguments: the name of a file, a pointer to an int array, and the size 
 * of the array. The function should open the specified file in binary mode, 
 * write the contents of the array to the file, and then close the file.
 * Write another function named fileToArray. This function should accept
 * three arguments: the name of a file, a pointer to an int array, and the 
 * size of the array. The function should open the specified file in binary 
 * mode, read its contents into the array, and then close the file.
 * Write a complete program that demonstrates these functions by using the 
 * arrayToFile function to write an array to a file, and then using the 
 * fileToArray function to read the data from the same file. After the data
 *  are read from the file into the array, display the array’s contents on 
 * the screen.
 */

/* 
 * File:   main.cpp
 * Author: chrystalla havadjia
 *
 * Created on April 4, 2016, 6:56 PM
 */

 //user library 
#include <iostream>
#include<fstream>
#include <ctime>
using namespace std;

// global constants

// function prototype
void arrayToFile(fstream &fileName, int * array, int size);
void fileToArray(fstream &fileName, int * array, int size);
void fillArray(int *a, int n);

//Execution begins here
int main() {
    unsigned seed = time(0);
    srand(seed);
    int size= 50;
    int array[size];
    fstream fileName;
    
    cout << "..This program copies the content of an array in binary form into "
            "a file and then reads the content of the file back into the array\n";
    cout << "_________________________________________\n";
    
    //call funtions
    fillArray(array,size);
    arrayToFile(fileName, array, size);
    fileToArray(fileName, array, size);
    
    
    return 0;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                            
//Inputs
//     n->Size of the array
//     a->Array
//     pass file by reference
////////////////////////////////////////////////////////////////////////////////
void arrayToFile(fstream &fileName, int * array, int size){
    

    fileName.open("Gaddis_12.8.txt", ios::out | ios::binary);
    // fileName.open("data.txt", ios::out | ios::binary);
    
    if(fileName){
      cout << "file opened"<< endl;
      cout << "Coping the content of an array to a file in binary" << endl;      
      fileName.write(reinterpret_cast<char *>(array),sizeof(array));
    }
    else
        cout << "failed to open file" << endl;
    
    // fileName<<"test";
    fileName.close();
    
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                             
//Inputs
//     n->Size of the array
//     a->Array
//     pass file by reference
////////////////////////////////////////////////////////////////////////////////
void fileToArray(fstream &fileName, int * array, int size){
    
    fileName.open("Gaddis_12.8.txt", ios::in | ios::binary);

    if(fileName){
       cout << "file opened"<< endl;
       cout << "Reading the contents of the file back into the array" << endl;    
       fileName.read(reinterpret_cast<char *>(array),sizeof(array));
      
    }
    else
        cout << "failed to open file" << endl;
    
    cout << "\nOutput stored inoframtion in array\n" << endl;
    for (int i=0; i < size; i++){
        cout << array[i] << " ";
        if(i%10==(10-1))cout<<endl;
    }
    
    fileName.close();
    
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                           
//Inputs
//     Size of the pointer
//     Pointer
//     pass file by reference
//Output
//     numbers randomly selected
////////////////////////////////////////////////////////////////////////////////
void fillArray(int *a, int n)
{       
    cout<< "The " << n << " numbers that were randomly selected for"
           " this array are: \n";

    for(int i=0;i<n;i++){
        *(a+i)=rand()%90+10;
    }
    int line = 10;
    
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<*(a+i)<<" ";
        if(i%line==(line-1))cout<<endl;
    }
    cout<<endl;
 
}


