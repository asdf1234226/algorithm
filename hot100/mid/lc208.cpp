//
// Created by SP on 2023/11/12.
//


class Trie {
public:
    Trie() {

    }

    void insert(string word) {

    }

    bool search(string word) {

    }

    bool startsWith(string prefix) {

    }
};

Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // 返回 True
trie.search("app");     // 返回 False
trie.startsWith("app"); // 返回 True
trie.insert("app");
trie.search("app");     // 返回 True