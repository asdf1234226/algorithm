#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x){
        val=x;
        next=nullptr;
    }
};

bool hasCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast && fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
        if (fast==slow)
        {
            return true;
        }
    }
    return false;
}