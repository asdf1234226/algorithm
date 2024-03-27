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
// pre      cur
// nullptr  h
ListNode* reverseList(ListNode* head){
    ListNode* pre=nullptr;
    ListNode* cur = head;
    while(cur){
        ListNode* tmp = cur->next;
        cur->next=pre;
        pre=cur;
        cur=tmp;
    }
    //跳出循环时cur为nullptr,所以返回pre
    return pre;
}

// 1 2 3 4 5,k=3 ==> 3 2 1 4 5
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* cur = head;
    for (int i = 0; i < k-1; i++)//判断有没有k个，移动k-1次
    {
        if (cur==nullptr)
        {
            break;
        }else
        {
            cur=cur->next;
        }
    }
    if (cur==nullptr)
    {
        return head;
    }
    //断开第一段
    ListNode* newh2 = cur->next;
    cur->next=nullptr;
    ListNode* newh1 = reverseList(head);
    ListNode* cur1 = newh1;
    while (cur1->next)
    {
        cur1=cur1->next;
    }
    cur1->next= reverseKGroup(newh2,k);
    return newh1;
}
void print_node(ListNode* head){
    while (head!= nullptr){
        cout << head->val << " ";
        head=head->next;
    }
}

int main(){
    cout << "111" << endl;
    ListNode* head = new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);
    print_node(reverseKGroup(head,3));
    return 0;
}