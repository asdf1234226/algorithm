// 给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。

// 输入：head = [1,2,3,4,5], k = 2
// 输出：[4,5,1,2,3]
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

//先断再连，需要影子节点记录第一段结尾
ListNode* rotateRight(ListNode* head, int k) {
    if(head==nullptr|| head->next==nullptr) return head;
    int count = 0;
    ListNode* cur = head;
    while (cur)
    {
        count++;
        cur=cur->next;
    }
    k=k%count;
    if(k==0) return head; //没必要断开
    ListNode* fast = head;
    int num = count-k;//移动count-k次
    ListNode* l1_end = fast;//记录第一段的结尾
    while (num>0)
    {
        num--;
        l1_end=fast;
        fast=fast->next;
    }
    l1_end->next=nullptr;//断开第一段
    ListNode* pre = new ListNode(-1);
    pre->next = fast;
    while (fast&&fast->next)
    {
        fast=fast->next;
    }
    
    fast->next = head;
    return pre->next;
}

//先连再断
ListNode* rotateRight_opt(ListNode* head, int k) {
    if(head==nullptr|| head->next==nullptr) return head;
    int count = 1;
    ListNode* cur = head;
    while (cur->next)
    {
        count++;
        cur=cur->next;
    }
    k=k%count;
    if(k==0) return head; //没必要断开
    cur->next=head;
    int num = count-k;//移动count-k次
    // 1 2 3 4 5 ---> 4 5 1 2 3, 连成环后cur指向5，再移动3次到3，记录下一个点并且断开
    while (num>0)
    {
        num--;
        cur=cur->next;
    }
    ListNode* newh = cur->next;
    cur->next=nullptr;
    return newh;
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
    print_node(rotateRight_opt(head,2));
    return 0;
}