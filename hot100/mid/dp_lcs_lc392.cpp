// 给定字符串 s 和 t ，判断 s 是否为 t 的子序列
// 输入：s = "abc", t = "ahbgdc"
// 输出：true

//求LCS长度是否等于短的长度就行

#include<iostream>
#include<cstring>
using namespace std;

//非连续，只需要定义前i个字母，和前j个字母，不要求结尾

bool isSubsequence(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int dp[m+1][n+1];
    memset(dp,0,sizeof dp);
    dp[0][0]=0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i-1]==t[j-1])//第i个字母下标i-1
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }else
            {
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);//s[i-1]不在或t[j-1]不在
            }
            
        }  
    }
    return dp[m][n]==min(m,n);   
}

//双指针简单遍历也可以
bool isSubsequence_easy(string s, string t){
    int m = s.size();
    int n = t.size();
    if(m==0) return true;
    int i=0,j=0;
    while (i<m && j<n)
    {
        if (s[i]==s[j])
        {
            i++;
            j++;
        }else
        {
            j++;
        }
    }
    return i==m;
}

int main(){
    string s = "abc";
    string t = "ahbgdc";
    if (isSubsequence_easy(s,t))
    {
        cout << "y";
    }else
    {
        cout << "no";
    }
    
    
    return 0;
}