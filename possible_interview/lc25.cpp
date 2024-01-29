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

ListNode* reverseList(ListNode* head){
    ListNode* pre = nullptr;
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

// 1 2 3 4 5,k=3 ==> 3 2 1 4 5
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* cur = head;
    for (int i = 0; i < k-1; i++)//判断当前是否有k个节点
    {
        //移动k-1次，如果最后cur是nullptr，就不满足够k个
        if (cur==nullptr)
        {
            break;
        }else
        {
            cur=cur->next;
        }
    }
    if (cur == nullptr) {
        return head;
    }
    cout << cur->val << endl;
    ListNode* l2 = cur->next;
    cur->next=nullptr;//断开第一段
    //反转链表
    ListNode* h = reverseList(head);
    ListNode* curh = h;
    while (curh->next)
    {
        curh=curh->next;
    }
    //递归调用， 下一段
    curh->next=reverseKGroup(l2,k);
    return h;    
}

void print_node(ListNode* head){
    while (head!= nullptr){
        cout << head->val << " ";
        head=head->next;
    }
}

int main(){
    ListNode* head = new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);
    print_node(reverseKGroup(head,3));
    return 0;
}