// 输入：s = ")()())"
// 输出：4
// 解释：最长有效括号子串是 "()()"

#include<iostream>
#include<vector>
using namespace std;

//dp[i]是s[i]下标结尾的最长有效括号长度
// s[i] == ')'时 s[i-1]== '('时， dp[i]=dp[i-2]+2;
//                     == ')'时， 如果dp[i-1]这个子串左边的是'('才行   i-1-start+1=dp[i-1], start=i-dp[i-1]
//                                                     所以要判断s[start-1]是不是'('，是的话就有三段
// s[i] == '(' 0

//不熟练，有bug
int longestValidParentheses(string s) {
    int n = s.size();
    vector<int> dp(n,0);
    for (int i = 1; i < n; i++)
    {
        if (s[i]==')')
        {
            if (i>=2 && s[i-1]=='(')
            {
                dp[i]=dp[i-2]+2;
            }
            if (i>=2 && s[i-1]==')')
            {
                if (i-dp[i-1]-1>=0&& s[i-dp[i-1]-1]=='(')
                {
                    int before = i-dp[i-1]-2>=0?dp[i-dp[i-1]-2]:0;
                    dp[i]=before+dp[i-1]+2;
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