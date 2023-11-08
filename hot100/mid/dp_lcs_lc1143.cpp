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
    int f[m][n];// f[i][j]表示text1到i为止和text2到j为止的LCS长度
    // text1[i]==text2[j]   f[i][j] = f[i-1][j-1]+1;
    //         !=           f[i][j] = max(f[i-1][j], f[i][j-1])
    memset(f,0,sizeof f);
    if (text1[0]==text2[0])
    {
        f[0][0]=1;
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (text1[i]==text2[j])
            {
                f[i][j]=f[i-1][j-1]+1;
            }else
            {
                f[i][j]=max(f[i-1][j], f[i][j-1]);
            }
        }
    }
    return f[m-1][n-1];
    
}

int main(){
    cout << longestCommonSubsequence("abcde", "ace");
    return 0;
}