// 给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，
// 使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
// 你不需要 保留 每个分区中各节点的初始相对位置。

// 输入：head = [1,4,3,2,5,2], x = 3
// 输出：[1,2,2,4,3,5]

#include <iostream>
#include <set>
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

void print_node(ListNode* head){
    while (head!= nullptr){
        cout << head->val << " ";
        head=head->next;
    }
}

//新建两个链表，分别保存小于x的节点 ； 大于等于x的节点
//将第二条链表接到第一条后面
ListNode* partition(ListNode* head, int x) {
    ListNode* dummy1 = new ListNode(-1);
    ListNode* dummy2 = new ListNode(-1);
    ListNode* cur1 = dummy1;
    ListNode* cur2 = dummy2;
    ListNode* cur = head;
    while (cur)
    {
        if (cur->val<x)
        {
            cur1->next=cur;
            cur1=cur1->next;
        }else
        {
            cur2->next=cur;
            cur2=cur2->next;
        }
        cur=cur->next;
    }
    cur2->next=nullptr;//将第二条结尾指向nullptr
    cur1->next = dummy2->next;//拼接
    return dummy1->next;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next=new ListNode(4);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(2);
    head->next->next->next->next=new ListNode(5);
    head->next->next->next->next->next=new ListNode(2);
    print_node(partition(head,3));
    return 0;
}