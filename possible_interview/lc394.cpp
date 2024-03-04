//输入：s = "3[a2[c]]"
//输出："accaccacc"
// 输入：s = "2[abc]3[cd]ef"
// 输出："abcabccdcdcdef"
// 输入：s = "3[a]2[bc]"
// 输出："aaabcbc"
//s 由小写英文字母、数字和方括号 '[]' 组成

#include<iostream>
#include<stack>
using namespace std;

//s[i]的可能取值
//     数字，计算（可能前面也有数字）
//     字母  拼接字符串
//     [    数字入栈，sum清空; 字符串入栈，清空
//     ]    出栈数字i，将当前字符串重复i倍，加上字母栈顶（如果有的话）

string decodeString(string s) {
    int n = s.size();
    stack<string> st_s;
    stack<int> st_num;
    int sum = 0;
    string res = "";
    for(int i=0;i<n;i++){
        if(s[i]>='0' && s[i]<='9'){
            sum=sum*10+s[i]-'0';
        }
        else if (s[i]>='a'&&s[i]<='z')
        {
            res +=s[i];
        }else if (s[i]=='[')
        {
            st_num.push(sum);
            sum = 0;
            st_s.push(res);
            res="";
        }else{// s[i]==']'
            string str = "";
            int times = 0;
            if (!st_num.empty())
            {
                times = st_num.top();
                st_num.pop();
            }
            for(int i=0;i<times;i++){
                str+=res;
            }
            if (!st_s.empty())
            {
                res=st_s.top()+str;
                st_s.pop();
            }else
            {
                res=str;
            }
        }
    }
    return res;
}

int main(){
    cout << decodeString("3[a]2[bc]");
    return 0;
}