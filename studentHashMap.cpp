#include <stdio.h>
#include <iostream>
#include <unordered_map>
using namespace std;

class student
{
    private:
    int roll_num;
    string name;
    int score;

    public:
    int getRollNum()
    {
        return this -> roll_num;
    }

    string getName()
    {
        return this -> name;
    }

    int getScore()
    {
        return this -> score;
    }
    
    unordered_map<int, int> stuMap;
    unordered_map<int, string> stuMapTwo;// have to make this one map

    student(string name, int roll_num, int score)
    {
        this -> name = name;
        this -> roll_num = roll_num;
        this -> score = score;
        stuMap[roll_num] = this -> score;
        stuMapTwo[roll_num] = this -> name;
    }

    void getScoreFromRollNum(int roll_num)
    {
        if ((stuMap.find(roll_num) != stuMap.end()) && 
            (stuMapTwo.find(roll_num) != stuMapTwo.end()))
        {
            cout << "Student's Name: " << stuMapTwo[roll_num] << endl;
            cout << "Student's Roll Number: " << roll_num << endl;
            cout << "Student's Score: " << stuMap[roll_num] << endl; 
        }
        else
        {
            cout << "!!!STUDENT NOT FOUND!!!" << endl;
        }
    }

    // void printMap()
    // {
    //     for(int i = 0; i < stuMap.size(); i++){
    //         cout << stuMap[i].getName() << "'s score: " 
    //         << newStudent.getScore() << " & roll number:" << 
    //         newStudent.getRollNum() << endl;
    //     }
   // }

    void deleteStudentFromMap(int roll_num)
    {
        if ((stuMap.find(roll_num) != stuMap.end()) && 
            (stuMapTwo.find(roll_num) != stuMapTwo.end()))
        {
            stuMap.erase(roll_num);
            stuMapTwo.erase(roll_num);
        }
        else
        {
            cout << "!!!STUDENT NOT FOUND!!!" << endl;
        }
    }
    
    int getSize()
    {
        return stuMap.size();
    }
};

int main(){
    int size;
    cout << "Enter the number of students in your class\n";
    cin >> size;

    for (int i = 0; i < size; i++)
    {

        int score;
        int roll_num;
        string name;

        cout << "Enter student's name \n";
        cin >> name;

        cout << "Enter student's roll number \n";
        cin >> roll_num;

        cout << "Enter student's score \n";
        cin >> score;

        student newStudent(name, roll_num, score);

        cout << newStudent.getName() << "'s score: " 
        << newStudent.getScore() << " & roll number:" << 
        newStudent.getRollNum() << endl;
    }
}




