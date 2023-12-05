

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
    if(head==NULL){
        return NULL;
    }
    map<Node*, Node*> mp;
    Node* cur = head;
    while(cur){
        mp[cur]=new Node(cur->val);//mp存储原节点和对应的复制节点
        cur=cur->next;
    }
    cur = head;
    while(cur){
        mp[cur]->next=mp[cur->next];//原节cur，复制节点mp[cur]
        //复制节点->next  原节点->next对应的复制节点
        mp[cur]->random=mp[cur->random];
        cur=cur->next;
    }
    return mp[head];
}
