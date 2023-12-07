// 给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
// 在 S 上反复执行重复项删除操作，直到无法继续删除。
// 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一

// 输入："abbaca"
// 输出："ca"
// 解释：例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作
// 的重复项。之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。

#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

string removeDuplicates(string S){
    stack<char> st;
    for(int i = 0;i < S.size(); i++){
        if (st.empty() || st.top()!=S[i])//只有栈空，或者和栈顶不同时才会push
        {
            st.push(S[i]);
        }
        else//栈不空且和栈顶元素相同
        {
            st.pop();
        }
    }
    string res = "";
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    string s = "abbaca";
    cout << removeDuplicates(s);
    return 0;
}