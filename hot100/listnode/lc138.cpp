

struct Node{
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }   
};


Node* copyRandomList(Node* head) {
    map<Node*, Node*> mp;
    Node* pre = new Node(-1);
    Node* cur = pre;
    Node* h = head;//h遍历head
    while (h)
    {
        Node* newnode = new Node(h->val);
        mp[h]=newnode;//原节点和新节点的对应关系
        cur->next = newnode;
        cur=cur->next;
        h = h->next;
    }

    Node* cur1 = pre->next;
    h = head;
    while(cur1){
        cur1->random = mp[h->random];
        cur1=cur1->next;
        h=h->next;
    }
    return pre->next;
}

//要不要简化
Node* copyRandomList(Node* head) {
    if (!head) return nullptr;

    map<Node*, Node*> mp;
    Node* h = head;
    while (h) {
        mp[h] = new Node(h->val);
        h = h->next;
    }

    h = head;
    while (h) {
        mp[h]->next = mp[h->next];
        mp[h]->random = mp[h->random];
        h = h->next;
    }

    return mp[head];
}
