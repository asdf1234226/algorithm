// 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
// 说明:
// 1 ≤ m ≤ n ≤ 链表长度。
// 示例:
// 输入: 1->2->3->4->5->NULL, m = 2, n = 4
// 输出: 1->4->3->2->5->NULL

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

ListNode* reverseList(ListNode* head){
    ListNode* pre = nullptr;
    ListNode* cur = head;
    while(cur){
        ListNode* tmp = cur->next;
        cur->next=pre;
        pre=cur;
        cur=tmp;
    }
    return pre;
}
//1->2->3->4->5->nullptr, m = 2, n = 4
// 输出: 1->4->3->2->5->NULL

//四点法，p1指向1，p2指向2，p3指向4，p4指向5
//将p1->next(如果p1不空的话)指向p3,p2->next指向p4
ListNode* reverseBetween(ListNode* head, int m, int n){
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* pre=nullptr;
    ListNode* cur=head;
    int count = 0;
    ListNode* p1=nullptr, *p2=nullptr,*p3=nullptr,*p4=nullptr;
    //同普通反转链表类似，只是增加了四点记录，并且使用计数，在某段区间反转
    //增加dummy节点，因为m==1时，方便记录p1
    while (cur)
    {
        count++;
        ListNode* tmp = cur->next;
        if (count==m-1)
        {
            p1=cur;
        }
        if (count==m)
        {
            p2=cur;
        }
        if (count==n)
        {
            p3=cur;
        }
        if (count==n+1)
        {
            p4=cur;
        }
        if (count>m&&count<=n)
        {
            cur->next=pre;
        }
        pre=cur;
        cur=tmp;
    }
    //如果m==1，p1就是nullptr，如果n==5（最后一个）p3也不是nullptr
    if (p1)
    {
        p1->next=p3;
    }else
    {
        dummy->next=p3;
    }
    p2->next=p4;
    return dummy->next;
}

void print_node(ListNode* head){
    while (head!= nullptr){
        cout << head->val << " ";
        head=head->next;
    }
}
int main(){
    ListNode* head = new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);
    print_node(reverseBetween(head,2,4));
    return 0;
}