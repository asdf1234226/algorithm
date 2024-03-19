//
// Created by SP on 2023/12/14.
//

//给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
//你应当 保留 两个分区中每个节点的初始相对位置。
//
//输入：head = [1,4,3,2,5,2], x = 3
//输出：[1,2,2,4,3,5]

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
ListNode* partition(ListNode* head, int x) {
    ListNode* l1 = new ListNode(-1);
    ListNode* l2 = new ListNode(-1);
    ListNode* l2h = l2;
    ListNode* l1h = l1;
    while (head)
    {
        if (head->val<x)
        {
            l1->next=head;
            l1=l1->next;
            head=head->next;
        }else
        {
            l2->next=head;
            l2=l2->next;
            head=head->next;
        }
    }
    l1->next = l2h->next;
    l2->next = nullptr;
    return l1h->next;
}

void print_node(ListNode* head){
    while (head!= nullptr){
        cout << head->val << " ";
        head=head->next;
    }
}
int main(){
    ListNode* head = new ListNode(1);
    head->next=new ListNode(4);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(2);
    head->next->next->next->next=new ListNode(5);
    head->next->next->next->next->next=new ListNode(2);
    print_node(partition(head,3));
    return 0;
}