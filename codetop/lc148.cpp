#include <iostream>
using namespace std;
// 输入：head = [-1,5,3,4,0]
// 输出：[-1,0,3,4,5]
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x){
        val=x;
        next=nullptr;
    }
};

ListNode* mergeList(ListNode* l1, ListNode* l2){
    ListNode* pre = new ListNode(-1);
    ListNode* cur = pre;
    while (l1&&l2)
    {
        if (l1->val<l2->val)
        {
            cur->next=l1;
            l1=l1->next;
        }else
        {
            cur->next=l2;
            l2=l2->next;
        }
        cur=cur->next;
    }
    if (l1)
    {
        cur->next=l1;
    }
    if (l2)
    {
        cur->next=l2;
    }
    return pre->next;
}
//TODO 又忘记了 归并排序，分成两段递归，然后合并
ListNode* sortList(ListNode* head) {
    if (head==nullptr || head->next==nullptr)
    {
        return head;
    }
    ListNode* fast=head;
    ListNode* slow=head;
    ListNode* l1_end = nullptr;
    while (fast&&fast->next)
    {
        fast=fast->next->next;
        l1_end=slow;
        slow=slow->next;
    }
    l1_end->next=nullptr;
    return mergeList(sortList(head), sortList(slow));
}

void print_node(ListNode* head){
    while (head!= nullptr){
        cout << head->val << " ";
        head=head->next;
    }
}

int main(){
    ListNode* head = new ListNode(-1);
    head->next=new ListNode(5);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(0);
    print_node(sortList(head));
    return 0;
}