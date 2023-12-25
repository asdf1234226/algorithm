
// 给你一个链表数组，每个链表都已经按升序排列。
// 请你将所有链表合并到一个升序链表中，返回合并后的链表。

// 输入：lists = [[1,4,5],[1,3,4],[2,6]]
// 输出：[1,1,2,3,4,4,5,6]
// 解释：链表数组如下：
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]


#include<iostream>
#include<vector>
using namespace std;
struct ListNode{
    ListNode* next;
    int val;
    ListNode(int x){
        val=x;
        next= nullptr;
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
        cur=cur->next;//经常漏写
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

//如果依次合并，那么第一条会被合并k-1次，最后一条会被合并1次，平均每条链表合并大概k/2次
//如果归并合并，每条链表平均合并logK次

ListNode* merge(vector<ListNode*>& lists, int l, int r){
    if (l==r)
    {
        return lists[l];
    }
    
    int mid = (l+r)>>1;
    ListNode* list1 = merge(lists,l,mid);
    ListNode* list2 = merge(lists,mid+1,r);
    return mergeTwoLists(list1, list2);
}
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size()==0)
    {
        return nullptr;
    }
    return merge(lists, 0, lists.size()-1);
}