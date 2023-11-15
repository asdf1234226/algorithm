
#include<iostream>
#include<vector>
#include<set>
using namespace std;

//字符串 s 和一个字符串列表 wordDict 作为字典。
//请你判断是否可以利用字典中出现的单词拼接出 s , 字典中的单词可以重复使用


//完全背包问题，背包是否能装满（是否存在某种排列能将背包装满）
//外层背包s.size()，内层物品，但是这个物品的体积不太好搞

//dp[i]表示前i个字母能否拼接
// dp[j] && s.substr(j,i-j+1)在字典中
bool wordBreak(string s, vector<string>& wordDict) {
    set<string> st(wordDict.begin(), wordDict.end());
    int n = wordDict.size();
    bool dp[n+1];
    dp[0]= true;
    for(int i = 1; i<= s.size(); i++){
        for (int j = 0; j < i; j++)
        {
            //第i个字母对应下标i-1
            if (dp[j]&& st.find(s.substr(j,i-1-j+1))!=st.end())
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

//背包总结
//https://programmercarl.com/%E8%83%8C%E5%8C%85%E6%80%BB%E7%BB%93%E7%AF%87.html#%E6%80%BB%E7%BB%93