
// 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
// 进阶：你能尝试使用一趟扫描实现吗？
// 输入：head = [1,2,3,4,5], n = 2
// 输出：[1,2,3,5]


//快慢指针
//判断环出现了一种表现形式，fast每次移动2，slow每次移动1
//这是另一种形式，fast先走n步，然后fast和slow每次移动1
ListNode* removeNthFromEnd(ListNode* head, int n){
    ListNode* fast = head;
    ListNode* slow = head;
    while(n--){
        fast = fast->next;
    }//fast此时指向3
    if(fast==nullptr){//特例
        return head->next;
    }
    while(fast->next!=nullptr){
        fast=fast->next;//fast指向5
        slow=slow->next;//slow指向3
    }
    slow->next=slow->next->next;//删除
    return head;
}