#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> vec, int n){
    if (n < 0){
        return;
    }
    cout << vec[n] << endl;
    print (vec, n - 1);
}

int main()
{
    vector<int> temp{1,2,3,4,5,6};
    print(temp, 6);
}