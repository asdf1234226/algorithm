// LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
// void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，
// 则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，
// 则应该 逐出 最久未使用的关键字。


//O(1)的复杂度，说明要用map
//get操作： 如果key存在就返回，并且作为最新使用的
//         如果key不存在，返回-1
//put操作： 如果key存在，更新，并作为最新使用的；
//          如果key不在，插入map，并且作为最新使用的
// 如何区别最新使用和最久未使用，头部是最新使用，尾部是最久未使用
// 为什么用双向链表，get的key存在时，要把这个作为最新使用的，需要先删除再插到头部，双向链表都是O(1)

#include<iostream>
#include<map>
using namespace std;

struct Node{
    Node* pre;
    Node* next;
    int k;
    int v;
    Node(int key, int val){
        k=key;
        v=val;
    }
};

class LRUCache {
public:
    Node* head;
    Node* tail;
    int cap;
    map<int, Node*> mp;
    
    LRUCache(int capacity) {
        cap=capacity;
        //初始化双向链表
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next=tail;
        tail->pre=head;
    }
    
    int get(int key) {
        if (mp.find(key)==mp.end())
        {
            return -1;
        }else
        {
            Node* node = mp[key];
            deleteNode(node);
            insertHead(node);
            return node->v; 
        }
    }

    void put(int key, int value) {
        if (mp.find(key)!=mp.end())
        {
            Node* nod = mp[key];
            nod->v = value;//更新map中值
            deleteNode(nod);
            insertHead(nod);
        }else
        {
            if (mp.size()==cap)//key之前不存在，需要判断容量是否超了
            {
                ////只有容量要溢出时，才会删除map中的Node
                mp.erase(tail->pre->k);
                deleteNode(tail->pre);
            }
            Node* nod = new Node(key,value);
            mp[key]=nod;
            insertHead(nod);
        }
    }

    void deleteNode(Node* node){
        //双向链表中删除节点
        Node* l = node->pre;
        Node* r = node->next;
        l->next=r;
        r->pre=l;
    }

    // head  node  head_next  
    //先从node出发，node->next,node->pre；先新后旧，右左右左
    void insertHead(Node* node){
        //插入到前驱节点head后
        Node* head_next = head->next;
        node->next=head_next;
        node->pre=head;
        head_next->pre=node;
        head->next=node;
    }

};


void testLRUCache() {
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    std::cout << cache.get(1) << std::endl; // 返回 1

    cache.put(3, 3);    // 该操作会使得密钥 2 作废
    std::cout << cache.get(2) << std::endl; // 返回 -1 (未找到)

    cache.put(4, 4);    // 该操作会使得密钥 1 作废
    std::cout << cache.get(1) << std::endl; // 返回 -1 (未找到)
    std::cout << cache.get(3) << std::endl; // 返回 3
    std::cout << cache.get(4) << std::endl; // 返回 4
}

int main() {
    testLRUCache();
    return 0;
}