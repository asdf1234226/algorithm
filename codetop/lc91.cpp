// 一条包含字母 A-Z 的消息通过以下映射进行了 编码 ：
// 'A' -> "1"
// 'B' -> "2"
// ...
// 'Z' -> "26"
// 要 解码 已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）。例如，"11106" 可以映射为：
//     "AAJF" ，将消息分组为 (1 1 10 6)
//     "KJF" ，将消息分组为 (11 10 6)

// 示例 2：
// 输入：s = "226"
// 输出：3
// 解释：它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。

// 示例 3：
// 输入：s = "06"
// 输出：0
// 解释："06" 无法映射到 "F" ，因为存在前导零（"6" 和 "06" 并不等价）。

// 提示：
//     1 <= s.length <= 100
//     s 只包含数字，并且可能包含前导零。


#include<iostream>
#include<vector>
using namespace std;


//s[i]和s[i-1]是否能组合， s[i]记为a, s[i-1]记录为b
//如果a有效值，dp[i]可以由dp[i-1]  (1<=a<=9)
//如果b有效值，dp[i]=dp[i-1]或dp[i-2]转移来， 10<=ba<=26
   
int numDecodings(string s) {
    if (s.size()==0 || s[0]=='0')
    {
        return 0;
    }
    int n = s.size();
    vector<int> dp(n,0);
    dp[0]=1;
    for (int i = 1; i < n; i++)
    {
        int a = s[i]-'0';
        int b = (s[i-1]-'0')*10+a;
        if (a>=1 && a<=9 && b>=10 && b<=26)
        {
            dp[i]=i-2>=0?dp[i-2]+dp[i-1]:dp[i-1]+1;//如果i-2<0，那么认为dp[i-2]也是1
        }else if (a>=1 && a<=9)
        {
            dp[i]=dp[i-1];
        }else if (b>=10&&b<=26)
        {
            dp[i]=i-2>=0?dp[i-2]:1;//如果i-2<0，那么认为dp[i-2]也是1
        }else
        {
            dp[i]=0;
        }
    }
    return dp[n-1];
}

int main(){
    cout << numDecodings("16");
    return 0;
}