// 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
// 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

// 示例 1：
// 给定链表 1->2->3->4, 重新排列为 1->4->2->3.
// 示例 2：
// 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.

#include<iostream>
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

ListNode* reverseList(ListNode* head){
    ListNode* pre = nullptr;
    ListNode* cur = head;
    while (cur)
    {
        ListNode* tmp = cur->next;
        cur->next=pre;
        pre=cur;
        cur=tmp;
    }
    return pre;
}
//分成两段，第二段1->2->3  5->4
ListNode* reorderList(ListNode* head){
    if (head==nullptr && head->next==nullptr)
    {
        return head;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* l1_end = nullptr;
    while (fast&&fast->next)
    {
        fast=fast->next->next;
        l1_end=slow;
        slow=slow->next;
    }
    l1_end->next=nullptr;
    ListNode* l2 = reverseList(slow);
    ListNode* pre = new ListNode(-1);
    ListNode* cur = pre;
    ListNode* l1 = head;
    bool flag = true;
    while (l1 && l2)
    {
        if (flag)
        {
            cur->next=l1;
            l1=l1->next;
        }else
        {
            cur->next=l2;
            l2=l2->next;
        }
        flag=!flag;
        cur=cur->next;
    }
    if (l2)
    {
        cur->next=l2;
    }
    return pre->next;
}
void print_node(ListNode* head){
    while (head!= nullptr){
        cout << head->val << " ";
        head=head->next;
    }
}
int main(){
    ListNode* h = new ListNode(1);
    h->next=new ListNode(2);
    h->next->next=new ListNode(3);
    h->next->next->next=new ListNode(4);
    h->next->next->next->next=new ListNode(5);
    print_node(reorderList(h));
    return 0;
}
//TODO [1]