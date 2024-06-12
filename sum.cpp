#include <iostream>
#include <array>
#include <map>
using namespace std;

int findsum(int a[], int n) {
    if (n == 0) {
        return 0;
    }
    return a[n - 1] + findsum(a, n - 1);
}


int main(){
    
    int a[5] = {1, 2, 3, 4, 5};
    cout << "Sum of elements: " << findsum(a, 5) << endl;

}