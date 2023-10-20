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

void Stack::Print(){
    Node* tempPtr = new Node;
            tempPtr = top; //saves position of top for later

            cout << "Stack Contents: ";

            while(top != NULL){
                cout << " " << top->data;
                top = top->next;
            }
            top = tempPtr; //returns top back to top
            cout << endl;
}



void Stack::Delete(){ //deletes the entire stack and head node

    while (top != NULL) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}
