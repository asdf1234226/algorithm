//
// Created by SP on 2023/12/3.
//

//给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
//请你将两个数相加，并以相同形式返回一个表示和的链表。
//你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

//输入：l1 = [2,4,3], l2 = [5,6,4]
//输出：[7,0,8]
//解释：342 + 465 = 807.


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

void print_node(ListNode* head){
    while (head!= nullptr){
        cout << head->val << " ";
        head=head->next;
    }
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode* pre = new ListNode(-1);
    ListNode* cur = pre;
    while(l1 || l2){
        int sum = carry;
        if(l1){
            sum+=l1->val;
        }
        if(l2){
            sum+=l2->val;
        }
        int val = sum%10;
        carry = sum/10;
        cur->next = new ListNode(val);
        cur=cur->next;
        l1=l1->next;
        l2=l2->next;  
    }
    return pre->next;
}

int main(){
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next=new ListNode(3);
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    ListNode* h = addTwoNumbers(l1,l2);
    print_node(h);
    return 0;
}