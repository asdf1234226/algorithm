//
// Created by SP on 2023/11/22.
//

//给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

//方法一：栈
//括号匹配问题，一般用栈，
//先找到所有可以匹配的索引号，然后找出最长连续数列！

// 例如：s = )(()())，
// 位置 2 和位置 3 匹配，
// 位置 4 和位置 5 匹配，
// 位置 1 和位置 6 匹配，
// 这个数组为：2,3,4,5,1,6 这是通过栈找到的，我们按递增排序 1,2,3,4,5,6
// 找出该数组的最长连续数列的长度就是最长有效括号长度！

//是否可以弹栈时优化为O(n)？？



////方法二，动态规划
// 我们用 dp[i] 表示以 i 结尾的最长有效括号；

// 当 s[i] 为 (,dp[i] 必然等于 0，因为不可能组成有效的括号；

// 那么 s[i] 为 )

// 2.1 当 s[i-1] 为 (，那么 dp[i] = dp[i-2] + 2；

// 2.2 当 s[i-1] 为 ) 并且 s[i-dp[i-1] - 1] 为 (，那么 dp[i] = dp[i-1] + 2 + dp[i-dp[i-1]-2]；

// 时间复杂度：O(n)


int longestValidParentheses(string s) {
    int n = s.size();
    if(n==0){
        return 0;
    }
    vector<int> res;
    stack<int> st;
    for(int i=0;i<s.size();i++){
        if (s[i]=='(')
        {
            st.push(i);
        }else//s[i]==')'
        {
            if(!st.empty()){
                //添加匹配的'('和')'的位置
                if (st.top()<0 || i <0){
                    cout << "t " << st.top() << " i " << i;
                }
                res.push_back(st.top());
                st.pop();
                res.push_back(i);
            }
        }
    }
    sort(res.begin(), res.end());
    //求res数组中最长连续序列的长度
    if (res.size()==0)
    {
        return 0;
    }
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i]<< " ";
    }
    int len = 1;
    int ans = 0;
    for (int i = 1; i < res.size(); i++)
    {
        if(res[i]-res[i-1]==1){
            len++;
            ans=max(len,ans);
        }else
        {
            len=1;
        }
    }
    return ans;
}

//方法二，动态规划
int longestValidParentheses_dp(string s) {
    int n = s.size();
    if(n==0) return 0;
    //dp[i]是以i为结尾的最长有效括号长度
    int dp[n];
    memset(dp, 0, sizeof dp);
    for(int i =1;i<n;i++){
        if(s[i]=='('){
            continue;
        }else//s[i]==')'
        {
            if (s[i-1]=='(')
            {
                dp[i]=i-2>=0?dp[i-2]+2:2;
            }else
            {//s[i-1]==')'
                //以i-1为结尾的最长有效括号长度是dp[i-1]，记为str,所以str左边index还是'('，就能和s[i]匹配
                //(i-1)-(index+1)+1=dp[i-1]==>index= i-1-dp[i-1], index+1是str的开头
                //三部分组成，str的长度，str左边和s[i]组成的+2, str左边的左边为结尾的有效括号长度
                if (i-1-dp[i-1]>=0 && s[i-1-dp[i-1]]=='(')
                {
                    dp[i]=dp[i-1]+2+(i-2-dp[i-1]>=0?dp[i-2-dp[i-1]]:0);
                }  
            }  
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans=max(ans,dp[i]);
    }
    return ans;
}

int main(){
    string s = ")(()(()(((())(((((()()))((((()()(()()())())())()))()()()())(())()()(((()))))()((()))(((())()((()()())((())))(())))())((()())()()((()((())))))((()(((((()((()))(()()(())))((()))()))())";
    cout << longestValidParentheses(s);
    return 0;
}