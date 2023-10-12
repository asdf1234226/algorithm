#include<iostream>
using namespace std;

//适用范围：每个节点的状态有限（如26个字母）
const int N = 10010;
int son[N][26], cnt[N]; //cnt记录节点的次数
int idx=0;//每个trie的节点有唯一的idx

void insert(string s)
{
    int p = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int u = s[i] - 'a';
        if (!son[p][u]) //不存在则新建节点
        {
            son[p][u]=++idx;
        }
        p=son[p][u]; //继续往下走
    }
    cnt[p]++;//insert完成后增加s的计数
}

int query(string s)
{
    int p = 0;
    for(int i=0;i<s.size();i++)
    {
        int u = s[i]-'a';
        if (!son[p][u])
        {
            return 0;
        }
        p=son[p][u];
        
    }
    return cnt[p];
}
int main()
{
    insert("abc");
    insert("abc");
    insert("acwing");
    insert("hhh");
    
    cout << query("abc") << " ";
    cout << query("hhh") <<" ";
    cout << query("aaaaa") << " ";
}