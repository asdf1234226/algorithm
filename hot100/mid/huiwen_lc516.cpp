//
// Created by SP on 2023/11/16.
//

//给你一个字符串 s，找到 s 中最长的回文子串。
//输入：s = "babad"
//输出："bab"
//解释："aba" 同样是符合题意的答案。

#include <iostream>
#include <vector>
using namespace std;

const int N = 1010;
struct E{
    int len;
    int l;
    int r;
};

E extend(string s, int i, int j){//扩散记录子回文串长度，左右边界
    E res;
    res.len = 0;
    while (i>=0 && j<s.size() && s[i]==s[j]){
        res.l=i; //赋值要在i--之前
        res.r=j;
        res.len=j-i+1;//更新长度
        i--;
        j++;
    }
    return res;
}

//子串是连续序列
string longestPalindrome(string s) {
    int max_len = 0;
    int left = 0, right = 0;
    for (int i = 0; i < s.size(); ++i) {
        E e1 = extend(s,i,i);
        if (e1.len>max_len){//单个元素为中心扩散
            max_len=e1.len;
            left=e1.l;
            right=e1.r;
        }
        E e2 = extend(s,i,i+1);//两个元素为中心扩散
        if (e2.len>max_len){
            max_len=e2.len;
            left=e2.l;
            right=e2.r;
        }
    }
    return s.substr(left,right-left+1);

}

int main(){
    string s = "cbbd";
    cout << longestPalindrome(s);
    return 0;
}