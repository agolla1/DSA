#include <iostream>
#include <array>
#include <map>
using namespace std;


int fibonacci (int n){
    if (n < 0){
        return INT_MIN;
    }
    if (n == 0){
        return 0;
    }
    if (n == 1){
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

long long fibonacciMemo (int n, map<long, long long> &hashMap){
    if (n < 0){
        return INT_MIN;
    }
    if (n == 0){
        return 0;
    }
    if (n == 1){
        return 1;
    }
    if (hashMap.find(n) != hashMap.end()){
        return hashMap[n];
    }

    long long result = fibonacciMemo(n - 1, hashMap) + fibonacciMemo(n - 2, hashMap);
    hashMap[n] = result;
    return result;
}

//NEED TO UPDATE fibonacciTab
// long long fibonacciTab (int n, vector<long long> &hash){
//     hash[0] = 0;
//     hash[1] = 1;
//     long long result;

//     for (auto it: hash){
//         if (it == hash[n]){
            
//             return n;
//         }
//     }

//     hash[n] = result;
//     return result;
// }

// f(n) = n + f(n-1)
// test for commit 


int main() 
{
    map<long, long long> hashMap;
    cout << fibonacciMemo(10,hashMap) << endl;

    vector<long long> hash(10,0);
    //cout << fibonacciTab(10,hash) << endl;
}
