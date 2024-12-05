#include <stdio.h>
#include <iostream>
#include <stack>
#include <array>
using namespace std;

void printIt (int arr[])
{
    cout << "[" ;
    for (int i = 0; i < sizeof(arr) + 1; i++)
    {
        if (i = sizeof(arr)){
            cout << arr[i];
            break;
        }
        cout << arr[i] << ", ";
    }
    cout << "]";
}

int topPntr (int arr[]){
    int topPntr = NULL;
    if (arr == NULL){
        return NULL;
    }
    else{
        int topPntr = sizeof(arr) + 1;
    }
    return topPntr;
}

void push (int x, int arr[])
{
    arr[topPntr(arr)] = x;
    printIt(arr);
}

void pop (int arr[])
{
    arr[topPntr(arr)] = NULL;
    printIt(arr);
}

bool isEmpty(int arr[])
{
    if (sizeof(arr) == 0)
    {
        printIt(arr);
        return true;
    }
    else 
    {
        printIt(arr);
        return false;
    }
}
//
int sizeOf(int arr[])
{
    printIt(arr);
    return sizeof(arr);
}

int main()
{
    int arr[] = {1,2,5,3,2,7,8};
    push(5, arr);
    pop(arr);
    sizeOf(arr);
    isEmpty(arr);
    topPntr(arr);
}


