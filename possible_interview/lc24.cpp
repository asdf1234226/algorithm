// 输入：head = [1,2,3,4]
// 输出：[2,1,4,3]

//结合图理解

ListNode* swapPairs(ListNode* head) {
    ListNode* pre = new ListNode(-1);
    pre->next=head;
    ListNode* cur = pre;
    while(cur && cur->next){
        ListNode* l2 = cur->next;
        ListNode* l3 = cur->next->next;
        
        l2->next=l1;
        l1->next=l3;
        cur=l3;
    }
}