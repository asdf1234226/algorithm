//
// Created by SP on 2023/12/3.
//

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

//链表头到环入口a, 环b
//slow走了s步, fast走了f步
// 1.f=2s
// 2.有环相遇,f多走了几圈 f=s+nb
//  ===> s=nb
//环入口的特征  a+nb都是环入口
// slow已经走了nb，如何构造a+nb；===> 从head出发到环入口为a，同样slow也再走a,会再次相遇
ListNode *detectCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;
    bool hasCycle=false;
    while (fast && fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
        if (fast==slow)//一次相遇判断是否有环
        {
            hasCycle = true;
        }
    }
    if (hasCycle)
    {
        ListNode* index = head;
        while (index!=slow)//这次相遇求环入口
        {
            index=index->next;
            slow=slow->next;
        }
        return index;
    }
    return nullptr;
}