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
    print_node(reverseList(head));
    return 0;
}