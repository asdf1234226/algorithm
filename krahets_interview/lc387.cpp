//
// Created by SP on 2023/12/21.
//

// 给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。
// 示例 2:

// 输入: s = "loveleetcode"
// 输出: 2

#include<iostream>
#include<cstring>
using namespace std;

int firstUniqChar(string s) {
    int n = s.size();
    if (n==0)
    {
        return -1;
    }
    int count[26];
    memset(count,0,sizeof count);
    for (int i = 0; i < n; i++)
    {
        count[s[i]-'a']++;
    }
    for(int i=0;i<n;i++){
        if(count[s[i]-'a']==1){
            return i;
        }
    }
    return -1;
}

int main(){
    cout << firstUniqChar("loveleetcode");
    return 0;
}