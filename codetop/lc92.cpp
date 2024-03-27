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
ListNode* reverseBetween(ListNode* head, int m, int n){
    ListNode* pre = new ListNode(-1);
    ListNode* cur = pre;
    cur->next=head;
    for (int i = 0; i < m-1; i++)
    {
        cur=cur->next;
    }
    ListNode* l1=cur;
    ListNode* l2h = cur->next;
    l1->next=nullptr;
    for (int i = 0; i < n-m; i++)
    {
        l2h=l2h->next;
    }
    ListNode* l3=l2h->next;
    l2h->next=nullptr;
    l1->next=reverseList(l2h);
    while (l1->next)
    {
        l1=l1->next;
    }
    l1->next=l3;
    return pre->next;
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