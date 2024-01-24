
//链表是否有环，返回环入口
//输入：head = [3,2,0,-4], pos = 1
//输出：返回索引为 1 的链表节点


#include <iostream>
using namespace std;

struct ListNode{
    ListNode* next;
    int val;
    ListNode(int x){
        val=x;
        next= nullptr;
    }
};

//有环 到入口a，环长度b
//f=2s，f=s+nb  ==> s=nb
//环入口特征nb+a，再走a就会到环入口，恰好h到入口也是a，刚好第二次相遇

ListNode *detectCycle(ListNode *head){
    bool hasCycle = false;
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast && fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
        if (fast==slow)
        {
            hasCycle=true;
            break;
        }
    }
    if (!hasCycle)
    {
        return nullptr;
    }
    ListNode* h = head;
    while (h!=slow)
    {
        h=h->next;
        slow=slow->next;
    }
    return h;
}