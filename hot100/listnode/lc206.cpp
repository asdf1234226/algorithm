//
// Created by SP on 2023/12/3.
//

//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

ListNode* reverseList(ListNode* head) {
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    ListNode* second = reverseList(head->next);
    //反转链表返回的是头结点，所以要先到尾节点，再连head
    ListNode* cur = second;//记录反转后的首节点
    while(cur->next!=nullptr){
        cur=cur->next;
    }
    cur->next=head;
    head->next=nullptr;
    return second;
}
//todo 迭代

ListNode* reverseList(ListNode* head) {
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    ListNode* pre = nullptr;
    ListNode* cur = head;
    while(cur!=nullptr){
        ListNode* tmp = cur->next;//暂存下一节点
        cur->next=pre;
        pre=cur;
        cur=tmp;
    }
    //跳出循环时,cur为nullptr，pre刚好是反转后链表头
    return pre;
}