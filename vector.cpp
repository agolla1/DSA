#include <stdio.h>
#include <iostream>
#include <vector> 
#include <string.h>
using namespace std; 

// class Vector
// {
//     public:
//     int val;
//     vector <int> temp;
//     Vector(int val){
//         this -> val = val;
//     }  
// };
// [1,2,3,6,9,5]
// [5,1,2,3,6,9]
// n.of right shifts
//

void printVectorArr(vector<int> &a){
    for ( auto it: a ){
        cout << it  + ", ";
    }
    cout << endl;
}

void rightShift(vector <int> arr, int k) {
    int n = arr.size();
    int lastNum = arr[n-1];

    while (k --){
        cout << k << endl;
        for (int i = 0; i < arr.size(); i++){
            arr[i+1] = arr[i];
        }
        arr[0] = lastNum;
    }
}




int main()
{
    


}

