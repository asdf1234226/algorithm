// 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。
// 如果两个链表没有交点，返回 null 

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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* curA = headA;
    ListNode* curB = headB;
    //如果有交点，肯定最后返回交点
    //如果没交点，最差的情况是curA先走完A再走完B； curB先走完B再走完A，最后curA=curB=nullptr
    while (curA!=curB)
    {
        curA = curA==nullptr?headB:curA->next;
        curB = curB==nullptr?headA:curB->next;
    }
    return curA;
}