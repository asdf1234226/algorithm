//
// Created by SP on 2023/11/22.
//

//给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。

//TODO 没做出来
#include <iostream>
#include <cstring>
using namespace std;
int longestValidParentheses(string s) {
    int n = s.size();
    if(n==0){
        return 0;
    }
    int dp[n+1];
    memset(dp, 0, sizeof dp);
    dp[0]=0, dp[1]=0;
    dp[2]= s[0]=='('&& s[1]==')'?2:0;
    for(int i = 3; i<=n;i++){
        if(s[i-1]==')'&&s[i-2]=='('){
            if(s[i-3]==')'){
                dp[i]=dp[i-3]+2;
            }
            else{
                dp[i]=2;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i< n+1; i++){
        ans = max(ans, dp[i]);
    }
    return ans;

}

int main(){
    string s = ")()())";
    cout << longestValidParentheses(s);
    return 0;
}