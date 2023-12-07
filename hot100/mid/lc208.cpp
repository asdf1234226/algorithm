//
// Created by SP on 2023/11/12.
//

// 1.Trie() 初始化前缀树对象。
// 2.void insert(String word) 向前缀树中插入字符串 word 。
// 3.boolean search(String word) 如果字符串 word 在前缀树中，返回 true
// （即，在检索之前已经插入）；否则，返回 false 。
// 4.boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，
// 返回 true ；否则，返回 false 

#include<iostream>
#include<cstring>
using namespace std;

class Trie {
public:
    Trie() {
        idx = 0;
        memset(cnt,0,sizeof cnt);
        memset(son,0,sizeof son);
    }

    void insert(string word) {
        int p = 0;
        for (int i = 0; i < word.size(); i++)
        {
            int u = word[i]-'a';
            if (!son[p][u])
            {
                son[p][u]=++idx;
            }
            p=son[p][u];
        }
        cnt[p]++;
    }

    bool search(string word) {
        int p = 0;
        for (int i = 0; i < word.size(); i++)
        {
            int u = word[i]-'a';
            if (!son[p][u])
            {
                return false;
            }
            p=son[p][u];
        }
        return cnt[p] > 0;
    }

    bool startsWith(string prefix) {
        int p = 0;
        for (int i = 0; i < prefix.size(); i++)
        {
            int u = prefix[i]-'a';
            if (!son[p][u])
            {
                return false;
            }
            p=son[p][u];
        }
        return true;
    }
private:
    static const int N = 2010;
    int idx;
    int cnt[N];
    int son[N][26];
};

int main(){
    Trie trie = Trie();
    trie.insert("apple");
    cout << trie.search("apple") << " ";   // 返回 True
    cout << trie.search("app") << " ";     // 返回 False
    cout << trie.startsWith("app") << " "; // 返回 True
    trie.insert("app");
    cout << trie.search("app") << " ";     // 返回 True
}
