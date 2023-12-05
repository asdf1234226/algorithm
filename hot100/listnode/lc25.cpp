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
    ListNode* cur = head;
    ListNode* end = head;//记录前k个节点组成的链表尾节点
    for(int i=0;i<k;i++){
        if(cur==nullptr){
            return head;//不足k个
        }
        end=cur;
        cur=cur->next;
    }
    end->next=nullptr;//1.前k个节点断开
    ListNode* nextHead = reverseList(head);
    end = nextHead;//翻转后链表的尾节点
    while(end->next){
        end=end->next;
    }
    end->next=reverseKGroup(cur,k);//2.连接递归后的部分
    return nextHead;
}