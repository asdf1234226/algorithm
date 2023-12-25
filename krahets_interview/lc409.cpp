//
// Created by SP on 2023/12/21.
//

// 给定一个包含大写字母和小写字母的字符串 s ，返回 通过这些字母构造成的 最长的回文串 。
// 在构造过程中，请注意 区分大小写 。比如 "Aa" 不能当做一个回文字符串。
// 示例 1:

// 输入:s = "abccccdd"
// 输出:7
// 解释:
// 我们可以构造的最长的回文串是"dccaccd", 它的长度是 7

#include<iostream>
#include<map>
using namespace std;
int longestPalindrome(string s) {
    int n = s.size();
    map<char, int> mp;
    for(int i=0;i<n;i++){
        mp[s[i]]++;
    }
    int ans = 0;
    bool hasOdd = false;
    for(auto it: mp){
        if (it.second%2==0)
        {
            ans += it.second;
        }else
        {
            if(!hasOdd){//只添加一个奇数
                ans += it.second;
                hasOdd=true;
            }else//剩余的奇数向下取偶数添加
            {
                ans+=(it.second/2)*2;
            }
        }
    }
    return ans;
}

int main(){
    return 0;
}