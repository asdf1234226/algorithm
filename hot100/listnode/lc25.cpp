// 给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
// k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序

// 输入：head = [1,2,3,4,5], k = 3
// 输出：[3,2,1,4,5]


ListNode* reverseList(ListNode* head){
    ListNode* pre = nullptr;
    ListNode* cur = head;
    while(cur){
        ListNode* tmp = cur->next;//暂存下一节点
        cur->next=pre;
        pre=cur;
        cur=tmp;
    }
    return pre;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* pre = new ListNode(-1);
    pre->next=head;
    ListNode* cur = pre;
    while(cur){
        ListNode* start = cur->next;
        ListNode* end = cur;
        for(int i = 0; i<k&&end ;i++){
            end=end->next;
        }
        if(end==nullptr){
            break;//最后一条子链表不满足k个了，不需要反转
        }
        ListNode* next_start = end->next;//记录下一链表的起点
        end->next = nullptr;//断开链表--为了反转
        ListNode* new_start = reverseList(start);//反转
        ListNode* cur1 = new_start;
        while(cur1->next){
            cur1=cur1->next;
        }
        cur1->next=next_start;//连接断开的链表
        cur = end;
    }
    return pre->next;
}