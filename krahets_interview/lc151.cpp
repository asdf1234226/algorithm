//
// Created by SP on 2023/12/14.
//

// 给你一个字符串 s ，请你反转字符串中 单词 的顺序。
// 单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
// 返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
// 注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。

// 示例 1：
// 输入：s = "the sky is blue"
// 输出："blue is sky the"
// 示例 2：
// 输入：s = "  hello world  "
// 输出："world hello"
// 解释：反转后的字符串中不能存在前导空格和尾随空格。

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

string trim(string s){
    int n = s.size();
    if(n==0) return "";
    int l = 0;
    int r = n-1;
    while (l<n&&s[l]==' ')
    {
        l++;
    }
    while (r>=0&&s[r]==' ')
    {
        r--;
    }
    return s.substr(l, r-l+1);
}

string reverseWords(string s) {
    s = trim(s);
    if (s=="")
    {
        return s;
    }
    int n = s.size();
    vector<string> res;
//    for (int i = 0; i < n; i++)
//    {
//        int j = i;
//        while (j<n && s[j]!=' ')
//        {
//            j++;
//        }
//        if(i!=j){
//            res.push_back(s.substr(i,j-i));//防止加入空串
//        }
//        i=j;//为什么不是i=j+1，因为外层for循环还有i++
//    }
     int i = 0;
     while (i<n)
     {
         int j = i;
         while (j<n && s[j]!=' ')
         {
             j++;
         }
         if(i!=j){
             res.push_back(s.substr(i,j-i));////防止加入空串
         }
         i=j+1;
     }
    reverse(res.begin(),res.end());
    string ans = "";
    for(int i = 0; i<res.size()-1;i++){
        ans+=res[i];
        ans+=" ";
    }
    ans+=res[res.size()-1];
    return ans;
}

int main(){
    string s = "a good   example";
    cout << reverseWords(s);
    return 0;
}