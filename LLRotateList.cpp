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
    ListNode* rotateRight(ListNode* head, int k) {
        while(k != 0){
            ListNode* shift = head;
            if(shift -> next -> next != NULL){
                shift = shift -> next;
            }
            ListNode* tail = shift;
            shift = shift -> next;
            tail -> next = NULL;
            shift -> next = head;
            head = shift;
            rotateRight(head, k --);
        }
        return head;
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

    cout << rotateRight(node1, 3);

}
