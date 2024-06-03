// 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
// 你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

// 输入：head = [1,2,3,4]
// 输出：[2,1,4,3]


ListNode* swapPairs(ListNode* head){
    if(head==nullptr || head->next==nullptr) return head;
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* cur = dummy;
    while(cur && cur->next && cur->next->next){
        ListNode* p1 = cur->next;
        ListNode* p2 = cur->next->next;
        ListNode* p3 = cur->next->next->next;
        cur->next=p2;
        p2->next=p1;
        p1->next=p3;
        cur=p3;
    }
    return dummy->next;
}