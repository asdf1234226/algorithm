// 实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。
// 输入： 1->2->3->4->5 和 k = 2
// 输出： 4


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

int kthToLast(ListNode* head, int k) {
    ListNode* fast = head;
    ListNode* slow = head;
    //快指针先走k步
    while (k--)
    {
        fast=fast->next;
    }
    while (fast!=nullptr)
    {
        fast=fast->next;
        slow=slow->next;
    }
    return slow->val;
}

int main(){
    ListNode* h = new ListNode(1);
    h->next=new ListNode(2);
    h->next->next=new ListNode(3);
    h->next->next->next=new ListNode(4);
    h->next->next->next->next=new ListNode(5);
    cout << kthToLast(h,2);
    return 0;
}