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
ListNode* reverseList(ListNode* head) {
    ListNode* pre = nullptr;
    ListNode* cur = head;
    while (cur)
    {
        ListNode* tmp =cur->next;
        cur->next=pre;
        pre=cur;
        cur=tmp;
    }
    return pre;
}
bool isPalindrome(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    // 1 2 2 1
    while (fast && fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    //翻转后半段链表，然后比较
    fast = head;
    slow = reverseList(slow);
    while (slow)
    {
        if (slow->val!=fast->val)
        {
            return false;
        }
        slow=slow->next;
        fast=fast->next;
    }
    return true;
}

int main(){
    ListNode* h = new ListNode(1);
    h->next=new ListNode(2);
    if (isPalindrome(h))
    {
        cout << "y";
    }else
    {
        cout << "n";
    }
    return 0;
}