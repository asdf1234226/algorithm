//
// Created by SP on 2023/11/7.
//
//输入：text1 = "abcde", text2 = "ace"
//输出：3
//解释：最长公共子序列是 "ace" ，它的长度为 3

#include<iostream>
#include<cstring>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();
    int f[m+1][n+1];// f[i][j]表示text1前i个字母和text2前j个字母的LCS长度
    // text1[i-1]==text2[j-1]   f[i][j] = f[i-1][j-1]+1;
    //         !=           f[i][j] = max(f[i-1][j], f[i][j-1])
    memset(f,0,sizeof f);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (text1[i-1]==text2[j-1])//第i个字母是i-1
            {
                f[i][j]=f[i-1][j-1]+1;
            }else
            {
                f[i][j]=max(f[i-1][j], f[i][j-1]);
            }
        }
    }
    return f[m][n];
    
}

int main(){
    cout << longestCommonSubsequence("abcde", "ace");
    return 0;
}