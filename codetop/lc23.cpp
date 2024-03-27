// 输入：lists = [[1,4,5],[1,3,4],[2,6]]
// 输出：[1,1,2,3,4,4,5,6]

#include<iostream>
#include<vector>
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

ListNode* mergeTwo(ListNode* l1, ListNode* l2){
    ListNode* pre = new ListNode(-1);
    ListNode* cur = pre;
    while (l1 && l2)
    {
        if (l1->val<l2->val)
        {
            cur->next=l1;
            l1=l1->next;
        }
        else
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

ListNode* helpMerge(vector<ListNode*>& lists, int l, int r){
    if (l==r)
    {
        return lists[l];
    }
    int mid = (l+r)>>1;
    ListNode* l1 = helpMerge(lists,l,mid);
    ListNode* l2 = helpMerge(lists,mid+1,r);
    return mergeTwo(l1,l2);
}
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size()==0) return nullptr;
    return helpMerge(lists,0,lists.size()-1);
}