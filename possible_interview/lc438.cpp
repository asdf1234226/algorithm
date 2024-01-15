// 输入: s = "cbaebabacd", p = "abc"
// 输出: [0,6]
// 解释:
// 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
// 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
//s 和 p 仅包含小写字母

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> cntp(26,0);
    vector<int> cnts(26,0);
    for(auto it: p){
        cntp[it-'a']++;
    }
    int start=0;
    vector<int> res;
    for(int end=0;end<s.size();end++){
        cnts[s[end]-'a']++;
        if(end>p.size()-1){//固定长度的滑动窗口
            cnts[s[start]-'a']--;
            start++;
        }
        if(end>=p.size()-1 && cntp==cnts){ //判断长度为p.size()的滑动窗口是否满足条件
            res.push_back(start);
        }
    }
    return res;
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