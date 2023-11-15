//
// Created by SP on 2023/11/5.
//

//字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s , 字典中的单词可以重复使用


#include<iostream>
#include<vector>
using namespace std;



bool wordBreak(string s, vector<string>& wordDict) {
    int n = wordDict.size();

}

int main(){
    string s = "applepenapple";
    vector<string> a = {"apple", "pen"};
    if (wordBreak(s,a))
    {
        cout << "y";
    }else
    {
        cout << "n";
    }
    return 0;
}