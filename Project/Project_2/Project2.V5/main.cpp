//Chrystalla Havadjia
//Mastermind

//System Libraries
#include <iostream>
#include <string>  
#include <cstdlib>
#include <ctime> //seed to rendomly generate numbers 
#include <fstream> //File I/O
#include <iomanip> //Formatting
#include <vector>
using namespace std;
 
//User Libraries
#include"Hints.h"
#include"UsrInpt.h"
#include"Absolut.h"

struct BnsGame{
    char color[8]; // bonus questions, user enters which colors can be generated
    string name[10]; // if user wins they can input their name on a leader board
};

//Global Constant

//Function Prototypes
void bonus(); //bonus game
void bnsGnrt(struct BnsGame game, int size, char [], char); //bonus game answer generator 
void bnsAnser(int*, char [], int); //bonus game answers
void wrteBinary(char [], int); //write array in file in binary
char *comGnrt(char[],char);
void input(char[],const int,char[],int&,char[],UsrInpt,char);
Hints sHints(char[],char[],bool,int,int,int&);
void reppic(char[],char[],int&,const char,int&,const int,vector<string>&,Hints);
void results(char[],char[],int&,const char,int&,int);
int check(char[],int, char);
string aryToStr(char [],int);
bool checkAsn(char [], char [], bool); //check if all answers are correct in hints
BnsGame leader(); // returns string object in order to print name on leaderboard
char bnsVld(BnsGame,int); // bonus game, check if user has inputed the same color twice 
char gmeVld(char [],int , char [],int); //checks if user has inputed same color twice
int usePrf(UsrInpt); //increments times played 
void bInst();//displays instructions for bonus game
void gInst();//displays instuctions of the game
void Menu();//displays menu options
int getN();//obtains users input to determine menu option
void game();//function containing main game

//Execution Begins Here
int main(int argc, char** argv) {
    cout<<endl<<"Project 2"<<endl;
    cout<<endl<<"Mastermind: "<<endl;
    cout<<endl <<"  ********************************\n";
    
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //declare variables
    int sMenu;//menu display 
    
    //Game menu
    do{
        Menu();
        sMenu=getN();
        switch(sMenu){
            case 1:    game();break;
            case 2:    bonus();break;
            case 3:    return 0;break;
        }
    }while(sMenu>=1&&sMenu<=3);
    
    return 0;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                              Main game                                     */
/******************************************************************************/
void game(){
    //Declare and initialize variables
    int numTrs=0; //number of times user has played
    Hints ply; //define a class
    Hints ply1;//declare instance
    const int SIZE=4;  //Size of array 4 to will be generated    
    char color[SIZE];  //User Inputs
    char options[8]={'R','G','B','N','K','Y','O','W'};//Options for computer and user 
    char pick[SIZE]; //Computer generated random pick
    int hint;  //hint for the game user chooses which hint he/she wants
    int mxPlys; //user can input amount of attempts they want to play
    const char MXPLYS=10; //Number limit which determines win or loss
    bool hintR = true; //exit hint when false
    int search; // checks if characters are valid 
    int incr=1; //increments times played, must only allow user to play 1 more time.
    bool vldtin=true; //validation, flag to re-input information
    vector<string>list; //vector which converts characters to one condensed string
    char ansr;//stores users input of yes or no type

    cout << "\n Would you like the instructions of the game?\n";
    cout << "Enter y for yes or n for no: ";
    cin>> ansr;
    //demonstrates exceptions
    while(vldtin){ 
        try{
            //store value in object
            ply.setAns(ansr);
            //if valid entry set bool to false
            vldtin =false; 
        }
        catch(UsrInpt::ExptClass){
            cout << "Invalid entry. Enter y for yes or n for no: ";
            cin>>ansr;
        }
    } 
    if(ansr=='y')
       gInst();
    cout<<" - Enter:\n red=r    green=g \n blue=b   yellow=y \n brown=n  orange=o";
    cout<<" \n black=k  white=w.\n -If you lose there is a bonus game."<<endl;
    cout << "________________________________________________\n";
    //User Inputs Game Amount
    cout << "Enter:\n Amount of attempts: ";
    cin>>mxPlys; //obtain max plays
    vldtin=true; //set validation back to true before entering loop
    while(vldtin){ //demonstrates exceptions
        try{
            ply.setMxPlys(mxPlys); //store value in object
            vldtin = false;//if valid entry set bool to false
        }
        catch (UsrInpt::ExptClass){
            cout << "Invalid entry, enter a positive value larger than 0 for the"
                        " times allowed to play\n";
            cout << "\n Amount of attempts: ";
            cin>>mxPlys;
        }
    }
    // display object content
    cout << "  You have entered " << ply.getMxPlys()<< endl; 

    //Modify the limit of games based on how many it takes to win
    mxPlys=mxPlys<MXPLYS?mxPlys:MXPLYS;//Ternary Operator
    char *pointer;
    cout<<"\nDuplicates?\n(Enter: y for yes or n for no): ";
        cin>> ansr;
        //set validation back to true before entering loop
        vldtin=true; 
        while(vldtin){ //demonstrates exceptions
            try{
                ply.setAns(ansr);//store value in object
                vldtin =false; //if valid entry set bool to false
            }
            catch(UsrInpt::ExptClass){
                cout << "Invalid entry. Enter y for yes or n for no: ";
                cin>>ansr;
            }
        } 
    //function that picks random colors
    pointer = comGnrt(options, ansr);
    for(int i =0; i < 4; i++){ 
       //write pointer information into array
        pick[i]=pointer[i];
    }
    //store array in binary form
    wrteBinary(pick, SIZE); 
    //play games as many times as user inputed
    for(int n=1;n<=mxPlys;n++){
        input(color,4,pick,search,options,ply,ansr);
        numTrs++;
        if (numTrs<=MXPLYS&&color[0]==pick[0]&&color[1]==pick[1]&&color[2]==pick[2]&&
                 color[3]==pick[3]){
            mxPlys=numTrs;
            cout<<"Your number of tries is "<<numTrs<<endl;
            results(color,pick,numTrs,MXPLYS,mxPlys,SIZE);
            exit(0);
        }
        ply1=sHints(color,pick,hintR,hint,numTrs,mxPlys);  
        reppic(color,pick,numTrs,MXPLYS,mxPlys,SIZE,list,ply1);
        //only ask to increment allowed time to play once
        if(mxPlys==n && incr==1){ 
            hintR = checkAsn(color, pick, hintR);
            if(!hintR){
                cout << "You have guessed incorrectly\n";
                 mxPlys=usePrf(ply);//increments max amount allowed to play
            }
            else 
                cout << "You have guessed correctly\n";
            incr++;
        } 
    }
    results(color,pick,numTrs,MXPLYS,mxPlys,SIZE);
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                       Instructions of the game                             */
/******************************************************************************/
void Menu(){
    cout<<" \n  Welcome to Mastermind."<<endl<<endl;
    cout <<"        Menu"<<endl;
    cout<<"1. Play the game"<<endl;
    cout<<"2. Go straight to the bonus game"<<endl;
    cout<<"3. Exit \n"<<endl; 
} 
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                       Obtains user input on menu display                   */
/******************************************************************************/
int getN(){
    int sMenu;
    cin>>sMenu;
    return sMenu;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                       Instructions of the game                             */
/******************************************************************************/
void gInst(){
    //Introduction to Game
    cout << "\nThis is how this game is played:\n";
    cout<<"   1. Pick four colors and press enter to continue."<<endl;
    cout<<"   2. If you can guess the colors in 10 tries or less you win."<<endl;
    cout<<" - Order matters and you must guess not only the\ncolors chosen, "
            "but the order as well (color spots).";
    cout<<" \n - There are no duplicates"<<endl;
    cout<<" - The available colors are:\n red    green \n blue   yellow \n brown  orange";
    cout<<" \n black  white."<<endl; 
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                       Reads and writes into a file in binary               */
/******************************************************************************/
void wrteBinary(char *pick, int size){
    fstream file; //Used for file
    //write chosen computer char array in a file in binary from
    file.open("Mastermind.txt", ios::out | ios::binary);
    if(file)//Coping the content of an array to a file in binary    
       file.write(reinterpret_cast<char *>(pick),sizeof(pick));
    if(file)//Reading the contents of the file back into the array   
       file.read(reinterpret_cast<char *>(pick),sizeof(pick)); 
    //close file
    file.close();  
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                       Computer picks its colors                            */
/******************************************************************************/
//Computer Generated Pick of Colors User Tries to Guess
char *comGnrt(char options[],char ansr){
    char pick[4];
    
    for(int j=0;j<4;j++){
        do{
            int index=rand()%8;
            pick[j]=options[index];
            //if user dose not want duplicates
            if(ansr=='n'){
                for(int k=1; k<j+1; k++){//make sure there are no duplicate colors
                    while(pick[j-k]==options[index]){//if duplicate pick again
                        index=rand()%8;
                        pick[j]=options[index];
                        k=1;
                    }   
                }
            }
        }while(pick[j+1]==pick[j]); //cout << pick [j] << " ";// to check if game works
    } 
    //return array in the form of a pointer
    return pick; 
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                       Input colors Function                                */
/******************************************************************************/
void input(char color[],const int SIZE,char pick[],int &search,
        char options[], UsrInpt ply, char ansr){
    cout<<" \nEnter:\n red=r    green=g \n blue=b   yellow=y \n brown=n  orange=o";
    cout<<" \n black=k  white=w.\n";
    
    cout <<"\nEnter your color choices:\n";
     for (int i=0;i<SIZE;i++){
        do{
            ply.prntOrder(i);
            cout<< " color: ";      
            cin>>color[i];
            color[i]=toupper(color[i]);
            if(ansr=='n'){
                //function checks if user entered duplicates
                color[i] = gmeVld(color,i,options,search);
            }
            search=check(options,8,color[i]);
            if (search==-1){
                cout<<"Invalid entry. Enter from given choices."<<endl;
            }
        }while(search==-1);
    }  
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                      Representation of previous picks to user              */
/******************************************************************************/
void reppic(char color[],char pick[],int &nTrys,const char GMELMT,int &limit,
        const int SIZE,vector<string>&list, Hints ply){
    //User's Choices
    cout<<"\n  You've entered: ";
    for(int i=0;i<4;i++){
        cout<<color[i]<<" ";
    }
    cout<<endl<<endl;
    //Generate the table of choices
    list.push_back(aryToStr(color,SIZE));
    
    cout<<"Input  |    Attempt Number "<<endl;
    cout<<"------------------------------------"<<endl;
    for(int i=0;i<list.size();i++){
        cout<<list[i]<<"            "<<i+1 << "      ";
        if(i+1==list.size()&&ply.getHintD1()==false){
            for(int c=0;c<4;c++){//display correct location if user asked for hint1
                    if(color[c]==pick[c])
                        cout << ply.getHnt1() << " ";
                }
            }
        if(i+1==list.size()&&ply.getHintD2()==false){
            for(int j=0; j<4;j++){//check if they are the correct color
                for(int k=0;k<4;k++){
                    if(pick[j]==color[k])
                       cout << ply.getHnt2() << " ";     
                }             
            }
        }
        cout << endl;
    }
    cout << "\n-------------------------------------"<<endl;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                          Array to String                                   */
/******************************************************************************/
string aryToStr(char color[],int cSize){
    string str=" ";
    for(int i=0;i<cSize;i++){
        str+=color[i];
   }
   return str; 
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                        Results Output Function                             */
/******************************************************************************/
void results(char color[],char pick[],int &nTrys, const char GMELMT,int &limit,
        const int SIZE){
    BnsGame game;
    char cnvperc =100;
    //Reveals Computer's Choice Once User Guesses
    cout<<"\t******************";
    cout << "\n  Your final entry was: ";
    for(int i=0;i<SIZE;i++){
        cout<<color[i]<<" ";
    }
    cout<<endl; 
    cout << "\t________________________\n";
    cout<<"\n\tCorrect Answers : ";
    for (int j=0;j<SIZE;j++){
        cout << " " <<pick[j];  
    }
    cout << endl;
    if(nTrys<=GMELMT&&color[0]==pick[0]&&color[1]==pick[1]&&color[2]==pick[2]&&
            color[3]==pick[3]){
        //Percentage of times attempted in comparison to attempts allowed if won
        cout<<fixed<<setprecision(1);
        cout<<"\t\t*You win!*"<<endl;
        cout<<"Percentage of the board you got through:";
        cout<<(float)(nTrys)/static_cast<float>(limit)*cnvperc<<"% "<<endl;
        game=leader();
        cout<<"  Top Ten on the Leaderboard "<<endl;
        for (int i=0;i<10;i++){
        cout<<i+1<<"       "<<game.name[i]<<endl;
        }
    }else{
        cout<<"You lose. You could not guess in the tries entered."<<endl;
         bonus();
    }
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                        Leader board Function                               */
/******************************************************************************/
BnsGame leader(){
    BnsGame game;
    for (int i=0;i<1;i++){
        cout<<"Enter name to be added to a leaderboard: "<<endl;
        cin.ignore();
        getline(cin,game.name[i]); 
      }
    //return structure
    return game;  
}    
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                        Switch Hints Function                               */
/******************************************************************************/
Hints sHints(char color[],char pick[],bool hintR,int hint,int nTrys,int &limit){ 
    bool hintD1=true; // hint display, determines based on users input, which hints to be 
    bool hintD2=true; //displayed in later function
    Hints ply; //define class
    UsrInpt *ui = &ply; // used to demonstrate polymorphism 
    
    int incr=1; // hints will stop being displayed after two are given.
    if(nTrys!=limit){
        cout<< "___________________________________\n\n"<<"Hints: "<<endl;
        cout<<" 1: *: colors are correct and in the right spot."<<endl;
        cout<<" 2: #: colors are correct but not in correct spot."<<endl;
        cout<<"Type 0 for no hint: ";  
        cout << "  \n\t   ----------------- \n";

        cout << "\n\nHint:";
        cout << "\n____________________\n";
        do{
            cout <<"\nhint? ";
            cin>>hint; //obtain user input
            while(hintR){//use bool hintR to validate hint, flag to re input information
                try{
                   ui->setHint(hint);//store in object, demonstrates polymorphism 
                   ply.disHnt(); //display hint, demonstrates polymorphism
                   //if valid entry set bool to false
                    hintR = false;
                }
                catch(UsrInpt::ExptClass){
                    cout << "Invalid entry, please enter 1, 2 or 0 for hint\n";
                    cin>>hint;
                }
            }
            //set bool back to true for switch statement 
            hintR= true; 
            switch (hint){
                //checks if their are the correct color and in the correct location
                case 1:{ 
                    hintD1=false;//reassign hintD1, acts as flag
                    ply.setHntD1(hintD1);//store in object
                    if(checkAsn(color,  pick, hintR)){//if all correct end game 
                                             //and program didn't previously end
                      nTrys=limit;
                      hintR = false;
                      cout << "You got them all correct\n";
                      break;
                    }
                    cout << "Correct color and location: ";
                    //check if they are in correct location
                    for(int c=0;c<4;c++){
                        if(color[c]==pick[c])
                            cout << ply.getHnt1() << " ";
                    }
                    break;
                }
                cout <<endl;
                //check if they are the correct color
                case 2:{
                   hintD2=false;//reassign hintD2, acts as flag
                   ply.setHntD2(hintD2);//store in object
                   cout << "Correct color: ";
                    for(int j=0; j<4;j++){
                        for(int k=0;k<4;k++){
                            if(pick[j]==color[k])
                                cout << ply.getHnt2() << " ";     
                        }
                    }
                   break;
                }
                cout << endl;
                default:{     
                    cout<<"No hint "<<endl<<endl;
                    hintR=false;
                }
            } 
            incr++;
            //only allow user to have a maximum of 2 hints
            if(incr>2) 
                hintR=false;
            ply.setHntr(hintR);
        }while(ply.getHintR());
    }cout << endl;
    //returns information stored in class instance
    return ply;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*     Original game, checks if all answers inputed by user are correct       */
/******************************************************************************/
bool checkAsn(char color[4], char pick[4], bool hintR){
     //check if they all correct in correct location
     if(color[0]==pick[0]&&color[1]==pick[1]&&color[2]==pick[2]&&color[3]==
             pick[3]&&color[4]==pick[4])
         hintR=true;
     else
        hintR=false;
     return hintR;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                      Linear Search
//Inputs:
//  a->Array or List
//  n->Size of List
//  strt->Starting Position
//  val->Value to find
//Outputs:
//  pos->Index where value is found
//******************************************************************************
int check(char options[], int SIZE, char color){
    int i = 0;			
    int pos = -1; //Records position of search value		
    bool found = false;		
    while (i < SIZE && !found){
        if (options[i] == toupper(color)){
            found = true;
            pos = i;		  			
        }
        i++;
    }
    return pos;				
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                            Bonus game                                      */
/******************************************************************************/
void bonus(){
    //declared variables
    bool vl=true;//validation, flag to re-input information
    UsrInpt inpt; //declare an instance 
    int size; //size used to dynamically allocate
    Absolut <int>abs(size); //declares instance, demonstrates templates 
    char ansr; //allows user to enter yes or no 
    BnsGame bnsGme; // declare struct instance
    BnsGame bnsGme2; //declare struct instance 
    char pick[8];
    
    int *options;//Options for computer and user 
    
    options = new int[size];//dynamically allocate
    
    cout << "\n  ***************Bonus**************\n";
    cout << "\n Redeem yourself by playing a bonus game\n";
    cout << "Would you like to play?\n(Enter: y for yes or n for no): ";
    cin >> ansr;
    while(vl){ //demonstrates exceptions
        try{
            inpt.setAns(ansr);//store value in object
            vl =false; //if valid entry set bool to false
        }
        catch(UsrInpt::ExptClass){
            cout << "Invalid entry. Enter y for yes or n for no: ";
            cin>>ansr;
        }
    }
    if(ansr == 'y'){
        do{
            cout << "\nWould you like the instructions of the bonus game?\n";
            cout << "(Enter y for yes or n for no: ";
            cin>> ansr;
            vl=true; //set validation back to true before entering loop
            while(vl){ //demonstrates exceptions
                try{
                    inpt.setAns(ansr);//store value in object
                    vl =false; //if valid entry set bool to false
                }
                catch(UsrInpt::ExptClass){
                    cout << "Invalid entry. Enter y for yes or n for no: ";
                    cin>>ansr;
                }
            } 
            if(ansr=='y')
                bInst();
            cout << "\n  Must be equal or smaller than 8 but larger than 2:\n"
                    "(if negative value is entered, the absolute value will be used): ";
            cin >> size;
            abs.setA(size);
            size = abs.FndAbs(); // assign the absolute value of users input to size
        }while(size > 8 || size < 3); 
        inpt.setNum(size);
        cout << "  Choose " << inpt.getNum() << " colors:\n Enter:\n red=r    green=g"
                " \n blue=b   yellow=y \n brown=n  orange=o \n black=k  white=w.\n\n";
        for(int i =0; i < size; i++){
            do{
                inpt.prntOrder(i);
                cout<< " color: ";      
                cin>>bnsGme.color[i];
                bnsGme.color[i]=toupper(bnsGme.color[i]);
                bnsGme.color[i] = bnsVld(bnsGme,i);
            }while(bnsGme.color[i+1]==bnsGme.color[i]);
            while(bnsGme.color[i]!='R'&& bnsGme.color[i]!='G'&&bnsGme.color[i]!=
                    'B'&&bnsGme.color[i]!='Y'&&bnsGme.color[i]!='N'&&bnsGme.color[i]
                    !='O'&&bnsGme.color[i]!='K'&&bnsGme.color[i]!='W'){
                cout<<"  Please enter one of the above choices\n";
                inpt.prntOrder(i);
                cout<< " color: ";
                cin >> bnsGme.color[i];
                bnsGme.color[i]=toupper(bnsGme.color[i]);
            }
        }
        cout<<"\nDuplicates?\n(Enter: y for yes or n for no): ";
        cin>> ansr;
        //set validation back to true before entering loop
        vl=true; 
        while(vl){ //demonstrates exceptions
            try{
                inpt.setAns(ansr);//store value in object
                vl =false; //if valid entry set bool to false
            }
            catch(UsrInpt::ExptClass){
                cout << "Invalid entry. Enter y for yes or n for no: ";
                cin>>ansr;
            }
        }       
        //function that generates random sequence
        bnsGnrt(bnsGme, size, pick, ansr); 
        int pos = 0;
        cout << "\n\n Enter the color and its location\n";
        for(int i =0; i < size; i++){
            do{
                cout << "Color: " << i+1 << ": ";
                cin >> bnsGme2.color[i]; // user inputs color into stuct object
                bnsGme2.color[i]=toupper(bnsGme2.color[i]);
                if(ansr == 'n')
                    bnsGme2.color[i] = bnsVld(bnsGme2,i);
            }while(bnsGme.color[i+1]==bnsGme.color[i]);   
            cout << "Position: ";
            cin >> pos;
            //set validation back to true before entering loop
            vl=true; 
            while(vl){ //demonstrates exceptions
                try{
                    inpt.setPos(pos);//store value in object
                    vl =false; //if valid entry set bool to false
                }
                catch(UsrInpt::ExptClass){
                    cout << "Invalid entry. Enter a number between 0 and "<<size<<" : ";
                    cin>>pos;
                }
            }          
            // users input of position is stored in struct object
            options[inpt.getPos()-1]=bnsGme2.color[i];      
         }                                  
        cout << "  You have entered: ";
        for(int i =0; i < size; i++)
            cout << static_cast<char>(options[i]) << " ";  
        // function that checks if user enters correct sequence 
        bnsAnser(options, pick, size);  
    }
    delete []options; //free memory 
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                       Bonus game instructions                              */
/******************************************************************************/
void bInst(){
    cout << "\nIn this part of the game you are allowed to enter how many"
            " colors will be generated, and you can also pick the colors"
            " that are allowed to be generated\n";
    cout << " -You must then guess in what sequence the colors were generated in\n";
    cout << " -This is a bonus game so you only get one chance\n";
    cout <<"_________________________________________\n";
    cout << "\n Number of colors generated: \n";
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                       Computer picks its colors for bonus game             */
/******************************************************************************/
//Computer Generated Pick of Colors User Tries to Guess
void bnsGnrt(struct BnsGame game, int size, char pick[], char ansr){
    for(int j=0;j<size;j++){
        do{
            int index=rand()%size; 
            pick[j]=game.color[index];
            if(ansr=='n'){
                //make sure there are no duplicate colors
                for(int k=1; k<j+1; k++){
                    while(pick[j-k]==game.color[index]){//if duplicate pick again
                        index=rand()%size;
                        pick[j]=game.color[index];
                        pick[j]=toupper(pick[j]);
                        k=1;    
                    }   
                }//cout << pick[j] << " "; //check bonus answers
            }
        }while(pick[j+1]==pick[j]);  
    }      
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                       Checks if user guessed the correct answer            */
/******************************************************************************/
void bnsAnser(int *options, char pick[], int size){
    cout << endl<<endl; 
    if (size == 8){
        if((static_cast<char>(*(options+0))==pick[0])&&(static_cast<char>(*(options+1))
                ==pick[1])&&(static_cast<char>(*(options+2))==pick[2])&&(static_cast<char>(*(options+3))
                ==pick[3])&&(static_cast<char>(*(options+4))==pick[4])&&(static_cast<char>(*(options+5))
                ==pick[5])&&(static_cast<char>(*(options+6))==pick[6])&&(static_cast<char>(*(options+7))==pick[7])){
                    cout<<"Congratulations!You guessed all the colors correctly."<<endl;}
        else
            cout <<"You have guessed wrong, maybe next time";   
    }
    if (size == 7){
        if((static_cast<char>(*(options+0))==pick[0])&&(static_cast<char>(*(options+1))
                ==pick[1])&&(static_cast<char>(*(options+2))==pick[2])&&(static_cast<char>(*(options+3))
                ==pick[3])&&(static_cast<char>(*(options+4))==pick[4])&&(static_cast<char>(*(options+5))
                ==pick[5])&&(static_cast<char>(*(options+6))==pick[6])){
                    cout<<"Congratulations!You guessed all the colors correctly."<<endl;}
        else
            cout <<"You have guessed wrong, maybe next time";   
    }
    if (size == 6){
        if((static_cast<char>(*(options+0))==pick[0])&&(static_cast<char>(*(options+1))
                ==pick[1])&&(static_cast<char>(*(options+2))==pick[2])&&(static_cast<char>(*(options+3))
                ==pick[3])&&(static_cast<char>(*(options+4))==pick[4])&&(static_cast<char>(*(options+5))
                ==pick[5])){
                    cout<<"Congratulations!You guessed all the colors correctly."<<endl;}
        else
            cout <<"You have guessed wrong, maybe next time";   
    }
    if (size == 5){
        if((static_cast<char>(*(options+0))==pick[0])&&(static_cast<char>(*(options+1))
                ==pick[1])&&(static_cast<char>(*(options+2))==pick[2])&&(static_cast<char>(*(options+3))
                ==pick[3])&&(static_cast<char>(*(options+4))==pick[4])){
                    cout<<"Congratulations!You guessed all the colors correctly."<<endl;}
        else
            cout <<"You have guessed wrong, maybe next time";   
    }
    if (size == 4){
        if((static_cast<char>(*(options+0))==pick[0])&&(static_cast<char>(*(options+1))
                ==pick[1])&&(static_cast<char>(*(options+2))==pick[2])&&(static_cast<char>(*(options+3))==pick[3])){
                    cout<<"Congratulations!You guessed all the colors correctly."<<endl;}
        else
            cout <<"You have guessed wrong, maybe next time";   
    }
    if (size == 3){
        if((static_cast<char>(*(options+0))==pick[0])&&(static_cast<char>(*(options+1))
                ==pick[1])&&(static_cast<char>(*(options+2))==pick[2])){
                    cout<<"Congratulations!You guessed all the colors correctly."<<endl;}
        else 
            cout <<"You have guessed wrong, maybe next time"; 
    }
    cout << "\n \t\t*******\n  The correct answers was: ";
    for(int i = 0; i < size; i++){
       cout << pick[i] << " ";
    }
 }
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*             Bonus game, check if duplicates are entered by user            */
/******************************************************************************/
char bnsVld(BnsGame game,int k){
    // declare instance
    UsrInpt ply; 
    for(int j=1;j<k+1;j++){//make sure no duplicates are inputed by user
        while(game.color[k-j]==game.color[k]){
            cout << " -Please enter each color once\n ";
            ply.prntOrder(k);
            cout<< " color: "; 
            cin >> game.color[k];
            game.color[k]=toupper(game.color[k]);
            j=1;
        }
    }
    return game.color[k];
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*           Overloading operator, asks user to play one more time            */
/******************************************************************************/
int usePrf(UsrInpt gme){
    //declare new instance
    UsrInpt pstfx;  
    //validation, flag to re-input information
    bool vl=true;
    char ans;
    cout << "\nWould you like try one more time?\n ";
    cout<<"Enter y for yes or n for no: ";
    cin>>ans;
    while(vl){ //demonstrates exceptions
        try{
            pstfx.setAns(ans);//store value in object
            vl =false; //if valid entry set bool to false
        }
        catch(UsrInpt::ExptClass){
            cout << "Invalid entry. Enter y for yes or n for no: ";
            cin>>ans;
        }
    }
    if(pstfx.getAns()=='y'){
        pstfx=++gme; // prefix ++ operator
        cout << "\nYou have been given once more attempt to try and win\n";
        cout << "Play one more time: New game attempts allowed: ";
        cout << gme.getMxPlys()<< endl;
        return gme.getMxPlys();
    }
    else
        return gme.getMxPlys();
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*              check if duplicates are entered by user in first game         */
/******************************************************************************/
char gmeVld(char color[],int k, char options[], int search){
    //declare instance
    UsrInpt ply;
    for(int j=1;j<k+1;j++){
        //make sure no duplicates are inputed by user
        while(color[k-j]==color[k]){
            cout << " -Please enter each color once\n" ;
            ply.prntOrder(k);
            cout << " color: ";
            cin >> color[k];
            color[k]=toupper(color[k]);
            j=1;
        }
    }
    return color[k];
}