#include <iostream>
#include <vector>
using namespace std;

int findMin(vector <int> vec, int n){
    if (n < 0){
        return INT_MAX;
    }

    int min = INT_MIN;
    
    if (vec[n] < vec[n-1]){
        min = vec[n];
    }

    return findMin(vec, n-1);
}


int main() 
{
    vector<int> x{1,3,6,4,9,11,900};
    findMin(x,7);

}

