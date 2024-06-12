#include <iostream>
#include <vector>
using namespace std;


void sieveOfEratosthenes (int n){
    vector <int> allNum(n+1,1);
    int x = 0;
    if (n < 0){
        cout << "THIS IS NOT A VALID N" <<  endl;
    }
    if (n >= 1){
        allNum[0] = 0;
        allNum[1] = 0;
    }

    for(int i = 2; i*i < n; i++ ){
        if (allNum[i] == 1){
            for (int j = i*i; j < n + 1; j+=i){
                allNum[j] = 0;
            }
        }
    }

    cout << "THE PRIME NUMBERS FROM 0 TO " << n  << " ARE: ";

    for (int i = 0; i < n; i++){
        if (allNum[i] == 1){
            cout << i << ", "; 
        }
    }
}

int main()
{
    sieveOfEratosthenes(100);
}
