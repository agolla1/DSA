#include <iostream>
#include <array>
using namespace std;

void getFirstNum(int arr[] ){
    cout << arr[1] << endl;;
}

int binarySearch(int arr[], int low, int high, int x)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int linearSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int fibonacci (int n){
    if (n <= 1){
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}








int main() 
{
    int n;
    int val;
    cout << "HOW MANY NUMBER OF ELEMENTS DO YOU WANT IN YOUR ARRAY?" << endl;
    cin >> n;
    int arr[n];
    
    for (int i = 0; i < n; i++)
    {   
        cout << "TYPE A NUMBER FOR ELEMENT: " + to_string(i + 1) << endl;
        cin >> val;
        arr[n] = val;
    }

    cout << "THIS PROGRAM REPRESENTS A O(n) TIME COMPLEXITY" << endl;

    
    for (int i = 0; i < n; i++)
    {   
        cout << "TYPE A NUMBER FOR ELEMENT: " + to_string(i + 1) << endl;
        cin >> val;
        arr[n] = val;
    }

    cout << "THIS PROGRAM REPRESENTS A O(n) TIME COMPLEXITY" << endl;


    return 0;
}
