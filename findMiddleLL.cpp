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

ListNode* findMiddleLL(ListNode* &head){
    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* slowPtr = head;
    ListNode* fastPtr = head;

    while(fastPtr != NULL && fastPtr->next != NULL){
        slowPtr = slowPtr -> next;
        fastPtr = fastPtr -> next -> next;
    }

    return slowPtr;
}

int main(){
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


    ListNode* middleNode = findMiddleLL(node1);
    if (middleNode != NULL) {
        cout << "Middle Node Value: " << middleNode->val << endl;
    } else {
        cout << "List is empty" << endl;
    }


}