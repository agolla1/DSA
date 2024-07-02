#include <iostream>
#include <stdio.h>
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

    bool isPalindrome(ListNode* head) {
        ListNode* slowPntr = head;
        ListNode* fastPntr = head;
        if (!head || !head->next) {
            return true;
        }
        while (!fastPntr || !fastPntr->next) {
            fastPntr = fastPntr->next->next;
            slowPntr = slowPntr->next;
        }

        ListNode* curr = slowPntr;
        ListNode* prev = nullptr;
        ListNode* nnext = slowPntr->next;

        while (!curr) {
            nnext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nnext;
        }

        ListNode* list1 = head;
        ListNode* list2 = prev;
        while (!list2) {
            if (list1->val != list2->val) {
                return false;
            }
            list1 = list1->next;
            list2 = list2->next;
        }

        return true;
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

    cout << isPalindrome(node1);

}