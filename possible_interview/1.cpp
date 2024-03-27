#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* current = head;
    while (current->next != NULL) {
        if (current->val == current->next->val) {
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
    return head;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(5);

    head = deleteDuplicates(head);

    ListNode* current = head;
    while (current != NULL) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    return 0;
}
