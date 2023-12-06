//
// Created by SP on 2023/12/3.
//

//给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。

ListNode* reverseList(ListNode* head){
    ListNode* pre= nullptr;
    ListNode* cur = head;
    while (cur)
    {
        ListNode* tmp = cur->next;//暂存
        cur->next=pre;
        pre=cur;
        cur=tmp;
    }
    return pre;
}

bool isPalindrome(ListNode* head) {
    if (head==nullptr)
    {
        return true;
    }
    //特殊处理长度为1和2的
    if(head && head->next==nullptr){
        return true;
    }
    if(head && head->next && head->next->next==nullptr){
        return head->val==head->next->val;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    // 1 2 3 4 nullptr
    // 1 2 3 4 5   nullptr
    while (fast && fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    //slow=slow->next;  模拟下，不需要这个
    ListNode* cur2 = reverseList(slow);
    ListNode* cur1 = head;
    while (cur2)
    {
        if (cur1->val!=cur2->val)
        {
            return false;
        }
        cur1=cur1->next;
        cur2=cur2->next;
    }
    return true;
}