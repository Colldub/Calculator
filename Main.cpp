/*
    Calculator Assignment CS 121
    Main file

    Collin Worth 10-15-2023

*/
#include "Stack.h"
#include <iostream>
using namespace std;

int main(){

    Stack s;

    do{
        s.exit = false;

        s.PushAndSend(s);
        s.DisplayTop();

    }while(s.exit == false);

    s.Delete();
    return 0;
}