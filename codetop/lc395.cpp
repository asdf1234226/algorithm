// 给你一个字符串 s 和一个整数 k ，请你找出 s 中的最长子串， 要求该子串中的每一字符出现次数都不少于 k 。返回这一子串的长度。
// 如果不存在这样的子字符串，则返回 0。

// 示例 1：
// 输入：s = "aaabb", k = 3
// 输出：3
// 解释：最长子串为 "aaa" ，其中 'a' 重复了 3 次。

// 示例 2：
// 输入：s = "ababbc", k = 2
// 输出：5
// 解释：最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。

// 提示：
//     1 <= s.length <= 104
//     s 仅由小写英文字母组成
//     1 <= k <= 105

#include<iostream>
#include<vector>
using namespace std;

//判断计数是否有效
bool isValid(vector<int>& cnt, int k) {
    for (int i = 0; i < cnt.size(); i++)
    {
        if (cnt[i]==0)
        {
            continue;
        }else
        {
            if (cnt[i]<k)
            {
                return false;
            }
        }
    }
    return true;
}
//前面窗口不满足k，可能要尝试右移
int longestSubstring_err(string s, int k) {
    int n = s.size();
    vector<int> cnt(26,0);
    int st = 0;
    int ans = 0;
    for(int ed=0;ed<n;ed++){
        cnt[s[ed]-'a']++;
        while (st<ed && !isValid(cnt,k))
        {
            cnt[s[st]-'a']--;
            st++;
        }
        ans=max(ans,ed-st+1);
    }
    return ans>=k?ans:0;
}

//先固定当前窗口出现的字符种类（1-26个枚举）
//当前窗口的字符种类 > 枚举的固定值，左移
//窗口字符种类<固定值，右移
// = 固定值，并且每个字符出现的次数>=k，更新结果
int longestSubstring(string s, int k) {
    int n = s.size();
    int ans = 0;
    //example: 两个字符种类，并且都>=k的子串长度
    for (int i = 1; i <=26; i++)
    {
        vector<int> cnt(26,0);
        int st = 0;
        int kinds=0;//窗口的字符种类
        int satisfy = 0;//满足>=k的种类
        for (int ed = 0; ed < n; ed++)
        {
            int pos = s[ed]-'a';
            cnt[pos]++;
            if(cnt[pos]==1){//窗口新出现了种类
                kinds++;
            }
            if(cnt[pos]==k){//该种类满足>=k的条件
                satisfy++;
            }
            while (kinds>i)//窗口出现的种类>枚举值，应该左移
            {
                int pos2 = s[st]-'a';
                cnt[pos2]--;
                if (cnt[pos2]==0)
                {
                    kinds--;
                }
                if (cnt[pos2]==k-1)//不满足>=k
                {
                    satisfy--;
                }
                st++;
            }
            if (satisfy==i && kinds==i)//窗口的种类应该=枚举种类，并且满足>=k的种类也要=枚举种类
            {
                ans=max(ans, ed-st+1);
            }
        }
    }
    return ans>=k?ans:0;
}

int main(){
    cout << longestSubstring("ababbc",2);
    return 0;
}