#include <stdio.h>
#include <iostream>
using namespace std;

class LLLoop
{
    public:
    int val;
    LLLoop *next;

    LLLoop(int val){
        this -> val = val;
        this -> next = NULL;
    }
};

int lengthLLLoop(LLLoop* meetPnt){
    LLLoop* temp = meetPnt;
    int length = 1;
    temp = temp -> next;

    while (temp != meetPnt){
        length ++;
        temp = temp -> next;
    }
    return length;
}

int isItLLLoop(LLLoop* head){
    LLLoop* fastPtr = head;
    LLLoop* slowPtr = head;

    if(head == NULL){
        cout << "IT IS NOT A LINKED LIST LOOP" << endl;
        return 0;
    }
    //It would never enter the loop, did you try running and testing?
    

    while (fastPtr->next != NULL) {
        slowPtr = slowPtr -> next;
        fastPtr = fastPtr -> next -> next;
        if (slowPtr == fastPtr){
            break;
            cout << "IT IS A LINKED LIST LOOP" << endl;
        }
        if (slowPtr != fastPtr){
            if(slowPtr -> next == NULL || 
            fastPtr -> next == NULL || 
            fastPtr -> next -> next == NULL){
            cout << "IT IS NOT A LINKED LIST LOOP" << endl;
                return 0;
            }
            slowPtr = slowPtr -> next;
            fastPtr = fastPtr -> next -> next;
            }
        if(slowPtr == fastPtr ){
            cout << "IT IS A LINKED LIST LOOP" << endl;
            return lengthLLLoop(slowPtr);
        }

        else{
            cout << "IT IS NOT A LINKED LIST LOOP" << endl;
            return 0;
        }
    }
}

int main()
{
    LLLoop* node1 = new LLLoop(1);
    LLLoop* node2 = new LLLoop(2);
    LLLoop* node3 = new LLLoop(3);
    LLLoop* node4 = new LLLoop(4);
    LLLoop* node5 = new LLLoop(5);
    LLLoop* node6 = new LLLoop(6);
    LLLoop* node7 = new LLLoop(7);
    
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;
    node5 -> next = node6;
    node6 -> next = node7;
    node7 -> next = node2;

    // int size;
    // string option;
    // int nodeVal;
    // cout << "WHAT IS THE SIZE OF YOUR DESIRED LINKED LIST?" << endl;
    // cin >> size;
    // cout << "DO YOU WANT TO CREATE A LOOP? \n TYPE ""YES"" OR ""NO""" << endl;
    // cin >> option;
    // if(option == "YES" || option == "yes"){

    // }

    cout << isItLLLoop(node1) << endl;
}