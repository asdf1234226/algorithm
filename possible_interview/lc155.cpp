// 请设计一个栈，除了常规栈支持的pop与push函数以外，还支持min函数，
// 该函数返回栈元素中的最小值。执行push、pop和min操作的时间复杂度必须为O(1)。

// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> 返回 -3.
// minStack.pop();
// minStack.top();      --> 返回 0.
// minStack.getMin();   --> 返回 -2.

#include<iostream>
#include<stack>
using namespace std;
class MinStack {
public:
    stack<int> st;
    stack<int> help;
    MinStack() {

    }
    
    void push(int val) {
        st.push(val);
        if (help.empty()||help.top()>=val)
        {
            help.push(val);
        }
    }
    
    void pop() {
        if(!st.empty()&& st.top()==help.top()){
            help.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return help.top();
    }
};
