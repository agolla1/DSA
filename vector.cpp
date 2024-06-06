#include <iostream>
#include <vector>
#include <algorithm>  
#include <string>     

using namespace std;

void rightShift(vector<int>& vec, int n) {
    if (n > 0) {
        int last = vec.back();
        for (int i = n - 1; i > 0; --i) {
            vec[i] = vec[i - 1];
        }
        vec[0] = last;
    }
}

void rightShift(vector<string>& vec, int n) {
    if (n > 0) {
        string last = vec.back();
        for (int i = n - 1; i > 0; --i) {
            vec[i] = vec[i - 1];
        }
        vec[0] = last;
    }
}

void printVectorArr(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

void printVectorArr(const vector<string>& vec) {
    for (const string& val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

void getIndex(const vector<int>& vec, int K) {
    auto it = find(vec.begin(), vec.end(), K);
    if (it != vec.end()) {
        int index = it - vec.begin();
        cout << "Index: " << index << endl;
    } else {
        cout << "INDEX NOT FOUND" << endl;
    }
}

void getIndex(const vector<string>& vec, const string& K) {
    auto it = find(vec.begin(), vec.end(), K);
    if (it != vec.end()) {
        int index = it - vec.begin();
        cout << "Index: " << index << endl;
    } else {
        cout << "INDEX NOT FOUND" << endl;
    }
}

int main() {
    int opt;
    int mainNum;
    vector<int> intVec;
    vector<string> strVec;
    bool flag = false;
    bool mainFlag = false;

    while (!mainFlag) {
        while (!flag) {
            cout << "WHICH DATA TYPE WOULD YOU LIKE YOUR VECTOR TO BE?" << endl;
            cout << "1. INTEGER (TYPE 1 FOR THIS OPTION)" << endl;
            cout << "2. STRING (TYPE 2 FOR THIS OPTION)" << endl;
            cin >> opt;

            if (opt == 1) {
                int num;
                int ele = 1;
                int val;
                cout << "PLEASE TYPE THE NUMBER OF ELEMENTS YOU WANT IN YOUR VECTOR!" << endl;
                cin >> num;

                for (int i = 0; i < num; ++i) {
                    cout << "PLEASE TYPE YOUR DESIRED INTEGER FOR ELEMENT: " + to_string(ele) << endl;
                    cin >> val;
                    intVec.push_back(val);
                    ele++;
                }

                mainNum = num;
                printVectorArr(intVec);
                flag = true;
        
            } else if (opt == 2) {
                int num;
                int ele = 1;

                cout << "PLEASE TYPE THE NUMBER OF ELEMENTS YOU WANT IN YOUR VECTOR!" << endl;
                cin >> num;

                for (int i = 0; i < num; ++i) {
                    string word;
                    cout << "PLEASE TYPE YOUR DESIRED WORD FOR ELEMENT: " + to_string(ele) << endl;
                    cin >> word;
                    strVec.push_back(word);
                    ele++;
                }

                mainNum = num;
                printVectorArr(strVec);
                flag = true;

            } else {
                cout << "****************************************************" << endl;
                cout << " !!!ERROR PLEASE TRY AGAIN NOT A VALID OPTION!!! " << endl;
                cout << "****************************************************" << endl;
                flag = false;
            }
        }

        string pick;
        bool flagRS = false;
        cout << "WOULD YOU LIKE TO DO A RIGHT SHIFT ON YOUR VECTOR?" << endl;
        cout << "TYPE \"YES\" OR \"NO\" AND HIT ENTER" << endl;
        cin >> pick;

        while (!flagRS) {
            if (pick == "YES" || pick == "yes") { // why does this not pick up the lower case form
                if (opt == 1) {
                    rightShift(intVec, mainNum);
                    printVectorArr(intVec);
                    flagRS = true;
                } 
                else if (opt == 2) {
                    rightShift(strVec, mainNum);
                    printVectorArr(strVec);
                    flagRS = true;
                }
            } 
            else if (pick == "NO" || pick == "no") {
                cout << "NO RIGHT SHIFT" << endl;
                flagRS = true;
            } 
            else {
                cout << "****************************************************" << endl;
                cout << " !!!ERROR PLEASE TRY AGAIN NOT A VALID OPTION!!! " << endl;
                cout << "****************************************************" << endl;
                flagRS = false;
            }
        }


        bool flagEX = false;
        while (!flagEX) {
            int optEX;
            cout << "WOULD YOU LIKE TO EXPLORE ANY OF THESE OPTIONS?" << endl;
            cout << "1. SEARCH THE INDEX OF YOUR CHOICE" << endl;
            cin >> optEX;

            if (optEX == 1) {
                if (opt == 1) {
                    printVectorArr(intVec);
                    int req;
                    cout << "WHICH NUMBER'S INDEX WOULD YOU LIKE TO KNOW FROM YOUR VECTOR ABOVE?" << endl;
                    cin >> req;
                    getIndex(intVec, req);
                    flagEX = true;
                } else if (opt == 2) {
                    string req;
                    printVectorArr(strVec);
                    cout << "WHICH WORD'S INDEX WOULD YOU LIKE TO KNOW FROM YOUR VECTOR ABOVE?" << endl;
                    cin >> req;
                    getIndex(strVec, req);
                    flagEX = true;
                } else {
                    cout << "****************************************************" << endl;
                    cout << " !!!ERROR PLEASE TRY AGAIN NOT A VALID OPTION!!! " << endl;
                    cout << "****************************************************" << endl;
                    flagEX = false;
                }
            }
            
        }
        string finalOpt;
            cout << "THANK YOU FOR USING MY SIMULATOR!!! \nWOULD YOU LIKE TO START AGAIN?" << endl;
            cin >> finalOpt;

            if (finalOpt == "YES" || finalOpt == "yes") {
                cout << "SURE, LET'S START AGAIN!" << endl;
                intVec.clear();
                strVec.clear();
                flag = false;
            } 
            else if (finalOpt == "NO" || finalOpt == "no") {
                mainFlag = true;
            } 
            else {
                break;
            }
        cout << "THANKS FOR USING!!!" << endl;
    }
    return 0;
}
