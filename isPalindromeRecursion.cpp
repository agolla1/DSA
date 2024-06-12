#include <iostream>
#include <vector>
using namespace std;

int isPalindrome(string temp) {
    int n = temp.size();
    if (n <= 1) {
        return 1;
    }
    if (temp[0] != temp[n - 1]) {
        return 0;
    }

    return isPalindrome(temp + 1, n - 2);
}

int main() 
{
    string temp = "racecar";
    if (isPalindrome(temp)) {
        cout << "The array is a palindrome." << endl;
    } else {
        cout << "The array is not a palindrome." << endl;
    }

    return 0;
}
