// 输入：head = [1,2,3,4]
// 输出：[2,1,4,3]

//结合图理解

ListNode* swapPairs(ListNode* head) {
    //TODO 有问题
    ListNode* pre = new ListNode(-1);
    pre->next=head;
    ListNode* cur = pre;
    while(cur && cur->next && cur->next->next){
        ListNode* l1 = cur->next;
        ListNode* l2 = cur->next->next;
        ListNode* l3 = cur->next->next->next;
        cur->next=l2;
        l2->next=l1;
        l1->next=l3;
        cur=l2;//TODO cur=cur->next->next还是l2
    }
    return pre->next;
}