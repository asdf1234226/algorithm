//
// Created by SP on 2023/12/14.
//
// 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

// '.' 匹配任意单个字符
// '*' 匹配零个或多个前面的那一个元素
//         所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

// 示例 1：
// 输入：s = "aa", p = "a"
// 输出：false
// 解释："a" 无法匹配 "aa" 整个字符串。
// 示例 2:
// 输入：s = "aa", p = "a*"
// 输出：true
// 解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
// s 只包含从 a-z 的小写字母。
// p 只包含从 a-z 的小写字母，以及字符 . 和 *。


#include<iostream>
#include<cstring>
using namespace std;

//为了下标统一，s,p头插"0"
//dp[i][j]定义为s的前i个字母和p的前j个字母是否匹配
// 1.p[j]==字母   dp[i-1][j-1]&&s[i]=p[j]
// 2.p[j]==‘.’    dp[i-1][j-1]
// 3.p[j]=='*'    a.匹配0个  s是"0cd"，i指向d; p是"0cda*",j指向*  dp[i][j-2]
//                b.匹配1个  s是"0cda" p是"0cda*"   dp[i-1][j-2]&&s[i]和p[j-1]匹配
//                                                 dp[i-1][j-2]对应s和p的"0cd"要相同，s[i]和p[j-1]匹配，对应s和p中的a
//                c.匹配2个  s是"0cdaa",p是"0cda*"  dp[i-2][j-2]&&s[i]和p[j-1]匹配&&s[i-1]和p[j-1]匹配
// 归纳得到f(i,j)=f(i,j-2)|| f(i-1,j-2)&&s[i]匹配p[j-1] || f(i-2,j-2)&&s[i]和s[i-1]匹配p[j-1]....
// i-1替换i得
// f(i-1,j)=f(i-1,j-2)||f(i-2,j-2)&&s[i-1]匹配p[j-1] || f(i-3,j-2)&&s[i-1]和s[i-2]匹配p[j-1]...
// 错位后发现f(i,j)除了第一项外，其他所有项都比f(i-1,j)的对应项多s[i]匹配p[j-1]
// 所以f(i,j)=f(i,j-2)||f(i-1,j)&&s[i]匹配p[j-1]
// s[i]匹配p[j-1]又可以写成s[i]==p[j-1] || p[j-1]='.'

bool isMatch(string s, string p) {
    s ="0"+s;
    p="0"+p;
    int m = s.size();
    int n = p.size();
    //dp[i][j]定义为s的前i个字母和p的前j个字母是否匹配
    bool dp[m+1][n+1];
    memset(dp,0,sizeof dp);
    dp[0][0]=true;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
        // 如果下一个字符是 '*'，则代表当前字符不能被单独使用，跳过
            if (j+1<=n && p[j+1]=='*' && p[j]!='*')
            {
                continue;
            }          
            if (p[j]=='.')
            {
                dp[i][j]=dp[i-1][j-1];        
            }else if (p[j]=='*')
            {
                dp[i][j]=(j-2>=0)&& dp[i][j-2] || (dp[i-1][j] && (s[i]==p[j-1]||p[j-1]=='.'));
            }else//p[j]是字母
            {
                dp[i][j]=dp[i-1][j-1]&&s[i]==p[j];
            }                  
        }
    }
    return dp[m][n];  
}

int main(){
    if (isMatch("cdaa","cda*"))
    {
        cout << "match";
    }
    return 0;
}


// class Solution {
//     public boolean isMatch(String ss, String pp) {
//         // 技巧：往原字符头部插入空格，这样得到 char 数组是从 1 开始，而且可以使得 f[0][0] = true，可以将 true 这个结果滚动下去
//         int n = ss.length(), m = pp.length();
//         ss = " " + ss;
//         pp = " " + pp;
//         char[] s = ss.toCharArray();
//         char[] p = pp.toCharArray();
//         // f(i,j) 代表考虑 s 中的 1~i 字符和 p 中的 1~j 字符 是否匹配
//         boolean[][] f = new boolean[n + 1][m + 1];
//         f[0][0] = true;
//         for (int i = 0; i <= n; i++) {
//             for (int j = 1; j <= m; j++) {
//                 // 如果下一个字符是 '*'，则代表当前字符不能被单独使用，跳过
//                 if (j + 1 <= m && p[j + 1] == '*' && p[j] != '*') continue;
                
//                 // 对应了 p[j] 为普通字符和 '.' 的两种情况
//                 if (i - 1 >= 0 && p[j] != '*') {
//                     f[i][j] = f[i - 1][j - 1] && (s[i] == p[j] || p[j] == '.');
//                 } 
                
//                 // 对应了 p[j] 为 '*' 的情况
//                 else if (p[j] == '*') {
//                     f[i][j] = (j - 2 >= 0 && f[i][j - 2]) || (i - 1 >= 0 && f[i - 1][j] && (s[i] == p[j - 1] || p[j - 1] == '.'));
//                 }
//             }
//         }
//         return f[n][m];
//     }
// }
