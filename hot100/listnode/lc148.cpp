//给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 
// 输入：head = [4,2,1,3]
// 输出：[1,2,3,4]

//适合归并排序，结合前面合并两个升序链表的题目
//如何找中点，快慢指针

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* pre = new ListNode(-1);
    ListNode* cur = pre;
    while(list1 && list2){
        if (list1->val<list2->val)
        {
            cur->next=list1;
            list1=list1->next;
        }else
        {
            cur->next=list2;
            list2=list2->next;
        }
        cur=cur->next;
    }
    if (list1 && list2==nullptr)
    {
        cur->next=list1;
    }
    if (list2 && list1==nullptr)
    {
        cur->next=list2;
    }
    return pre->next;
}

ListNode* sortList(ListNode* head) {
    if(head==nullptr || (head&&head->next==nullptr)){
        return head;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* left_end = nullptr;//记录前半段链表的尾节点
    while(fast && fast->next){
        fast=fast->next->next;
        left_end=slow;
        slow=slow->next;
    }
    //如果 4，2，1，3, 跳出循环时fast指向nullptr，slow指向1
    //如果5，4，2，1，3 跳出循环时fast指向3，slow指向2
    ListNode* l2 = slow;//右半边链表的头节点
    left_end->next=nullptr;//左半边链表断开
    ListNode* left = sortList(head);
    ListNode* right = sortList(l2);
    return mergeTwoLists(left, right);
}