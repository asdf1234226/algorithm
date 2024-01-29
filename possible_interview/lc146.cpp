#include<iostream>
#include<map>
using namespace std;

struct ListNode{
    int k,v;
    ListNode* left;
    ListNode* right;
    ListNode(int _k,int _v){
        k=_k;
        v=_v;
        left=nullptr;
        right=nullptr;
    }
};

//get操作：有值返回值，没有返回-1；对map来说没什么改变，对List来说要删除尾节点并且头插
//错误的put操作：容量满了删除尾节点，删除map中对应的节点；
//         容量没满，如果存在这个key，更新对应的value，删除这个并且头插
//                      不存在，插入map，头插

//正确的put： 先判断key是不是存在，再判断容量满没满

class LRUCache {
public:
    int cap;
    ListNode* head;
    ListNode* tail;
    map<int, ListNode*> mp;
    
    LRUCache(int capacity) {
        cap=capacity;
        head=new ListNode(-1,-1);
        tail=new ListNode(-1,-1);
        head->right=tail;
        tail->left=head;
    }
    
    int get(int key) {
        if (mp.find(key)!=mp.end())
        {
            deleteNode(mp[key]);
            insertHead(mp[key]);
            return mp[key]->v;
        }else
        {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (mp.find(key)!=mp.end())
        {
            mp[key]->v=value;//更新value
            deleteNode(mp[key]);
            insertHead(mp[key]);
        }else
        {
            if (mp.size()==cap)
            {
                mp.erase(tail->left->k);//erase要根据key删除，所以tail->left要记录key的信息
                deleteNode(tail->left);
            }
            ListNode* node = new ListNode(key, value);
            mp[key]=node;
            insertHead(node);
        }
    }
    // node->left node node->right
    void deleteNode(ListNode* node){
        node->left->right=node->right;
        node->right->left=node->left;
    }
    // head    head->right
    //   node
    void insertHead(ListNode* node){
        node->right=head->right;
        node->left=head;
        head->right->left=node;
        head->right=node;
    }
};