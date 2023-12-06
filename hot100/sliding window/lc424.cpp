
// 给你一个字符串 s 和一个整数 k 。你可以选择字符串中的任一字符，
// 并将其更改为任何其他大写英文字符。该操作最多可执行 k 次。
//s 仅由大写英文字母组成
// 在执行上述操作后，返回 包含相同字母的最长子字符串的长度。

// 输入：s = "AABABBA", k = 1
// 输出：4
// 解释：
// 将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
// 子串 "BBBB" 有最长重复字母, 答案为 4。
// 可能存在其他的方法来得到同样的结果。


#include<iostream>
#include<cstring>
using namespace std;
// 对于合法的子串而言，必然有 sum(所有字符的出现次数) - max(出现次数最多的字符的出现次数）
// = other(其他字符的出现次数) <= k。

bool isValid(int cnt[], int k){
    int sum = 0;
    int max_cnt = 0;
    for (int i = 0; i < 26; i++)
    {
        sum += cnt[i];
        max_cnt=max(max_cnt, cnt[i]);
    }
    return sum - max_cnt <= k;
}
int characterReplacement(string s, int k) {
    int cnt[26];
    memset(cnt,0,sizeof cnt);
    int start = 0;
    int ans = 0;
    for (int end = 0; end < s.size(); end++)
    {
        cnt[s[end]-'A']++;
        while (!isValid(cnt,k))
        {
            cnt[s[start]-'A']--;
            start++;
        }
        ans=max(ans,end-start+1);
    }
    return ans;
}

int main(){
    cout << characterReplacement("AABABBA",1);
    return 0;
}