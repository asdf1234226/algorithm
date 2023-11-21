//
// Created by SP on 2023/11/16.
//

//给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
//具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
//
//输入：s = "aaa"
//输出：6
//解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"

#include <iostream>
using namespace std;

//i,j作为中心点的回文子串个数（j=i或j=i+1）
int extend(string s, int i, int j){
    int res = 0;
    while (i>=0&&j<s.size()&&s[i]==s[j]){
        i--;
        j++;
        res++;
    }
    return res;
}
int countSubstrings(string s) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans += extend(s,i,i);//以一个元素作为中心点
        ans +=extend(s,i,i+1);//以两个元素作为中心点
    }
    return ans;
}


int main(){
    string s = "aaa";
    cout << countSubstrings(s);
    return 0;

}