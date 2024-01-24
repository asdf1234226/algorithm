// 输入：head = [1,2,3,4,5], n = 2
// 输出：[1,2,3,5]
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (n--)
    {
        fast=fast->next;
    }
    if (fast==nullptr)//特例
    {
        return head->next;
    } 
    while(fast->next){//用测试用例过一下
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=slow->next->next;
    return head;
}