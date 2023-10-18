/*
	Calculator Assignment	CS 121
	Header File
	
	Collin Worth	10-15-2023
*/

#ifndef Stack_H
#define Stack_H
#include <string>
using namespace std;

class Stack {
public:
    Stack(); // Constructor
    ~Stack(); // Destructor

    void push(double);
    double pop();
    double peek();
    void PushAndSend(Stack&);
    void OperateFunc(Stack&, string);
    void DisplayTop();
    void Delete();

    bool exit;

private:
    struct Node {
        double data;
        Node* next;
    };
    Node* top;
};

#endif