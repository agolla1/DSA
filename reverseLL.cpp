#include <stdio.h>
#include <iostream>
using namespace std;

class ListNode
{
    public:
    int val;
    ListNode *next;

    ListNode(int val){
        this -> val = val;
        this -> next = NULL;
    }
};

    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nnext;

        while (curr != NULL) {
            nnext = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nnext;
        }
        
        head = prev;
    
    return head; 
}

void printLL(ListNode *head)
{
    ListNode *temp = head;
    cout << "[";
    while (temp)
    {   
        if (temp -> next == NULL){
            int x = temp->val;
            cout << x;
            break;
        }
        int x = temp->val;
        cout << x << ", ";
        temp = temp->next;
    }
    cout << "]";
}

int main()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(6);
    ListNode* node7 = new ListNode(7);
    
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;
    node5 -> next = node6;
    node6 -> next = node7;

    ListNode* output = reverseList(node1);
    printLL(output);

}
