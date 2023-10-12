#include <iostream>

//TODO 链表后面再说
struct Node
{
    int val;
    Node* next;
    Node(int x): val(x){};
};
class LinedList{
public:
    LinedList():head(nullptr){};
    void append(int val)
    {
        if (head == nullptr)
        {
            head = new ListNode(val);
        }
        else
        {
            ListNode* cur = head;
            while (cur->next!=nullptr)
            {
                cur = cur->next;
            }
            cur->next = new ListNode(val);          
        }   
    }
    void print()
    {
        ListNode* cur = head;
        while (cur!= nullptr)
        {
            std::cout << cur->val << " ";
            cur = cur->next;
        }
        std::cout << std::endl;  
    }
    
    ListNode* mergeTwoLists(ListNode* n1, ListNode* n2)
    {   
        ListNode* pre = new ListNode(0);
        while(n1!=nullptr && n2!=nullptr)
        {} 

    };
private:
    ListNode* head;
};




int main()
{
    LinedList l;
    l.append(1);
    l.append(2);
    l.append(4);
    l.print();
    LinedList l2;
    l2.append(1);
    l2.append(3);
    l2.append(4);


    return 0;
}
