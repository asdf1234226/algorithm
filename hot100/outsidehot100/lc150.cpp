// 根据 逆波兰表示法，求表达式的值。
// 有效的运算符包括 + ,  - ,  * ,  / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式

// 输入: ["2", "1", "+", "3", "*"]
// 输出: 9
// 解释: 该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

bool isCal(string a){
    return a=="+" || a=="-" || a=="*" || a=="/";
}
int evalRPN(vector<string>& tokens){
    stack<long long> st;
    for(auto str: tokens){
        if (isCal(str))//运算符
        {
            long long num1 = st.top();
            st.pop();
            long long num2 = st.top();
            st.pop();
            long long res = 0;
            if (str=="+")
            {
                res = num2+num1;
            }else if (str=="-")
            {
                res=num2-num1;//栈是倒序，所以是num2-num1
            }else if (str=="*")
            {
                res=num2*num1;
            }else
            {
                res=num2/num1;
            }
            st.push(res);
        }else//数字
        {
            st.push(stoi(str));
        }
    }
    return st.top();
}

int main(){
    vector<string> a = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << evalRPN(a);
    return 0;
}