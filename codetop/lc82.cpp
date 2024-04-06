#include<iostream>
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

    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);//前驱节点
        dummy->next=head;
        ListNode* cur = dummy;
        while (cur->next && cur->next->next)
        {
            int x = cur->next->val;//记录下节点值
            // 如 1,2,3,3,4,4,5
            //cur指向2，cur->next指向3，cur->next->next指向3
            //只要这两个相同，都要删掉
            if (cur->next->next->val==x)
            {
                //删除所有和x相同的
                while(cur && cur->next &&cur->next->val==x){
                    cur->next=cur->next->next;
                }
            }
            else{
                cur=cur->next;
            }
        }
        return dummy->next;
    }

int main(){
    return 0;
}