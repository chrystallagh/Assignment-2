/* 
 * Find the media, mode and the mean of a list of numbers
 * The mode pointer sould display
 * [number of modes, frequency, mode 1, ... mode n]
 * 
 * File:   main.cpp
 * Author: CHrystalla Havadiia
 * Finding the mode of an array
 * Created on March 8, 2016, 3:05 PM
 */


/*Thought process: 
 * array  = {1,1,1,2,2,2,3,3}
 * mode array {2,3,1,2}
 * 1. max freq
 * 2. # has max freq
 * 3. record the numbers that have max freq
 */

 //system library 
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

 // global constants

// function prototype
float mean(int [],int);
float median(int [],int);
int *mode(int [], int);
void markSrt(int *a,int n);
void fillArray(int*, int);


int main() 
{
    srand(time(0));
    
    int size = 100;
    int *number;
    float getMedian = 0;
    float getMean = 0;
    
//    cout << "Input the amount of numbers you would"
//            " like to generate to find their mode:" << endl;
//    cin >> size; // determine size of array vie user input
    number = new int[size]; // dynamic allocation
    
    //call funtion fill array
    fillArray(number, size);
//    cout << "input:";
//    for(int i=0;i<size;i++)
//    {
//        cin>>number[i];
//    }
     
    // call function sorting
    markSrt(number, size);
    
    //call get mode function
    int *getMode = mode(number, size);    
    cout<<endl;
    
    if(getMode!=0){
       cout << "Returned mode: [number of modes, frequency, mode 1, ... mode n]"
                "" << endl;
         for (int i = 0; i< getMode[0]+2; i++){ 
          cout << getMode[i] << "\t";
         }
    }
    // call median function
    getMedian = median(number, size);
    cout <<"\nThis is the median \n";
    cout << getMedian;
    
    //call mean function
    getMean = mean(number, size);
    cout << "\nThe mean is \n";
    cout << getMean;
    
    //free memory
    delete []number;
    
    return 0;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                           
//Inputs
//     Size of the pointer
//     Pointer
//Output
//     numbers randomly selected
////////////////////////////////////////////////////////////////////////////////
void fillArray(int *a, int n)
{       
    cout<< "The " << n << " numbers that were randomly selected for"
           " this array are: \n";
//    for(int i=0;i<size;i++)
//    {  
//     number[i] = rand()%10; // randomly select numbers
//     cout << number[i] << "\t"; // display numbers
//        // int *mode = getMode(number, size);
//    }  
//    cout << endl;
    
    //Declare and allocate memory
    //int *a=new int[n];
    //Loop and fill with 2 digit numbers
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
    //return the pointer
    //return a;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                           
//Inputs
//     Size of the pointer
//     Pointer
//Output
//     a->The sorted pointer 
////////////////////////////////////////////////////////////////////////////////
void markSrt(int *value,int n)
{
    for (int pos = 0; pos< n-1; pos++){
        for ( int row= pos+1;row<n;row++){
            if (*(value+pos)>* (value+row)){
                *(value+pos)=* (value+pos)^*(value+row);
                *(value+row)=* (value+pos)^*(value+row);
                *(value+pos)=* (value+pos)^*(value+row);
            }
        }  
    }
    int line = 10;
    
    cout << "This is the list in ascending order" << endl;
    for (int i = 0; i < n; i++){
        cout << value[i] << " ";
        if(i%line==(line-1))cout<<endl;
    }
    cout<<endl;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                           
//Inputs
//     Size of the array
//     Array
//Output
//     a->Find the mode of the array return in a pointer
////////////////////////////////////////////////////////////////////////////////
int *mode(int number[], int size)
{   
    int counter = 1;
    int *mode; 
    int maxFreq = 0;
    int numMode = 0;
    
    //find max frequency
    for(int i=1;i<size;i++){
        if(number[i]==number[i-1]){
            counter++;
        }
        //i!=i-1
        else{
            //update max frequency
            if(counter>maxFreq){
                maxFreq=counter;
            }
            counter=1;
        }
    }
    if(counter>maxFreq)
        maxFreq=counter;
    
    counter = 1;
    
    //find # of elements that have same frequency
    for(int i=1;i<size;i++){
        if(number[i]==number[i-1]){
            counter++;
        }
  
        //i!=i-1
        else{
            //update max frequency
            if(counter==maxFreq){
                numMode++;
            }
            counter=1;
        }
    }
    if(counter==maxFreq)
        numMode++;
    
    
    // dynamic allocation
    mode = new int[numMode + 2];
    mode[0]=numMode;
    mode[1]=maxFreq;

   
    int temp=0;
    counter=1;
   
    //find all the numbers that are modes.
    for(int i=1;i<size;i++)
    {
        if(number[i]==number[i-1])
            counter++;
        
        //i!=i-1
        else{
            //update max frequency
            if(counter==maxFreq){
                mode[temp+2]=number[i-1];
                temp++;
            }
            counter=1;
        }
    }
    if(counter==maxFreq){
       mode[temp+2]=number[size-1];
    }
    
    // if there is no mode return 0 for numMode.
    if(maxFreq ==1)
        mode[0] = 0;
     
   delete []mode;
   
   return mode; 
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                           
//Inputs
//     Size of the array
//     Array
//Return
//     a->media value
////////////////////////////////////////////////////////////////////////////////
float median(int a[],int n){
    
    int median = a[n/2];
    
    if(n%2 == 0)
        median = a[(n/2)-1];

    return median;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                           
//Inputs
//     Size of the array
//     Array
//Return
//     a-> mean
////////////////////////////////////////////////////////////////////////////////
float mean(int a[],int n){
    float total = 0;
    float average = 0;
    
    for (int i =0; i <n ; i++){
        total += a[i];
    }
    average = total/n;
    
    return average;
}