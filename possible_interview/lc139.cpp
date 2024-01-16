
// 输入: s = "leetcode", wordDict = ["leet", "code"]
// 输出: true
// 解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。

#include<iostream>
#include<vector>
#include<set>
using namespace std;

//TODO 第一时间没想起来
//和青蛙跳台阶类似，dp[i]由dp[j]转移而来(0<j<i)，并且dp[j]=true
//dp[i]表示前i个字母
bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
    vector<bool> dp(n+1,false);
    set<string> st;
    for(auto word: wordDict){
        st.insert(word);
    }
    dp[0]=true;
    for (int i = 1; i <=n; i++)//前i个字母
    {
        for(int j=0;j<i;j++){
            //第i个字母对应下标i-1
            if(dp[j] && st.find(s.substr(j, (i-1)-j+1))!=st.end()){
                dp[i]=true;
                break;
            }
        }
    }
    return dp[n];
}

int main(){
    string s = "applepenapple";
    vector<string> a = {"apple", "pen"};
    if (wordBreak(s,a))
    {
        cout << "y";
    }else
    {
        cout << "n";
    }  
    return 0;
}