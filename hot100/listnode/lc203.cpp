//
// Created by SP on 2023/12/3.
//

//题意：删除链表中等于给定值 val 的所有节点。
//示例 1： 输入：head = [1,2,6,3,4,5,6], val = 6 输出：[1,2,3,4,5]

#include <iostream>
using namespace std;

struct ListNode{
    ListNode* next;
    int val;
    ListNode(int x){
        val=x;
        next= nullptr;
    }
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode* pre = new ListNode(-1);//// 设置一个虚拟头结点
    pre->next=head;
    ListNode* cur = pre;
    while (cur->next!= nullptr){//没到结尾
        if (cur->next->val==val){
            cur->next=cur->next->next;//删除下一个节点
        } else{
            cur=cur->next;
        }
    }
    return pre->next;
}
void print_node(ListNode* head){
    while (head!= nullptr){
        cout << head->val << " ";
        head=head->next;
    }
}

int main(){
    ListNode* head =  new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(6);
    head->next->next->next=new ListNode(3);
    head->next->next->next->next=new ListNode(6);
    print_node(removeElements(head,6));
    return 0;
}
