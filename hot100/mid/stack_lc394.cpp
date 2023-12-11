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

//遇到第一个数字，如果后面还是数字，要计算整数，直到遇到[
// [ 左边都是数字，右边都是字母


#include<iostream>
#include<stack>
using namespace std;

string decodeString(string s) {
    int n = s.size();
    for(int i = 0; i<n; i++){
        if(s[i]>='0' && s[i]<='9'){//计算数值
            int end = i+1;
            while (end<n && s[end]>='0' && s[end]<='9')
            {
                end++;
            }
            

        }
        else if(s[i]=='['){

        }else if (s[i]==']')
        {
            /* code */
        }else
        {
            /* code */
        }
        
    }

}

int main(){
    cout << decodeString("3[a2[c]]");
    return 0;
}

public String decodeString(String s) {
    Stack<Integer> numStack=new Stack<>();
    Stack<String> strStack=new Stack<>();
    String result="";
    int num=0;
    for(int i=0;i<s.length();i++){
        if(s.charAt(i)>='0'&&s.charAt(i)<='9'){
            num=num*10+s.charAt(i)-'0';//计算倍数
        }
        else if(s.charAt(i)=='['){
            numStack.push(num);//入栈
            num=0;//清零
            strStack.push(result);//入栈
            result="";
        }
        else if(s.charAt(i)==']'){
            String temp="";
            int times=numStack.pop();
            for(int j=0;j<times;j++){
                temp+=result;//res*出栈数字

            }
            result=strStack.isEmpty()?temp:strStack.pop()+temp;
            //加完后如果栈空则为temp，栈不为空则将刚出栈res+当前res*刚出栈数字
        }
        else {
            result+=s.charAt(i);
        }
    }
    return result;

}