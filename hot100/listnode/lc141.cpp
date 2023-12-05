//
// Created by SP on 2023/12/3.
//

//给你一个链表的头节点 head ，判断链表中是否有环。
//输入：head = [3,2,0,-4], pos = 1
//输出：true

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


bool hasCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast && fast->next)//无环，fast->next总会走到链表结尾，不会死循环
    {
        fast=fast->next->next;
        slow=slow->next;
        if (fast==slow)//有环就会相遇
        {
            return true;
        }
    }
    return false;           
}