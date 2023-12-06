// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
// s 由英文字母、数字、符号和空格组成

// 输入: s = "pwwkew"
// 输出: 3
// 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串


#include<iostream>
#include<map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    map<char, int> mp;
    int start=0;
    int ans = 0;
    for (int end =0;end<s.size();end++)
    {
        char c = s[end];
        mp[c]++;//如果c在mp中不存在，那么mp[c]会被初始化为0
        while(mp[c]>1){//直到窗口合法
            mp[s[start]]--;
            start++;
        }
        ans=max(ans,end-start+1);
    }
    return ans;
}

int main(){
    string s = "pwwkew";
    cout << lengthOfLongestSubstring(s);
    return 0;

}