// 输入: s = "leetcode", wordDict = ["leet", "code"]
// 输出: true
// 解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。

//wordDict中元素可多次使用
//dp[i]由dp[j]转移而来，dp[j]=true并且（i~j）是dict中的单词
#include<iostream>
#include<vector>
#include<set>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict){
    int n = s.size();
    vector<bool> dp(n+1,false);
    dp[0]=true;
    set<string> st;
    for(auto it: wordDict){
        st.insert(it);
    }
    //dp[i]=true 前i个字母可以组成, dp[i]由于dp[j]==true并且前j+1到前i个的子串在字典中
    //                                                      [j+1-1,i-1]
    for (int i = 1; i <= n; i++)
    {
        for(int j = 0;j<=i;j++){
            string str = s.substr(j,(i-1)-j+1);
            if (dp[j]&&st.find(str)!=st.end())
            {
                dp[i]=true;
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