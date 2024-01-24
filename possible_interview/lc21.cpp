#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int v){
        val=v;
        next=nullptr;
    }
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* pre = new ListNode(-1);
    ListNode* cur = pre;
    while (list1 && list2)
    {
        if (list1->val<list2->val)
        {
            cur->next=list1;
            list1=list1->next;
        }else
        {
            cur->next=list2;
            list2=list2->next;
        }
        cur=cur->next;
    }
    if (list1)
    {
        cur->next=list1;
    }
    if (list2)
    {
        cur->next=list2;
    }
    return pre->next;
}
void print_node(ListNode* head){
    while (head!= nullptr){
        cout << head->val << " ";
        head=head->next;
    }
}

int main(){
    ListNode* list1 = new ListNode(1);
    list1->next=new ListNode(3);
    list1->next->next=new ListNode(5);
    ListNode* list2 = new ListNode(2);
    list2->next=new ListNode(4);
    ListNode* h = mergeTwoLists(list1, list2);
    print_node(h);
    return 0;
}