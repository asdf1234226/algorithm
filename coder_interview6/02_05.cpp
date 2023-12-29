// 给定两个用链表表示的整数，每个节点包含一个数位。
// 这些数位是反向存放的，也就是个位排在链表首部。
// 编写函数对这两个整数求和，并用链表形式返回结果。

// 示例：
// 输入：(7 -> 1 -> 6) + (5 -> 9 -> 2)，即617 + 295
// 输出：2 -> 1 -> 9，即912

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x){
        val=x;
        next=nullptr;
    }
};

void print_node(ListNode* head){
    while (head!= nullptr){
        cout << head->val << " ";
        head=head->next;
    }
}

ListNode* reverseList(ListNode* head){
    ListNode* pre = nullptr;
    //pre->next=head; //不能加这个
    ListNode* cur = head;
    while (cur)
    {
        ListNode* tmp = cur->next;
        cur->next=pre;
        pre=cur;
        cur=tmp;
    }
    return pre;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int add = 0; //进位
    ListNode* dummy = new ListNode(-1);
    ListNode* cur = dummy;
    while (l1 || l2)
    {
        int sum = add;
        if (l1)
        {
            sum+=l1->val;
            l1=l1->next;
        }
        if (l2)
        {
            sum+=l2->val;
            l2=l2->next;
        }
        cur->next=new ListNode(sum%10);
        add=sum/10;
        cur=cur->next;
    }
    if (add)
    {
        cur->next=new ListNode(add);
    }
    //return dummy->next;
    return reverseList(dummy->next);
}

int main(){
    ListNode* h1 = new ListNode(7);
    h1->next=new ListNode(1);
    h1->next->next=new ListNode(6);
    ListNode* h2 = new ListNode(5);
    h2->next=new ListNode(9);
    h2->next->next=new ListNode(2);
    print_node(addTwoNumbers(h1,h2));
    return 0;
}