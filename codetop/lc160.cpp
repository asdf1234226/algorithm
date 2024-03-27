//给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。
// 如果两个链表不存在相交节点，返回 null 。


//TODO 不是很熟
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
    ListNode* curA = headA;
    ListNode* curB = headB;
    while(curA!=curB){
        curA=curA==nullptr?headB:curA->next;
        curB=curB==nullptr?headA:curB->next;
    }
    return curA;
}