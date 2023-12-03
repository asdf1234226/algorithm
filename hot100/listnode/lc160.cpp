//
// Created by SP on 2023/12/3.
//

//给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。
// 如果两个链表不存在相交节点，返回 null 。

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA==nullptr || headB==nullptr) return nullptr;
    ListNode* curA = headA;
    ListNode* curB = headB;
    //为什么不会死循环
    // 如果两个链表有公共尾部，curA和curB同时指向第一个公共节点
    // 如果两个链表没公共尾部, curA和curB同时指向nullptr
    //这个nullptr也细分两种情况 a: A和B长度相等，同时指向nullptr
    //                         b: A和B长度不等，curA在走完A后走B，curB在走完B后走A，最后同时指向nullptr
    while(curA!=curB){
        curA = curA==nullptr?headB:curA->next;
        curB = curB==nullptr?headA:curB->next;
    }
    return curA;
}