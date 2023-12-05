// 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
// 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
// 仅包含小写字母

// 输入: s = "cbaebabacd", p = "abc"
// 输出: [0,6]
// 解释:
// 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
// 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;


vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    vector<int> cntP(26,0);
    vector<int> cntS(26,0);
    for (int i = 0; i < p.size(); i++)
    {
        int index = p[i]-'a';
        cntP[index]++;
    }
    int start = 0;
    for (int i = 0; i < s.size(); i++)
    {
        cntS[s[i]-'a']++;
        if (i>=p.size())//固定长度的滑动窗口
        {
            cntS[s[start]-'a']--;
            start++;
        }
        if (cntP==cntS)//vector重写了==
        {
            ans.push_back(start);
        } 
    }
    return ans;
}

int main(){
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> a=findAnagrams(s,p);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}