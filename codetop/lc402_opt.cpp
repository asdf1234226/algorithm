// 给你一个以字符串表示的非负整数 num 和一个整数 k ，移除这个数中的 k 位数字，使得剩下的数字最小。
// 请你以字符串形式返回这个最小的数字。

// 输入：num = "1432219", k = 3
// 输出："1219"
// 解释：移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219

// 输入：num = "10200", k = 1
// 输出："200"
// 解释：移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。

#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

//单调栈,要去除的是逆序对（4,3）这种，保留的就是正序
//构造一个单调递增栈(栈底到栈顶)
string removeKdigits(string num, int k) {
    stack<int> st;
    for (int i = 0; i < num.size(); i++)
    {
        while (!st.empty() && k >0 && num[i] < num[st.top()])
        {
            st.pop();
            k--;
        }
        st.push(i);
    }
    //如果还需要移除更多数字
    while (!st.empty() && k>0)
    {
        k--;
        st.pop();
    }
    //栈空，返回"0"
    if (st.empty())
    {
        return "0";
    }
    string res = "";
    while (!st.empty())
    {
        res += num[st.top()];
        st.pop();
    }
    //栈是倒序，需要反转
    reverse(res.begin(), res.end());
    // 移除结果字符串前面的所有零
    int start = 0;
    while (start < res.size() && res[start] == '0') {
        start++;
    }
    res=res.substr(start);
    return res.empty() ? "0" : res; // 如果移除前导零后的字符串为空，则返回"0"
}

int main(){
    cout << removeKdigits("1432219", 5);
    return 0;
}