//
// Created by SP on 2023/11/12.
//

//输入：s = "3[a2[c]]"
//输出："accaccacc"
// 输入：s = "2[abc]3[cd]ef"
// 输出："abcabccdcdcdef"
// 输入：s = "3[a]2[bc]"
// 输出："aaabcbc"
//s 由小写英文字母、数字和方括号 '[]' 组成

//遍历字符c
// c为数字，要计算数字num，用于倍数计算
// c为字母，res尾部添加c
// c为 [ 将当前 num 和 res入栈，并置空
// c 为 ] 出栈，拼接res=last_res+num x [...]字符串, last_res是上个 [ 到当前 [的字符串，"3[a2[c]]" 中的 a
// num是 字符串重复倍数，如"3[a2[c]]" 中的 2


#include<iostream>
#include<stack>
using namespace std;

string decodeString(string s) {
    int n = s.size();
    int num = 0;
    string res = "";
    stack<int> numst;
    stack<string> strst;
    for(int i = 0; i<n; i++){
        if(s[i]>='0' && s[i]<='9'){//计算数值
            num=num*10+s[i]-'0';
        }
        else if(s[i]=='['){
            numst.push(num);//倍数
            num=0;
            strst.push(res);
            res="";
            
        }else if (s[i]==']')//"3[a2[c]]"的第一个 ] 时，res=c, numst存了{3,2}， strst存了{a}
        {
            int times = numst.top();
            numst.pop();
            string tmp = "";
            for (int j = 0; j < times; j++)//乘倍数变成cc，numst变成{3},strst还是{a}
            {
                tmp+=res;
            }
            if (!strst.empty())
            {
                res=strst.top()+tmp;//拼接a，res变成acc, numst还是{3}，strst变成{}
                strst.pop();
            }
            else
            {
                res=tmp;
            }
            
        }else//字母
        {
            res+=s[i];
        }
    }
    return res;
}

int main(){
    cout << decodeString("3[a]2[bc]");
    return 0;
}
