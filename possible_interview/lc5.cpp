// 输入：s = "babad"
// 输出："bab"
// 解释："aba" 同样是符合题意的答案

#include<iostream>
using namespace std;
//回文子串长度要么是奇数，要么是偶数
// 奇数都能由s[i]中心扩散，偶数由s[i]和s[i+1]中心扩散(s[i]==s[i+1])
struct E{
    int l;
    int r;
    int len;
};

E help(string s, int i, int j){
    E res;
    int n = s.size();
    while (i>=0&&j<n)
    {
        if(s[i]==s[j]){
            res.l=i;
            res.r=j;
            i--;
            j++;
        }else
        {
            break;
        }
    }
    res.len=res.r-res.l+1;
    return res;
}
string longestPalindrome(string s) {
    int n = s.size();
    if(n==0) return s;
    int minLen = 0;
    int startIndex = -1;
    for (int i = 0; i < n; i++)
    {
        E e = help(s,i,i);
        if(e.len>minLen){
            minLen=e.len;
            startIndex=e.l;
        }
        if(i+1<n){
            E e2 = help(s,i,i+1);
            if (e2.len>minLen)
            {
                minLen=e2.len;
                startIndex=e2.l;
            }
        }
    }
    return s.substr(startIndex,minLen);
}

int main(){
    string s = "babad";
    cout << longestPalindrome(s);
    return 0;
}