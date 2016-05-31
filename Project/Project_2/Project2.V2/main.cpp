//Chrystalla Havadjia
//Mastermind

//System Libraries
#include <iostream>
#include <string> 
#include <cstdlib>
#include <ctime> 
#include <fstream> //File I/O
#include <iomanip> //Formatting
#include <vector>
using namespace std;
 
//User Libraries
struct Game{
    char color[8]; // bonus questions, user enters which colors can be generated
    int num; // bonus question, user inputs how many colors to be generated
    string name[10]; // if user wins they can input their name on a leader board
};
//Global Constant
const int COLS=2;
//Function Prototypes
void bonus(); //bonus game
void bnsGnrt(struct Game game, int size, char []); //bonus game answer generator 
void bnsAnser(int*, char [], int); //bonus game answers
void wrteBinary(char [], int); //write array in file in binary
char *comGnrt(char[]);
void input(char[],string*,const int,char[],int&,char[]);
void switchH(char[],char[],bool,char,int,int&);
void reppic(char[],char[],int&,const char,int&,const int,vector<string>&);
void results(char[],char[],int&,const char,int&,int,char[][COLS],
        const int);
int check(char[],int, char);
string aryToStr(char [],int);
bool checkAsn(char [], char [], bool); //check if all answers are correct in hints
Game leader(); // returns string object in order to print name on leaderboard

//Execution Begins Here
int main(int argc, char** argv) {
    cout<<endl<<"Project 2"<<endl;
    cout<<endl<<"Mastermind: "<<endl<<endl <<"********************************\n";
    int numTrs=0; //number of times user has played
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare and initialize variables
    const int SIZE=4;  //Size of array 4 to will be generated    
    char color[SIZE];  //User Inputs
    string order[SIZE]={"First","Second","Third","Fourth"}; //User Order Inputs
    char options[8]={'R','G','B','N','K','Y','O','W'};//Options for computer and user 
    char pick[SIZE]; //Computer generated random pick
    char hint;  //hint for the game
    int mxPlys; //user can input amount of attempts they want to play
    const char MXPLYS=10; //Number limit which determines win or loss
    bool hintR=true; //exit hint when false
    int search; // checks if characters are valid 
    char end[SIZE][COLS]; //2D array to show final results
    vector<string>list; //vector which converts characters to one condensed string

    //Introduction to Game
    cout<<"Welcome to Mastermind."<<endl<<endl;
    cout << "This is how this game is played:\n";
    cout<<"   1. Pick four colors and press enter to continue."<<endl;
    cout<<"   2. If you can guess the colors in 10 tries or less you win."<<endl;
    cout<<" - Order matters and you must guess not only the\ncolors chosen, "
            "but the order as well";
    cout<<"(color spots). \n - There are no duplicates"<<endl;
    cout<<" - The available colors are:\n red    green \n blue   yellow \n brown  orange";
    cout<<" \n black  white."<<endl;
    cout<<" - Enter:\n red=r    green=g \n blue=b   yellow=y \n brown=n  orange=o";
    cout<<" \n black=k  white=w.\n -If you lose there is a bonus game."<<endl;

    cout << "________________________________________________\n";
    //User Inputs Game Amount
    cout << "Enter:\n Amount of attempts: "<<endl;
    cin>>mxPlys;

    //Modify the limit of games based on how many it takes to win
    mxPlys=mxPlys<MXPLYS?mxPlys:MXPLYS;//Ternary Operator
    char *pointer;
    pointer = comGnrt(options);//function that picks random colors
    for(int i =0; i < 4; i++){ //write pointer information into array
        pick[i]=pointer[i];
    }
    wrteBinary(pick, SIZE); 
    for(int n=1;n<=mxPlys;n++){//play games as many times as user inputed
        input(color,order,4,pick,search,options);
        reppic(color,pick,numTrs,MXPLYS,mxPlys,SIZE,list);
        numTrs++;
        if (numTrs<=MXPLYS&&color[0]==pick[0]&&color[1]==pick[1]&&color[2]==pick[2]&&
                 color[3]==pick[3]){
            mxPlys=numTrs;
            cout<<"Your number of tries is "<<numTrs<<endl;
            results(color,pick,numTrs,MXPLYS,mxPlys,SIZE,end,COLS);
            return 0;
        }
        switchH(color,pick,hintR,hint,numTrs,mxPlys);
    }
    results(color,pick,numTrs,MXPLYS,mxPlys,SIZE,end,COLS);

    return 0;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                       Reads and writes into a file in binary                */
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
char *comGnrt(char options[]){
    char pick[4];//you can add an option to make user pick weather they want
                 //duplicates see project
    for(int j=0;j<4;j++){
        do{
            int index=rand()%8;
            pick[j]=options[index];
            for(int k=1; k<j+1; k++){//make sure there are no duplicate colors
                while(pick[j-k]==options[index]){//if duplicate pick again
                    index=rand()%8;
                    pick[j]=options[index];
                    k=1;
                }   
            }
        }while(pick[j+1]==pick[j]);
     cout << pick [j] << " "; // to check if game works
    } 
    return pick; //return array in the form of a pointer
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                       Input colors Function                                */
/******************************************************************************/
void input(char color[],string *order,const int SIZE,char pick[],int &search,
        char options[]){
    cout <<"\nEnter your color choices:\n";
    for (int i=0;i<SIZE;i++){
        do{
            cout<<*(order+i) << " color: ";      
            cin>>color[i];
            color[i]=toupper(color[i]);
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
        const int SIZE,vector<string>&list){
    //User's Choices
//    cout<<"You've entered: ";
//    for(int i=0;i<4;i++){
//        cout<<color[i]<<" ";
//    }
    cout<<endl;
    //Generate the table of choices
    list.push_back(aryToStr(color,SIZE));
    cout<<"User Input\tAttempt Number"<<endl;
    cout<<"----------------------------"<<endl;
    for(int i=0;i<list.size();i++){
        cout<<list[i]<<"               "<<i+1<<endl;
    }      
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
void results(char color[],char pick[],int &nTrys,
        const char GMELMT,int &limit,const int SIZE,char end[][COLS],const int COLS){
    Game game;
    char cnvperc =100;
    //Reveals Computer's Choice Once User Guesses
    cout<<"Your colors are ";
    for(int i=0;i<SIZE;i++){
        cout<<color[i]<<" ";
    }cout<<endl; 
    cout<<"Color Choices\tNumber of Attempts Listed For each Color"<<endl;
    for (int j=0;j<SIZE;j++){
        cout<<color[j];
        int i=nTrys;
        cout<<end[color[j]][COLS];
        cout<<"                                     "<<i;
        cout<<endl;
    }
    if(nTrys<=GMELMT&&color[0]==pick[0]&&color[1]==pick[1]&&
    color[2]==pick[2]&&color[3]==pick[3]){
        //Tries Percentage if won
        cout<<fixed<<setprecision(1);
        cout<<"You win!"<<endl;
        cout<<"Percentage of the board you got through: ";
        cout<<(float)(nTrys)/(10.0f)*cnvperc<<"% "<<endl;
        game=leader();
        cout<<"Top Ten on the Leaderboard "<<endl;
        for (int i=0;i<10;i++){
        cout<<i+1<<"       "<<game.name[i]<<endl;
    }
    }else{
        cout<<"You lose. You could not guess in the tries allowd."<<endl;
         bonus();
    }
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                        Leader board Function                               */
/******************************************************************************/
Game leader(){
    Game game;
    for (int i=0;i<1;i++){
        cout<<"Enter name to be added to a leader board "<<endl;
        cin.ignore();
        getline(cin,game.name[i]);
        return game; //return structure variable
      }  
}    
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                        Switch Hints Function                               */
/******************************************************************************/
void switchH(char color[],char pick[],bool hintR,char hint,int nTrys,int &limit){ 
    char hnt1='*'; // if correct color and right spot
    char hnt2='#';// if correct color but not correct spot
    if(nTrys!=limit){
        cout<< "___________________________________\n\n"<<"Hints: "<<endl;
        cout<<" 1: * if colors are correct and in the right spot."<<endl;
        cout<<" 2: # if colors are correct but not in correct spot."<<endl;
        cout<<"Type anything else if you don't want a hint: ";  

        cout << "\n\nHint:\n____________________\n";
        do{
            cout <<"\nhint? ";
            cin>>hint;
            switch (hint){
                case '1':{ 
                    if(checkAsn(color,  pick, hintR)){
                    // if( arrEq(color,pick))
                    //if all correct end game
                      nTrys=limit;
                      hintR = false;
                      cout << "You got them all correct\n";
                      break;
                    }
                    cout << "Correct color and location: ";
                    for(int c=0;c<4;c++){//check if they are in correct location
                        if(color[c]==pick[c])
                            cout << hnt1 << " ";
                    }break;
                }cout <<endl;
                case '2':{//check if they are the correct color
                   cout << "Correct color, but not location: ";
                    for(int j=0; j<4;j++){
                        for(int k=0;k<j+1;k++){
                            if(pick[j]==color[k]){
                                cout << hnt2 << " "; }     
                        }
                    }break;
                }cout << endl;
                default:{     
                    cout<<"No hint "<<endl<<endl;
                    hintR=false;
                }
            } 
        }while(hintR);
    }
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
void bonus(){
        //declared variables
    int size; //size used to dynamically allocate
    char ansr; //input user to play bonus  
    Game bnsGme; // declare struct instance
    Game bnsGme2; //declare struct instance 
    char pick[8];
    
    int *options;//Options for computer and user 
    
    options = new int[size];//dynamically allocate
    
    cout << "\n***************Bonus**************\nRedeem yourself by playing a bonus game\n";
    cout << "Would you like to play?\n(Enter: y for yes ): ";
    cin >> ansr;
    
    if(ansr == 'y'){
        cout << "\nIn this part of the game you are allowed to enter how many"
                " colors will be generated, and you can also pick the colors"
                " that are allowed to be generated\n";
        cout << "-You must then guess in what sequence the colors were generated in\n";
        cout << "-This is a bonus game so you only get one chance\n";
        cout <<"_________________________________________\n";
        cout << "Number of colors generated: \n";
        do{
            cout << "Must be equal or smaller than 8 but larger than 2: ";
            cin >> size;
        }while(size > 8 || size < 3); 
        bnsGme.num = size; 
        cout << "Choose " << bnsGme.num << " colors:\n Enter:\n red=r    green=g \n blue=b   yellow=y \n brown=n  orange=o \n black=k  white=w.\n";
        for(int i =0; i < bnsGme.num; i++){
            cout << " Color " << i+1 << ": ";
            cin >> bnsGme.color[i];
            while(bnsGme.color[i]!='r'&& bnsGme.color[i]!='g'&&bnsGme.color[i]!='b'&&bnsGme.color[i]!='y'&&bnsGme.color[i]!='n'&&bnsGme.color[i]!='o'&&bnsGme.color[i]!='k'&&bnsGme.color[i]!='w'){
                cout<<"Please enter one of the above choices\n";
                cout << " Color " << i+1 << ": ";
                cin >> bnsGme.color[i];
            }
        }
        bnsGnrt(bnsGme, size, pick); //function that generates random sequence
        int pos =0;
        cout << "\n\nNow guess the sequence, and location(there are no duplicates)\n";
        for(int i =0; i < bnsGme.num; i++){
            cout << "Color: " << i+1 << ": ";
            cin >> bnsGme2.color[i]; // user inputs color into stuct object
            cout << "Position: ";
            cin >> pos;
            options[pos-1]=bnsGme2.color[i]; // users input of positin is stored 
        }                                 //in struct object
        cout << "You have entered: ";
        for(int i =0; i < bnsGme.num; i++)
            cout << static_cast<char>(options[i]) << " ";  
        bnsAnser(options, pick, size);  // function that checks if user enters correct sequence 
    }
    
    delete []options;  //free memory 
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                       Computer picks its colors for bonus game             */
/******************************************************************************/
//Computer Generated Pick of Colors User Tries to Guess
void bnsGnrt(struct Game game, int size, char pick[]){
    for(int j=0;j<size;j++){
        do{
            int index=rand()%5; 
            pick[j]=game.color[index];
            for(int k=1; k<j+1; k++){//make sure there are no duplicate colors
                while(pick[j-k]==game.color[index]){//if duplicate pick again
                    index=rand()%8;
                    pick[j]=game.color[index];
                    k=1;    
                }   
            }cout << pick[j] << " ";
        }while(pick[j+1]==pick[j]);  
    }      
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                       Checks if user guessed the correct answer            */
/******************************************************************************/
void bnsAnser(int *options, char pick[], int size){
    cout << endl; 
      
    if (size == 8){
        if((static_cast<char>(options[0])==pick[0])&&(static_cast<char>(options[1])
                ==pick[1])&&(static_cast<char>(options[2])==pick[2])&&(static_cast<char>(options[3])==pick[3])&&(static_cast<char>(options[4])==pick[4])&&(static_cast<char>(options[5])
                ==pick[5])&&(static_cast<char>(options[6])==pick[6])&&(static_cast<char>(options[7])==pick[7])){
                    cout<<"Congratulations! You guessed all the colors correctly."<<endl;}
        else
            cout <<"You have guessed wrong, maybe next time";   
    }
    if (size == 7){
        if((static_cast<char>(options[0])==pick[0])&&(static_cast<char>(options[1])
                ==pick[1])&&(static_cast<char>(options[2])==pick[2])&&(static_cast<char>(options[3])==pick[3])&&(static_cast<char>(options[4])==pick[4])&&(static_cast<char>(options[5])
                ==pick[5])&&(static_cast<char>(options[6])==pick[6])){
                    cout<<"Congratulations! You guessed all the colors correctly."<<endl;}
        else
            cout <<"you have guessed wrong, maybe next time";   
    }
    if (size == 6){
        if((static_cast<char>(options[0])==pick[0])&&(static_cast<char>(options[1])
                ==pick[1])&&(static_cast<char>(options[2])==pick[2])&&(static_cast<char>(options[3])==pick[3])&&(static_cast<char>(options[4])==pick[4])&&(static_cast<char>(options[5])
                ==pick[5])){
                    cout<<"Congratulations! You guessed all the colors correctly."<<endl;}
        else
            cout <<"you have guessed wrong, maybe next time";   
    }
    if (size == 5){
        if((static_cast<char>(options[0])==pick[0])&&(static_cast<char>(options[1])
                ==pick[1])&&(static_cast<char>(options[2])==pick[2])&&(static_cast<char>(options[3])==pick[3])&&(static_cast<char>(options[4])==pick[4])){
                    cout<<"Congratulations! You guessed all the colors correctly."<<endl;}
        else
            cout <<"you have guessed wrong, maybe next time";   
    }
    if (size == 4){
        if((static_cast<char>(options[0])==pick[0])&&(static_cast<char>(options[1])
                ==pick[1])&&(static_cast<char>(options[2])==pick[2])&&(static_cast<char>(options[3])==pick[3])){
                    cout<<"Congratulations! You guessed all the colors correctly."<<endl;}
        else
            cout <<"you have guessed wrong, maybe next time";   
    }
    if (size == 3){
        if((static_cast<char>(options[0])==pick[0])&&(static_cast<char>(options[1])
                ==pick[1])&&(static_cast<char>(options[2])==pick[2])){
                    cout<<"Congratulations! You guessed all the colors correctly."<<endl;}
        else 
            cout <<"you have guessed wrong, maybe next time"; 
    }
    cout << "\nThe correct answers is: ";
    for(int i = 0; i < size; i++){
       cout << pick[i] << " ";
    }
 }
bool checkAsn(char color[4], char pick[4], bool hintR){
     for(int c=0;c<4;c++){//check if they all correct in correct location
         if(color[c]==pick[c])
             hintR=true;
         else 
             hintR=false;
     }
     return hintR;
}
                        