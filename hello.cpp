/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;

class LL
{
public:
    int runs;
    string name;
    LL *next;

    LL(int runs, string name)
    {
        this->runs = runs;
        this->name = name;
        this->next = NULL;
    }
};

void printLL(LL *head)
{
    LL *temp = head;
    while (temp)
    {
        int x = temp->runs;
        cout << temp->name + " HAS SCORED: " + to_string(x) + " RUNS" << endl;
        temp = temp->next;
    }
}

LL *deleteFirstNode(LL *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    LL *test = head->next;
    head->next = NULL;
    free(head);
    return test;
}

LL *deleteLastNode(LL *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    LL *test = head;
    LL *newLastNode;
    while (head->next != NULL)
    {
        if (head->next->next == NULL)
        {
            newLastNode = head;
        }
        head = head->next;
    }

    free(head);
    newLastNode->next = NULL;

    return test;
}

LL *deleteMiddleNode(LL *head, LL *deleteNode)
{
    LL *start = head;
    if (head == deleteNode)
    {
        return deleteFirstNode(head); // fix 1
    }

    else if (deleteNode->next == NULL)
    {
        return deleteLastNode(deleteNode); // fix 2
    }

    while (start->next != NULL && start->next != deleteNode)
    { // 3rd
        start = start->next;
    }

    start->next = start->next->next;
    deleteNode->next = NULL;

    free(deleteNode);

    return head;
}

LL *insertNode(string insertAfterName, LL *newPlayer, LL *head)
{
    LL *insert = head;
    while (insertAfterName != insert->name)
    {
        insert = insert->next;
    }

    newPlayer->next = insert->next;
    insert->next = newPlayer;

    return (head);
}

int main()
{
    int size;
    cout << "Enter the number of players \n";
    cin >> size;

    LL *head = NULL;
    LL *temp = NULL;

    // Constructing the Linked List
    for (int i = 0; i < size; i++)
    {

        int n;
        string x;

        cout << "Enter player's name \n";
        cin >> x;

        cout << "Enter player's score \n";
        cin >> n;

        LL *player = new LL(n, x);
        cout << player << endl;
        cout << player->name << endl;
        cout << "SCORED" << endl;
        cout << player->runs << endl;
        cout << "RUNS" << endl;

        if (!head)
        {

            head = player;
            temp = head;
        }
        else
        {

            temp->next = player;
            temp = temp->next;
        }
    }

    int option;
    bool mainFlag = false;

    while (mainFlag == false)
    {

        if (option == 5)
        {
            break;
            cout << "THANK YOU FOR USING MY PROGRAM!!!" << endl;
        }

        cout << "WHICH OPTION WOULD YOU LIKE TO PICK?\n 1. DELETE THE FIRST PLAYER \n 2. DELETE THE LAST PLAYER \n 3. DELETE A PLAYER IN THE MIDDLE \n 4. INSERT A NEW PLAYER \n 5.END PROGRAM" << endl;
        cin >> option;

        if (option == 1)
        {
            string firstNodeReq;
            bool firstNodeFlag = false;

            while (firstNodeFlag == false)
            {
                cout << "DO YOU WISH TO DELETE THE FIRST NODE? \n PLEASE TYPE "
                        "YES"
                        " OR "
                        "NO"
                        " \n";
                cin >> firstNodeReq;

                if (firstNodeReq == "YES")
                {
                    head = deleteFirstNode(head);
                    printLL(head);
                    firstNodeFlag = true;
                }

                else if (firstNodeReq == "NO")
                {
                    cout << "LET'S GO TO THE NEXT OPTION! \n";
                    break;
                }

                else
                {
                    cout << "PLEASE TRY AGAIN!";
                }
            }
        }

        if (option == 2)
        {

            string lastNodeReq;
            bool lastNodeFlag = false;

            while (lastNodeFlag == false)
            {
                cout << "DO YOU WISH TO DELETE THE LAST NODE? \n PLEASE TYPE "
                        "YES"
                        " OR "
                        "NO"
                        " \n";
                cin >> lastNodeReq;
                if (lastNodeReq == "YES")
                {
                    head = deleteLastNode(head);
                    printLL(head);
                    lastNodeFlag = true;
                }

                else if (lastNodeReq == "NO")
                {
                    cout << "LET'S GO TO THE NEXT OPTION!\n";
                    break;
                }

                else
                {
                    cout << "PLEASE TRY AGAIN! \n";
                }
            }
        }

        if (option == 3)
        {

            string middleNodeReq;
            string deleteName;
            LL *rep = head;
            bool flag = false;

            while (flag == false)
            {
                cout << "DO YOU WISH TO DELETE A MIDDLE NODE? \n PLEASE TYPE "
                        "YES"
                        " OR "
                        "NO"
                        " \n";
                cin >> middleNodeReq;

                if (middleNodeReq == "YES")
                {
                    cout << "WHAT IS THE NAME OF THE PLAYER YOU WANT TO DELETE? \n";
                    cin >> deleteName;

                    while (rep->next != NULL)
                    {
                        if (rep->name == deleteName)
                        {
                            flag = true;
                            break;
                        }
                        rep = rep->next;
                    }

                    if (flag == true)
                    {
                        deleteMiddleNode(head, rep);
                        printLL(head);
                    }
                }

                else if (middleNodeReq == "NO")
                {
                    cout << "LET'S GO TO THE NEXT OPTION! \n";
                    break;
                }

                else
                {
                    cout << "PLEASE TRY AGAIN! \n";
                }
            }
        }

        if (option == 5)
        {
            string newNodeReq;
            string newName;
            string addAfterName;
            int newScore;
            bool newNodeFlag = false;

            while (newNodeFlag == false)
            {
                cout << "DO YOU WISH TO INSERT A NEW PLAYER? \n PLEASE TYPE "
                        "YES"
                        " OR "
                        "NO"
                        " \n";
                cin >> newNodeReq;

                if (newNodeReq == "YES")
                {
                    cout << "WHAT IS THE NAME OF THE NEW PLAYER YOU WANT TO INSERT ?" << endl;
                    cin >> newName;
                    cout << "WHAT IS THE " + newName + "'S SCORE?" << endl;
                    cin >> newScore;
                    cout << "WHAT IS THE NAME OF THE PLAYER YOU WANT TO ADD " + newName + " AFTER?" << endl;
                    cin >> addAfterName;

                    LL *newPlayer = new LL(newScore, newName);
                    head = insertNode(addAfterName, newPlayer, head);
                    printLL(head);
                    newNodeFlag = true;
                    break;
                }

                else if (newNodeReq == "NO")
                {
                    cout << "ALL DONE!\n";
                    break;
                }

                else
                {
                    cout << "PLEASE TRY AGAIN!\n";
                }
            }
        }
    }
}

// LL* player2 = new LL(n, x);
// player1 -> next = player2;
// cout << player2 << endl;
// cout << player2 -> name << endl;
// cout << "SCORED" << endl;
// cout << player2 -> runs << endl;
// cout << "RUNS" << endl;

// string x;
// cin>> n;
// cin>> x;

// LL* player3 = new LL(n, x);
// player2 -> next = player3;
// cout << player3 << endl;
// cout << player3 -> name << endl;
// cout << "SCORED" << endl;
// cout << player3 -> runs << endl;
// cout << "RUNS" << endl;

// string x;
// cin>> n;
// cin>> x;

// LL* player4 = new LL(n, x);
// player3 -> next = player4;
// cout << player4 << endl;
// cout << player4 -> name << endl;
// cout << "SCORED" << endl;
// cout << player4 -> runs << endl;
// cout << "RUNS" << endl;

// string x;
// cin>> n;
// cin>> x;

// LL* player5 = new LL(n, x);
// player4 -> next = player5;
// cout << player5 << endl;
// cout << player5 -> name << endl;
// cout << "SCORED" << endl;
// cout << player5 -> runs << endl;
// cout << "RUNS" << endl;
