// 字符串表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格  。 整数除法仅保留整数部分。

// 示例 1:
// 输入: "3+2*2"
// 输出: 7
// 示例 2:
// 输入: " 3/2 "
// 输出: 1
// 示例 3:
// 输入: " 3+5 / 2 "
// 输出: 5

#include<iostream>
#include<stack>
using namespace std;

// s[i]=='1'~'9'计算数值，计算完数字，如果前面的运算符是'+'，则数字入栈，'+'弹出
//                                                   '-',数字*(-1)入栈，'-'弹出
//                                                   '*', 数字栈顶*当前数字 替换 数字栈栈顶, '*'弹出
//                                                   '/'，数字栈顶/当前数字...............
//       '+'  符号入栈 
//       '-'  ...
//       '*'  ...
//       '/'  ...

int calculate(string s){
    stack<int> st_num;
    stack<char> st_op; 
    int n = s.size();
    int i = 0;
    while (i < n)
    {
        char c = s[i];
        if (c==' ')
        {
            i++;
            continue;
        }
        else if (c>='0'&&c<='9')
        {
            int num = 0;
            while (s[i]>='0'&&s[i]<='9')
            {
                num = num*10 + (s[i]-'0');
                i++;
            }
            i--;//退出while时i位于下一个
            if (!st_op.empty())
            {
                char op = st_op.top();
                st_op.pop();
                if (op=='+')
                {
                    st_num.push(num);
                }else if (op=='-')
                {
                    st_num.push(num*(-1));
                }else if (op=='*')
                {
                    int num1 = st_num.top();
                    st_num.pop();
                    st_num.push(num1*num);
                }else
                {
                    int num1 = st_num.top();
                    st_num.pop();
                    st_num.push(num1/num);
                }
            }else
            {
                st_num.push(num);
            } 
            i++;
        }
        else
        {
            st_op.push(c);
            i++;
        }
    }
    int total = 0;
    while (!st_num.empty())
    {
        total += st_num.top();
        st_num.pop();
    }
    return total;
}

int main(){
    cout << calculate("2147483647");
    return 0;
}