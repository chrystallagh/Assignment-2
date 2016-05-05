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
    char color[8];
    int num;
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
void hints1();
void hints2();
void hints3();
int check(char[],int, char);
string aryToStr(char [],int);
string leader(); // returns string object in order to print name on leaderboard
void selectS(string[],int);
void bublSrt(int[],int);
//Execution Begins Here
int main(int argc, char** argv) {
    cout<<endl<<"Project 1"<<endl;
    cout<<endl<<"Mastermind: "<<endl<<endl <<"********************************\n";
    int numTrs=0; //number of times user has played
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare and initialize variables
    const int SIZE=4;  //Size of array 4 to will be generated    
    char color[SIZE];  //User Inputs
    string order[SIZE]={"first","second","third","fourth"}; //User Order Inputs
    char options[8]={'R','G','B','N','K','Y','O','W'};//Options for computer and user 
    char pick[SIZE]; //Computer generated random pick
    char hint;  //hint for the game
    int mxPlys; //user can input amount of attempts they want to play
    const char GMELMT=10; //Number limit which determines win or loss
    bool hintR=true; //exit hint when false
    int search; // checks if characters are valid 
    char end[SIZE][COLS]; //2D array to show final results
    vector<string>list; //vector which converts characters to one condensed string

    //Introduction to Game
    cout<<"Welcome to Mastermind."<<endl<<endl;
    cout << "This is how this game is played:\n";
    cout<<"   1. Pick four colors and press enter to continue."<<endl;
    cout<<"   2.If you can guess the colors in 10 tries or less, you win."<<endl;
    cout<<" -Order matters and you must guess not only the ";
    cout<<"colors   chosen,"<<endl<<" but the order as well";
    cout<<"(color spots). Each color can appear more than once"<<endl;
    cout<<" -The available colors are: red, green, blue, yellow, brown, orange,";
    cout<<" black, and white."<<endl;
    cout<<" -To choose your colors enter:\n red= r, green=g, blue=b, brown=n, black=k,";
    cout<<endl<<"yellow=y, orange=o, and white = w.\n -If you lose there is a bonus game."<<endl;

    cout << "________________________________________\n";
    //User Inputs Game Amount
    cout << "Enter:\n Amount of attempts: "<<endl;
    cin>>mxPlys;

    //Modify the limit of games based on how many it takes to win
    mxPlys=mxPlys<GMELMT?mxPlys:GMELMT;//Ternary Operator
    char *pointer;
    pointer = comGnrt(options);//function that picks random colors
    for(int i =0; i < 4; i++){ //write pointer information into array
        pick[i]=pointer[i];
    }
    wrteBinary(pick, SIZE); 
    for(int n=1;n<=mxPlys;n++){//play games as many times as user inputed
        input(color,order,4,pick,search,options);
        reppic(color,pick,numTrs,GMELMT,mxPlys,SIZE,list);
        numTrs++;
        if (numTrs<=GMELMT&&color[0]==pick[0]&&color[1]==pick[1]&&color[2]==pick[2]&&
                 color[3]==pick[3]){
            mxPlys=numTrs;
            cout<<"Your number of tries is "<<numTrs<<endl;
            results(color,pick,numTrs,GMELMT,mxPlys,SIZE,end,COLS);
            return 0;
        }
        switchH(color,pick,hintR,hint,numTrs,mxPlys);
    }
    results(color,pick,numTrs,GMELMT,mxPlys,SIZE,end,COLS);

    return 0;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                       Reads and writes into a file in biray                */
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
    char pick[4];
    for(int j=0;j<4;j++){
        do{
        int index=rand()%8;
        pick[j]=options[index];
        }while(pick[j+1]==pick[j]);
    } 
    return pick; //return array in the form of a pointer
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                       Input colors Function                                */
/******************************************************************************/
void input(char color[],string *order,const int SIZE,char pick[],int &search,
        char options[]){
    for (int i=0;i<SIZE;i++){
        do{
            cout<<"Enter the "<<*(order+i)<<" color: ";      
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
    cout<<"You've entered: ";
    for(int i=0;i<4;i++){
        cout<<color[i]<<" ";
    }cout<<endl;
    //Generate the table of choices
    list.push_back(aryToStr(color,SIZE));
    cout<<"Color Choices\tAttempt Number"<<endl;
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
    cout<<"Final Color Choices\tNumber of Attempts Listed For each Color"<<endl;
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
        game.name[0]=leader();
        cout<<"Top Ten on the Leaderboard "<<endl;
        for (int i=0;i<10;i++){
        cout<<i+1<<"       "<<game.name[i]<<endl;
    }
    }else{
        cout<<"You lose. You could not guess in 10 tries or less."<<endl;
         bonus();
    }
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                        Leader board Function                               */
/******************************************************************************/
string leader(){
    Game game;
    for (int i=0;i<1;i++){
        cout<<"Enter name to be added to a leader board "<<endl;
        cin.ignore();
        getline(cin,game.name[i]);
        return game.name[i]; 
      }  
}    
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                        Switch Hints Function                               */
/******************************************************************************/
void switchH(char color[],char pick[],bool hintR,char hint,int nTrys,int &limit){ 
    do{
        cout<< "*******************************\n"<<"For a hint type: "<<endl;
        cout<<" 1: to display how many colors are correct and in the right spot."<<endl;
        cout<<" 2: to display how many colors are correct."<<endl;
        cout<<"Type anything else if you don't want a hint ";
        cin>>hint;
        switch (hint){
            case 49:{ 
                cout << "\nHint: \n";
                //Two in the correct spot
                if (color[0]==pick[0]&&color[1]==pick[1]&&color[2]==pick[2]&&
                        color[3]==pick[3]){
                    nTrys=limit;
                    cout<<"You guessed all the colors correctly."<<endl;
                    hintR = false;
                    break;
                //Three in the correct spot
                }else if((color[0]==pick[0])&&(color[1]==pick[1])&&
                        (color[2]==pick[2])){
                    cout<<"3 correct colors, and they are correct in the right ";
                    cout<<"spot."<<endl<<endl;
                }else if((color[0]==pick[0])&&(color[1]==pick[1])&&
                        (color[3]==pick[3])){
                    cout<<"3 correct colors, and they are correct in the right ";
                    cout<<"spot."<<endl<<endl;
                }else if((color[3]==pick[3])&&(color[1]==pick[1])&&
                        (color[2]==pick[2])){
                    cout<<"3 correct colors, and they are correct in the right ";
                    cout<<"spot."<<endl<<endl;
                }else if((color[0]==pick[0])&&(color[3]==pick[3])&&
                        (color[2]==pick[2])){
                    cout<<"3 correct colors, and they are correct in the right ";
                    cout<<"spot."<<endl<<endl;
                }else if((color[0]==pick[0])&&(color[1]==pick[1])){
                    cout<<"2 correct colors, and in the correct ";
                    cout<<"spot."<<endl<<endl;
                }else if((color[0]==pick[0])&&(color[2]==pick[2])){
                    cout<<"2 correct colors, and in the correct ";
                    cout<<"spot."<<endl<<endl;
                }else if((color[0]==pick[0])&&(color[3]==pick[3])){
                    cout<<"2 correct colors, and in the correct";
                    cout<<"spot."<<endl<<endl;
                }else if((color[2]==pick[2])&&(color[1]==pick[1])){
                    cout<<"2 correct colors, and in the correct ";
                    cout<<"spot."<<endl<<endl;
                }else if((color[3]==pick[3])&&(color[1]==pick[1])){
                    cout<<"2 correct colors, and in the correct ";
                    cout<<"spot."<<endl<<endl;
                }else if((color[2]==pick[2])&&(color[3]==pick[3])){
                    cout<<"2 correct colors, and in the correct ";
                    cout<<"spot."<<endl<<endl;
                }else if ((color[0]==pick[0])||(color[1]==pick[1])||(color[2]==pick[2])||
                        (color[3]==pick[3])){
                    cout<<"1 correct colors, and in the correct "; 
                    cout<<"spot."<<endl<<endl;
                }else{
                    cout<<"None are in the right spot."<<endl;
                }
                case 50:{
                //Three of your color choices are correct
                if ((color[0]==pick[1]||color[0]==pick[2]||color[0]==pick[3])
                        &&(color[1]==pick[2]||color[1]==pick[3]||color[1]==pick[0])
                         &&(color[2]==pick[1]||color[2]==pick[3]||color[2]==pick[0])){
                    hints3();
                }else if ((color[0]==pick[1]||color[0]==pick[2]||color[0]==pick[3])
                        &&(color[1]==pick[2]||color[1]==pick[3]||color[1]==pick[0])
                         &&(color[3]==pick[1]||color[3]==pick[2]||color[3]==pick[0])){
                    hints3();
                }else if ((color[3]==pick[1]||color[3]==pick[2]||color[3]==pick[0])
                        &&(color[1]==pick[2]||color[1]==pick[3]||color[1]==pick[0])
                         &&(color[2]==pick[1]||color[2]==pick[3]||color[2]==pick[0])){
                    hints3();
                }else if ((color[0]==pick[1]||color[0]==pick[2]||color[0]==pick[3])
                        &&(color[3]==pick[2]||color[3]==pick[1]||color[3]==pick[0])
                         &&(color[2]==pick[1]||color[2]==pick[3]||color[2]==pick[0])){
                    hints3();
                } 
                //Two of your color choices are correct  
                else if ((color[0]==pick[1]||color[0]==pick[2]||color[0]==pick[3])
                        &&(color[1]==pick[2]||color[1]==pick[3]||color[1]==pick[0])){
                    hints2();
                }else if ((color[0]==pick[1]||color[0]==pick[2]||color[0]==pick[3])
                        &&(color[2]==pick[1]||color[2]==pick[3]||color[2]==pick[0])){
                    hints2();
                }else if ((color[0]==pick[1]||color[0]==pick[2]||color[0]==pick[3])
                        &&(color[3]==pick[2]||color[3]==pick[1]||color[3]==pick[0])){
                    hints2();
                }else if ((color[3]==pick[1]||color[3]==pick[2]||color[3]==pick[0])
                        &&(color[1]==pick[2]||color[1]==pick[3]||color[1]==pick[0])){
                    hints2();
                }else if ((color[2]==pick[1]||color[2]==pick[0]||color[2]==pick[3])
                        &&(color[1]==pick[2]||color[1]==pick[3]||color[1]==pick[0])){
                    hints2();
                }else if ((color[3]==pick[1]||color[3]==pick[2]||color[3]==pick[0])
                        &&(color[2]==pick[1]||color[2]==pick[3]||color[2]==pick[0])){
                    hints2();
                //One of your color choices is correct
                }else if (color[0]==pick[1]&&!(color[0]==pick[2]&&color[0]==pick[3]
                        &&color[1]==pick[0]&&color[1]==pick[2]&&color[1]==pick[3]&&
                        color[2]==pick[1]&&color[2]==pick[0]&&color[2]==pick[3]&&
                        color[3]==pick[1]&&color[3]==pick[2]&&color[3]==pick[0])){
                    hints1();
                }else if (color[0]==pick[2]&&!(color[0]==pick[1]&&color[0]==pick[3]
                        &&color[1]==pick[0]&&color[1]==pick[2]&&color[1]==pick[3]&&
                        color[2]==pick[1]&&color[2]==pick[0]&&color[2]==pick[3]&&
                        color[3]==pick[1]&&color[3]==pick[2]&&color[3]==pick[0])){
                    hints1();
                } else if(color[0]==pick[3]&&!(color[0]==pick[2]&&color[0]==pick[1]
                        &&color[1]==pick[0]&&color[1]==pick[2]&&color[1]==pick[3]&&
                        color[2]==pick[1]&&color[2]==pick[0]&&color[2]==pick[3]&&
                        color[3]==pick[1]&&color[3]==pick[2]&&color[3]==pick[0])){
                    hints1();
                }else if (color[1]==pick[0]&&!(color[0]==pick[2]&&color[0]==pick[3]
                        &&color[0]==pick[1]&&color[1]==pick[2]&&color[1]==pick[3]&&
                        color[2]==pick[1]&&color[2]==pick[0]&&color[2]==pick[3]&&
                        color[3]==pick[1]&&color[3]==pick[2]&&color[3]==pick[0])){
                    hints1();
                }else if(color[1]==pick[2]&&!(color[0]==pick[2]&&color[0]==pick[3]
                        &&color[1]==pick[0]&&color[0]==pick[1]&&color[1]==pick[3]&&
                        color[2]==pick[1]&&color[2]==pick[0]&&color[2]==pick[3]&&
                        color[3]==pick[1]&&color[3]==pick[2]&&color[3]==pick[0])){
                    hints1();
                }else if(color[1]==pick[3]&&!(color[0]==pick[2]&&color[0]==pick[3]
                        &&color[1]==pick[0]&&color[1]==pick[2]&&color[0]==pick[1]&&
                        color[2]==pick[1]&&color[2]==pick[0]&&color[2]==pick[3]&&
                        color[3]==pick[1]&&color[3]==pick[2]&&color[3]==pick[0])){
                    hints1();
                }else if (color[2]==pick[1]&&!(color[0]==pick[2]&&color[0]==pick[3]
                        &&color[1]==pick[0]&&color[1]==pick[2]&&color[1]==pick[3]&&
                        color[0]==pick[1]&&color[2]==pick[0]&&color[2]==pick[3]&&
                        color[3]==pick[1]&&color[3]==pick[2]&&color[3]==pick[0])){
                    hints1();
                }else if(color[2]==pick[0]&&!(color[0]==pick[2]&&color[0]==pick[3]
                        &&color[1]==pick[0]&&color[1]==pick[2]&&color[1]==pick[3]&&
                        color[2]==pick[1]&&color[0]==pick[1]&&color[2]==pick[3]&&
                        color[3]==pick[1]&&color[3]==pick[2]&&color[3]==pick[0])){
                    hints1();
                }else if(color[2]==pick[3]&&!(color[0]==pick[2]&&color[0]==pick[3]
                        &&color[1]==pick[0]&&color[1]==pick[2]&&color[1]==pick[3]&&
                        color[2]==pick[1]&&color[2]==pick[0]&&color[0]==pick[1]&&
                        color[3]==pick[1]&&color[3]==pick[2]&&color[3]==pick[0])){
                    hints1();
                }else if (color[3]==pick[1]&&!(color[0]==pick[2]&&color[0]==pick[3]
                        &&color[1]==pick[0]&&color[1]==pick[2]&&color[1]==pick[3]&&
                        color[2]==pick[1]&&color[2]==pick[0]&&color[2]==pick[3]&&
                        color[0]==pick[1]&&color[3]==pick[2]&&color[3]==pick[0])){
                    hints1();
                }else if(color[3]==pick[2]&&(!(color[0]==pick[2]&&color[0]==pick[3]
                        &&color[1]==pick[0]&&color[1]==pick[2]&&color[1]==pick[3]&&
                        color[2]==pick[1]&&color[2]==pick[0]&&color[2]==pick[3]&&
                        color[3]==pick[1]&&color[0]==pick[1]&&color[3]==pick[0]))){
                    hints1();
                }else if(color[3]==pick[0]&&!(color[0]==pick[2]&&color[0]==pick[3]
                        &&color[1]==pick[0]&&color[1]==pick[2]&&color[1]==pick[3]&&
                        color[2]==pick[1]&&color[2]==pick[0]&&color[2]==pick[3]&&
                        color[3]==pick[1]&&color[3]==pick[2]&&color[0]==pick[1])){
                    hints1();
                }else if(color[0]==pick[0]&&color[1]==pick[1]&&color[2]==pick[2]&&
                        color[3]==pick[3]){
                    cout<<"You guessed all the colors correctly."<<endl;
                    hintR = false;
                }else{
                    cout<<"None of these color choices are correct or in the  "; 
                    cout<<"right spot."<<endl<<"Try something different."<<endl
                                                                         <<endl;
                }
              break;  
            }
            default:{     
                cout<<"No hint: "<<endl<<endl;
                hintR=false;
            }
            }
        }
    }while(hintR);
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                               Hints Function                               */
/******************************************************************************/
void hints1(){
    cout<<"1 correct color, ";
    cout<<"however, it is not in the right spot."<<endl;
    cout<<"Change the order of which you ";
    cout<<"input this color to get it in the right spot."<<endl;
    cout<<endl<<endl;
}
void hints2(){
    cout<<"2 correct colors, ";
    cout<<"however, neither are in the right spot."<<endl;
    cout<<"Change the order of which you ";
    cout<<"input this color to get it in the right spot."<<endl;
    cout<<endl<<endl;
}
void hints3(){
    cout<<"3 correct colors, ";
    cout<<"however, none are not in the right spot."<<endl;
    cout<<"Change the order of which you ";
    cout<<"input this color to get it in the right spot."<<endl;
    cout<<endl<<endl;
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
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                      Bubble Sort
//Inputs:
//  a->Array or List
//  n->Size of List
//Outputs:
//  a->Sorted Array
//******************************************************************************
void bublSrt(int a[],int n){
    //Outside loop to test if any swaps happen
    bool swap;
    do{
        swap=false;
        //Inside List above the Element
        for(int j=0;j<n-1;j++){
            //Swap
            if(a[j]>a[j+1]){
                int temp =a[j];
                a[j]=a[j+1];
                a[j+1]=temp;//Exclusive or XOR a=b
                swap=true;
            }
        }
    }while(swap);
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
    cout << "Would you like to play?(Enter: y for yes n for no): ";
    cin >> ansr;
    
    if(ansr == 'y'){
        cout << "\nIn this part of the game you are allowed to enter how many"
                " colors will be generated, and you can also pick the colors"
                " that are allowed to be generated\n";
        cout << "-You must then guess in what sequence the colors were generated in\n";
        cout << "-This is a bonus game so you only get one chance\n";
        cout <<"_________________________________________\n";
        cout << "Enter how many numbers you would like to be generated and "
                "each of those numbers: \n";
        do{
            cout << "Please enter a number equal or smaller than 4 but larger than 1: ";
            cin >> size;
        }while(size > 4 || size < 2); 
        bnsGme.num = size; 
        cout << "Choose " << bnsGme.num << " colors by inputing:\n "
                "red=r, green=g, blue=b, brown=n,\n black=k, yellow=y, orange=o,"
                " and white = w.\n";
        for(int i =0; i < bnsGme.num; i++){
            cout<<"Please enter one of the above choices\n";
            cout << "Enter color number  " << i+1 << ": ";
            cin >> bnsGme.color[i];
        }
        bnsGnrt(bnsGme, size, pick); //function that generates random sequence
        int pos =0;
        cout << "\n\nNow guess the sequence,(remember that there can be repeating colors"
                "and that it is not necessary for the colors you selected to be present)\n";
        for(int i =0; i < bnsGme.num; i++){
            cout << "Enter a color: ";
            cin >> bnsGme2.color[i]; // user inputs color into stuct object
            cout << "Enter the position you believe it is in: ";
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
        }while(pick[j+1]==pick[j]);  
    }   
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                       Checks if user guessed the correct answer            */
/******************************************************************************/
void bnsAnser(int *options, char pick[], int size){
    cout << endl;
    if (size == 4){
        if((static_cast<char>(options[0])==pick[0])&&(static_cast<char>(options[1])
                ==pick[1])&&(static_cast<char>(options[2])==pick[2])&&(static_cast<char>(options[3])==pick[3])){
                    cout<<"Congratulations! You guessed all the colors correctly."<<endl;}
        else
            cout <<"you have guessed wrong, You lost!";   
    }
    if (size == 3){
        if((static_cast<char>(options[0])==pick[0])&&(static_cast<char>(options[1])
                ==pick[1])&&(static_cast<char>(options[2])==pick[2])){
                    cout<<"Congratulations! You guessed all the colors correctly."<<endl;}
        else 
            cout <<"you have guessed wrong, You lost!"; 
    }
    if (size == 2){
        if((static_cast<char>(options[0])==pick[0])&&(static_cast<char>(options[1])
                ==pick[1])){
                    cout<<"Congratulations! You guessed all the colors correctly."<<endl;}
        else 
            cout <<"you have guessed wrong, You lost!"; 
    }
    cout << "\nThe correct answers is: ";
    for(int i = 0; i < size; i++){
       cout << pick[i] << " ";
    }
 }