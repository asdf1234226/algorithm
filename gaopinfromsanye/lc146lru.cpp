#include<iostream>
#include<unordered_map>

using namespace std;
struct Node
{
    Node* l;
    Node* r;
    int k,v;
    Node(int _k,int _v){
        k=_k;
        v=_v;
    }
};
class LRUCache
{
    int capacity;
    unordered_map<int, Node*> map;
    Node* head;
    Node* tail;
public:
    LRUCache(int cap)
    {
        head = new Node(-1,-1);
        capacity = cap;
        tail = new Node(-1,-1);
        head->r=tail;
        tail->l=head;
    }
    int get(int key)
    {
        if (map.find(key)!=map.end())  //key存在，返回v并且将该结点放在链表头部
        {
            auto nod = map[key];
            refresh(nod,false);
            return nod->v;
        }
        return -1;
    }
    void put(int key, int value)
    {
        if (map.find(key)!=map.end())
        {//存在则更新
            auto nod = map[key];
            nod->v=value;
            refresh(nod,false);
        }
        else
        {
            if (map.size()==capacity) //容量上限
            {
                auto nod = tail->l;
                map.erase(nod->k); //去掉双向链表尾部结点，并且删除map中对应的key
                deleteNode(nod,false);
            }
            Node* node = new Node(key,value); //容量没上限，新建node结点插入并更新，把该结点放链表头
            map[key] = node;
            refresh(node, true);
        }
    }
    void refresh(Node* node, bool isNew) //删除该结点，并将该node放在双向链表头
    {
        deleteNode(node, isNew); 
        auto head_r = head->r;
        //在head和head_r中插入node
        node->r=head_r;
        node->l=head;
        head->r = node;
        head_r->l=node;
        

    }
    void deleteNode(Node* node, bool isNew)
    {
        if (!isNew)  //只删除存在的结点
        {
            auto left = node->l;
            auto right = node->r;
            left->r=right;
            right->l=left;
        }
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