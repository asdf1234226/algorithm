#include<iostream>
#include<map>
using namespace std;


struct Node{
    int key,val;
    Node* left;
    Node* right;
    Node(int _k,int _v){
        key=_k;
        val=_v;
        left=nullptr;
        right=nullptr;
    }
};


//get 如果没有返回-1，如果有，删除节点，刷新到头结点
//put 如果有，更新值，删除节点，刷新到头
// 如果没有，插入（满了就要删尾节点），没满直接头插
class LRUCache {
public:
    int cap;
    map<int, Node*> mp;
    Node* head;
    Node* tail;
    LRUCache(int capacity) {
        cap=capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->right=tail;
        tail->left=head;
        
    }
    
    int get(int key) {
        if (mp.find(key)==mp.end())
        {
            return -1;
        }else
        {
            Node* nod = mp[key];
            deleteNode(nod);
            insertHead(nod);
            return nod->val;
        }
    }
    
    void put(int key, int value) {
        if (mp.find(key)!=mp.end())
        {
            mp[key]->val=value;
            deleteNode(mp[key]);
            insertHead(mp[key]);
        }else
        {
            if (mp.size()==cap)
            {
                mp.erase(tail->left->key);//map删除节点，需要记录key
                //Attention:  deleteNode必须在后面做，如果先deleteNode再erase,会erase错误的节点
                deleteNode(tail->left);
            }
            Node* nod = new Node(key,value);
            mp[key]=nod;
            insertHead(nod);
        }
    }

    //nod->left nod nod->right
    void deleteNode(Node* node){
        node->left->right=node->right;
        node->right->left=node->left;
    }
    //head nod head->right
    void insertHead(Node* nod){
        nod->right=head->right;
        nod->left=head;
        head->right->left=nod;
        head->right=nod;
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