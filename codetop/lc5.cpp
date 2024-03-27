// 输入：s = "babad"
// 输出："bab"
// 解释："aba" 同样是符合题意的答案

#include<iostream>
using namespace std;

struct E {
    int l;
    int r;
    int len;
};

//以x,y为中心的最长回文子串长度
E help(string s, int x, int y){
    E e;
    e.len=0;
    while (x>=0 && y<s.size())
    {
        if (s[x]==s[y])
        {
            e.len=y-x+1;
            e.l=x;
            e.r=y;
            x--;
            y++;    
        }else
        {
            break;
        }
    }
    return e;
}
string longestPalindrome(string s){
    int n = s.size();
    int maxlen = 0;
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        E e1 = help(s,i,i+1);
        E e2 = help(s,i,i);
        if (e1.len>maxlen)
        {
            start=e1.l;
            maxlen=e1.len;
        }
        if (e2.len>maxlen)
        {
            start=e2.l;
            maxlen=e2.len;
        }
    }
    return s.substr(start, maxlen);
    
}


int main() {
    cout << longestPalindrome("babad");
    return 0;
}
