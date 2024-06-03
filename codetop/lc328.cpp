#include<iostream>
using namespace std;

struct ListNode
{
    ListNode* next;
    int val;
    ListNode(int x): next(nullptr), val(x){
    }
};

void print_node(ListNode* head){
    while (head!= nullptr){
        cout << head->val << " ";
        head=head->next;
    }
}

// 1 2 3 4 5 6
// 画图，o和e分别更新（o借助e，e借助o），最后o链接e的头
ListNode* oddEvenList(ListNode* head){
    if (head==nullptr || head->next==nullptr)
    {
        return head;
    }
    ListNode* odd = head;
    ListNode* evenH = head->next;//保存head
    ListNode* even = evenH;
    while (even && even->next)//odd在even之前，所以判断even就好
    {
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=evenH;
    return head;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);
    head->next->next->next->next->next=new ListNode(6);
    print_node(oddEvenList(head));
    return 0;
}