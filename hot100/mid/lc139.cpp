//
// Created by SP on 2023/11/5.
//

//字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s , 字典中的单词可以重复使用
//字典树

#include<iostream>
#include<vector>
using namespace std;
const int N = 1010;
int idx;
int son[N][30];


bool wordBreak(string s, vector<string>& wordDict) {
    int n = wordDict.size();
    int l = 0;
    int p = 0;
    while (l<=s.size())
    {
        string str = "";
        int index =-1;
        for(int i = 0;i <n;i++)
        {
            if (l+wordDict[i].size() <= s.size())
            {
                string subs= s.substr(l,l+wordDict[i].size());
                if (subs==wordDict[i])
                {
                    str=wordDict[i];
                    index=i;
                    break;
                }
            }
        }
        if(str=="") return false;
        if (!son[p][index])
        {
            son[p][index]=++idx;
        }
        p=son[p][index];
        l+=wordDict[index].size();
    }
    return true;
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