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
    while (fast && fast->next)//不会死循环，如果有环就会相遇return true, 
    //如果无环就fast->next会指向nullptr
    {
        fast=fast->next->next;
        slow=slow->next;
        if (fast==slow)//有环会相遇
        {
            return true;
        }
    }
    return false;
    
}

int main(){
    return 0;
}