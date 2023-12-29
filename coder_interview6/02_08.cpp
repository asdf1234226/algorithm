// 给定一个链表，如果它是有环链表，实现一个算法返回环路的开头节点。若环不存在，请返回 null

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

// 到环入口a， 环b, 到环入口的特征a+nb
// f = 2s
// f比s多走了n个环的距离， f=s+nb    ====> s = nb
// s已经走了nb，只要再走a就构成a+nb环入口的特征，cur从head出发再走a也是到环入口，两者相遇

ListNode *detectCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;
    bool hasCycle = false;
    while (fast&&fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
        if (fast==slow)
        {
            hasCycle=true;
            break;
        }
    }
    if (!hasCycle)
    {
        return nullptr;
    }
    ListNode* cur = head;
    while (cur!=slow)
    {
        cur=cur->next;
        slow=slow->next;
    }
    return cur;
}

int main(){
    return 0;
}