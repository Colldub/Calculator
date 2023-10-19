/*
    Calculator Assignment CS 121
    Class file

    Collin Worth 10-15-2023

*/
#include "Stack.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

Stack::Stack(){ //constructor
    top = NULL;
}

Stack::~Stack(){ //deconstructor

}

double Stack::pop(){ //returns top value of stack and removes it from stack

    if(top == NULL){
        return 0;
    }else{
        double ret = 0.0;
        //disconect
        Node* temp = new Node;
        temp = top;
        top = top->next;
        //store
        ret = temp->data;
        //delete
        delete temp;
        //return
        return ret;
    }
}

void Stack::push(double val){ //takes a val and inserts it onto the stack

    Node* ptr = new Node;
    ptr->data = val;
    ptr->next = top;
    top = ptr;
}

double Stack::peek(){ //returns top value of stack
    if(top == NULL){
        return 0;
    }else{
        return top->data;
    }
}

void Stack::DisplayTop(){ //prints out the top of the stack along with a '>'
    if(top != NULL){
        cout << "RPN " << top->data << " > ";
    }else{
        return;
    }
}

void Stack::PushAndSend(Stack& s){ //asks for a cin, pushes any doubles onto the stack and performs any operations found 
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
                s.OperateFunc(s, cString);
                cString.clear();
            }
        }else{
            cString += c;
        }
    }
}

void Stack::OperateFunc(Stack& s, string str) { //takes in a string for the operation to compleate, 
                                                //and then uses the stack to perform operation
                                                    
                                                                    //functions that dont need poped vals
        /////////////////////////////////////////////////////////////////////////////
        if(str == "quit"){
            s.exit = true;

        }else if(str == "ps"){
            Node* tempPtr = new Node;
            tempPtr = top; //saves position of top for later

            cout << "Stack Contents: ";

            while(top != NULL){
                cout << " " << s.peek();
                top = top->next;
            }
            top = tempPtr; //returns top back to top

            cout << endl;
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

void Stack::Delete(){ //deletes the entire stack and head node

    while (top != NULL) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}
