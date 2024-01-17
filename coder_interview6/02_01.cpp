// 编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。

// 示例1:
// 输入：[1, 2, 3, 3, 2, 1]
// 输出：[1, 2, 3]
// 如果不得使用临时缓冲区，该怎么解决？


#include <iostream>
#include <set>
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

ListNode* removeDuplicateNodes(ListNode* head) {
    ListNode* cur = head;
    set<int> st;
    st.insert(cur->val);
    if(head==nullptr) return head;
    while (cur->next!=nullptr)
    {
        if (st.find(cur->next->val)!=st.end())//已经出现过，要删除
        {
            cur->next=cur->next->next;       
        }else
        {
            //删除节点后不立即更新 cur 来解决这个问题，只有当 cur->next 不需要被删除时，才更新 cur
            st.insert(cur->next->val);
            cur=cur->next;
        }
        //cur=cur->next;
        //当 cur->next 是一个已经出现过的值，你将 cur->next 更新为 cur->next->next，
        //然后在循环的最后，你又将 cur 更新为 cur->next。这可能会导致跳过一些节点
    }
    return head;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(3);
    head->next->next->next->next=new ListNode(2);
    head->next->next->next->next->next=new ListNode(1);
    print_node(removeDuplicateNodes(head));
    return 0;
}