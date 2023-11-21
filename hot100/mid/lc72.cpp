//
// Created by SP on 2023/11/12.
//

// 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数
// 你可以对一个单词进行如下三种操作：
// 插入一个字符
// 删除一个字符
// 替换一个字符

// 输入：word1 = "horse", word2 = "ros"
// 输出：3
// 解释：
// horse -> rorse (将 'h' 替换为 'r')
// rorse -> rose (删除 'r')
// rose -> ros (删除 'e')

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

//dp[i][j]  连续，word1的前i个字母， word2的前j个字母的最小距离,所以只和i-1,j-1有关
// word1[i-1]==word2[j-1] 不需要操作
// word1[i-1]!=word2[j-1]
//                a.word1添加 dp[i][j-1]+1    和word2删除一个 操作数相同 
//        word1="aef" word2="aefb", 在经过一系列操作后,word1的前半段和word2的前半段相同，即"aef"
//        word1添加b后二者相同；word2删除b二者后也相同，这两种方案操作数都是1，所以等价
//                b.word1替换 dp[i-1][j-1]+1
//                c.word1删除 dp[i-1][j]+1
int minDistance(string word1, string word2){
    int m = word1.size();
    int n = word2.size();
    int dp[m+1][n+1];
    memset(dp, 0x3f, sizeof dp);
    dp[0][0]=0;
    for (int i = 1; i <= m; i++)
    {
        dp[i][0]=i;//word1的前i个字母要删除i次变成空的word2
    }
    for (int j = 1; j <= n; j++)
    {
        dp[0][j]=j;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (word1[i-1]==word2[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }else
            {
                dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j], dp[i][j-1]))+1;
            }
        } 
    }
    return dp[m][n];
    
}

int main(){
    string s = "horse";
    string t = "ros";
    cout << minDistance(s,t);
    return 0;
}