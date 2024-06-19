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
    ListNode(){
        this -> next = NULL;
    }
};

    ListNode* reverseListNode(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nnext;

        while (!curr) {
            nnext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nnext;
        }

        head = prev;

        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* newl1 = reverseListNode(l1);
    ListNode* newl2 = reverseListNode(l2);

    if (l1 == NULL && l2 == NULL) {
        return NULL;
    }

    if (l1 == NULL) {
        return l2;
    } else {
        return l1;
    }

    int carry = 0;
    ListNode* sol = new ListNode();
    ListNode* curr = sol;

    while (newl1 != NULL  && newl2 != NULL) {
          int sum = newl1->val + newl2->val;
          carry = sum / 10;
          if(curr != NULL){
          curr->next = new ListNode(sum % 10);
          newl1 = newl1->next;
          newl2 = newl2->next;
      }
    }

    if (newl1) {
        while (newl1) {
            curr->next = new ListNode((newl1->val + carry) % 10);
            newl1 = newl1->next;
        }
    } else if (newl2) {
        while (newl2) {
            curr->next = new ListNode((newl2->val + carry) % 10);
            newl2 = newl2->next;
        }
    }

    else {
        if (carry) {
            curr->next = new ListNode(carry);
        } else
            return sol;
    }

    return sol;
}
int main () 
{

}