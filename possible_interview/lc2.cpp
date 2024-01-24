//输入：l1 = [2,4,3], l2 = [5,6,4]
//输出：[7,0,8]
//解释：342 + 465 = 807.


#include <iostream>
using namespace std;

struct ListNode{
    ListNode* next;
    int val;
    ListNode(int x){
        val=x;
        next= nullptr;
    }
};

void print_node(ListNode* head){
    while (head!= nullptr){
        cout << head->val << " ";
        head=head->next;
    }
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* pre = new ListNode(-1);
    ListNode* cur = pre;
    int add = 0;
    while (l1 || l2)
    {
        int v1=0;
        if(l1){
            v1=l1->val;
            l1=l1->next;
        }
        int v2=0;
        if (l2)
        {
            v2=l2->val;
            l2=l2->next;
        }
        int num=(v1+v2+add)%10;
        add = (v1+v2+add)/10;
        cur->next = new ListNode(num);
        cur=cur->next;
    }
    if (add==1)
    {
        cur->next=new ListNode(1);
    }
    return pre->next;
}

int main(){
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next=new ListNode(3);
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    ListNode* h = addTwoNumbers(l1,l2);
    print_node(h);
    return 0;
}