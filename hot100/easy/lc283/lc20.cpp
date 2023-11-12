//
// Created by SP on 2023/11/11.
//
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
//输入：s = "()[]{}"
//输出：true


//cnt[0], cnt[1], cnt[2]分别代表小括号，中括号，大括号
//遇到左半边，如(, cnt[0]++，右半边cnt[0]--; 任何时刻cnt都应该>=0; 如果<0 return false；
//最后遍历完后，再判断这三个是否都为0


#include <iostream>
#include <stack>
using namespace std;
bool isValidErr(string s) {  //([)]会过不了
    int cnt[3] = {0,0,0};
    for (int i = 0; i < s.size(); ++i) {
        if (cnt[0] < 0 || cnt[1] < 0 || cnt[2] <0){
            return false;
        }
        if (s[i]=='('){
            cnt[0]++;
        } else if (s[i]==')'){
            cnt[0]--;
        } else if (s[i]=='['){
            cnt[1]++;
        } else if (s[i]==']'){
            cnt[1]--;
        }else if (s[i]=='{'){
            cnt[2]++;
        } else if (s[i]=='}'){
            cnt[2]--;
        }
    }
    return cnt[0]==0 && cnt[1]==0 && cnt[2]==0;
}

bool isValid(string s) {
    //栈存储，左括号入栈，右括号找栈顶是否和该右括号匹配，不匹配直接返回false，匹配弹出栈顶
    //最后需要判断栈空，因为可能存在只有左括号的情况
    stack<char> st;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i]=='(' || s[i]== '[' || s[i] =='{'){
            st.push(s[i]);
        } else if (s[i]==')'){
            if (st.empty() || st.top()!='(') return false;
            st.pop();
        }else if (s[i]==']'){
            if (st.empty() || st.top()!='[') return false;
            st.pop();
        }else if (s[i]=='}'){
            if (st.empty() || st.top()!='{') return false;
            st.pop();
        }
    }
    return st.empty();
}

int main(){
    return 0;
}