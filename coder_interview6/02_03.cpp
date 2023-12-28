// 若链表中的某个节点，既不是链表头节点，也不是链表尾节点，则称其为该链表的「中间节点」。
// 假定已知链表的某一个中间节点，请实现一种算法，将该节点从链表中删除。

// 输入：节点 5 （位于单向链表 4->5->1->9 中）
// 输出：不返回任何数据，从链表中删除传入的节点 5，使链表变为 4->1->9


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
void print_node(ListNode* head){
    while (head!= nullptr){
        cout << head->val << " ";
        head=head->next;
    }
}

void deleteNode(ListNode* head, ListNode* node) {
    ListNode* cur = head;
    while (cur->next!=nullptr)
    {
        if (cur->next==node)//删除这个中间节点
        {
            cur->next=cur->next->next;
        }else
        {//如果没找到就继续找
            cur=cur->next;
        }
    }
    print_node(head);
    
}

int main(){
    ListNode* h = new ListNode(4);
    h->next=new ListNode(5);
    h->next->next=new ListNode(1);
    h->next->next->next=new ListNode(9);
    deleteNode(h,h->next);
    return 0;
}