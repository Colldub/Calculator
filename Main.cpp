/*
    Calculator Assignment CS 121
    Main file

    Collin Worth 10-15-2023

*/
#include "Stack.h"
#include <iostream>
using namespace std;

//prototypes
void PushAndSend(Stack&);
void OperateFunc(Stack&, string);

int main(){

    Stack s;

    do{
        s.exit = false;

        PushAndSend(s);
        s.DisplayTop();

    }while(s.exit == false);

    s.Delete();
    return 0;
}

void PushAndSend(Stack& s){ //asks for a cin, pushes any doubles onto the stack and performs any operations found 
    string input;                  // from one line in order that they appear
    char temp;
    char cVal;
    double dVal;
    string cString;
    
    getline(cin, input);
    input += " ~";

    for(char c : input){

        if(isspace(c)){

            if(isdigit(cString[0])){
                dVal = stod(cString);
                s.push(dVal);
                cString.clear();
            }else if(cString == "~"){
                return;
            }else{
                OperateFunc(s, cString);
                cString.clear();
            }
        }else{
            cString += c;
        }
    }
}


void OperateFunc(Stack& s, string str) { //takes in a string for the operation to compleate, 
                                                //and then uses the stack to perform operation
                                                    
                                                                    //functions that dont need poped vals
        /////////////////////////////////////////////////////////////////////////////
        if(str == "quit"){
            s.exit = true;

        }else if(str == "ps"){
            s.Print();
        }                                                             //functions that require poped vals  
        //////////////////////////////////////////////////////////////////////////////
        double val1;
        double val2;

        if(str == "swap"){
            val1 = s.pop();
            val2 = s.pop();
            s.push(val1);
            s.push(val2);
        
        }else if(str == "sq"){
            val1 = s.pop();
            s.push(val1 * val1);

        }else if(str == "sqrt"){
            val1 = s.pop();
            s.push(sqrt(val1));

        }else if(str == "dup"){
            val1 = s.pop();
            s.push(val1);
            s.push(val1);

        }else if(str == "/"){
            val1 = s.pop();
            val2 = s.pop();
                s.push(val2/val1);

        }else if(str == "-"){
            val1 = s.pop();
            val2 = s.pop();
                s.push(val2 - val1);

        }else if(str == "+"){
            val1 = s.pop();
            val2 = s.pop();
                s.push(val1 + val2);

        }else if(str == "*"){
            val1 = s.pop();
            val2 = s.pop();
                s.push(val1 * val2);
        }
}