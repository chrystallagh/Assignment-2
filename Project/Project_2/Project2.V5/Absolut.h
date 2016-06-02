//Chrystalla Havadjia
//Class is used to return the absolute value of a valid user input using templates
#ifndef ABSOLUT_H
#define ABSOLUT_H

template <class T> //declare template 

class Absolut {
    private:
        T abst;
    public:
        Absolut(T a){ //default constructor
            abst = 0;
        }
        T setA(T a){
            abst = a; //sets value in variable
        }
        T getA() const{ // returns value
            return abst;
        }
        T FndAbs(){
            if(abst < 0)
                return -1*abst; // obtains 
            else 
                return abst;
        }        
};
#endif /* ABSOLUT_H */