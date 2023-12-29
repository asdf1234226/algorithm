// 编写一个函数，检查输入的链表是否是回文的。
// 输入： 1->2->2->1
// 输出： true 


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

bool isPalindrome(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    // 1 2 3 2 1
    while (fast && fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    ListNode* l2= reverseList(slow);
    ListNode* cur = head;
    while (l2)//如果奇数个节点，l2是短的后半段反转的
    {
        if (l2->val==cur->val)
        {
            l2=l2->next;
            cur=cur->next;
        }else
        {
            return false;
        }
    }
    return true;
    
    
}

int main(){
    ListNode* h = new ListNode(1);
    h->next=new ListNode(2);
    h->next->next=new ListNode(2);
    h->next->next=new ListNode(3);
    if (isPalindrome(h))
    {
        cout << "y";
    }else
    {
        cout << "n";
    }
    return 0;
}