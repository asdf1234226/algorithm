// 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
// 你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

// 输入：head = [1,2,3,4]
// 输出：[2,1,4,3]

//结合图
ListNode* swapPairs(ListNode* head){
    ListNode* pre = new ListNode(-1);
    pre->next = head;
    ListNode* cur = pre;
    while(cur->next && cur->next->next){
        ListNode* tmp1 = cur->next;
        ListNode* tmp2 = cur->next->next;
        ListNode* tmp3 = cur->next->next->next;
        cur->next = tmp2;
        tmp2->next= tmp1;
        tmp1->next= tmp3; 
        cur=cur->next->next;//cur移动两位，准备下一轮交换
    }
    return pre->next;
}