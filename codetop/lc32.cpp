// 输入：s = ")()())"
// 输出：4
// 解释：最长有效括号子串是 "()()"

#include<iostream>
#include<vector>
using namespace std;

//dp[i]以s[i]为结尾的最长有效括号长度
//s[i]='('
//s[i]=')'  s[i-1]='('  dp[i]=dp[i-2]+2
//          s[i-1]=')'  长度是dp[i-1]，i-1-x+1=dp[i-1], dp[i-1]的start是i-dp[i-1],如果s[start-1]='(',有三段 
//                                                     dp[start-2]+dp[i-1]+2
int longestValidParentheses(string s){
    int n = s.size();
    vector<int> dp(n,0);
    for (int i = 1; i < n; i++)
    {
        if (s[i]=='(')
        {
            dp[i]=0;
        }else
        {
            if (s[i-1]=='(')
            {
                dp[i]=(i>=2?dp[i-2]:0)+2;
            }else{//s[i-1]==')'
                int start=i-dp[i-1];
                if (start-1>=0&&s[start-1]=='(')
                {
                    dp[i]=(start>=2?dp[start-2]:0)+dp[i-1]+2; 
                }
            }
        }
    }
    int ans = 0;
    for(auto it: dp){
        ans=max(ans,it);
    }
    return ans;
}
int main(){
    string s = ")(()(()(((())(((((()()))((((()()(()()())())())()))()()()())(())()()(((()))))()((()))(((())()((()()())((())))(())))())((()())()()((()((())))))((()(((((()((()))(()()(())))((()))()))())";
    cout << longestValidParentheses(s);
    return 0;
}