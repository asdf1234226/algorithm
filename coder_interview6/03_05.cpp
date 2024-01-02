// 栈排序。 编写程序，对栈进行排序使最小元素位于栈顶。
// 最多只能使用一个其他的临时栈存放数据，但不得将元素复制到别的数据结构（如数组）中。
// 该栈支持如下操作：push、pop、peek 和 isEmpty。当栈为空时，peek 返回 -1

//  输入：
// ["SortedStack", "push", "push", "peek", "pop", "peek"]
// [[], [1], [2], [], [], []]
//  输出：
// [null,null,null,1,null,2]

#include<iostream>
#include<stack>
using namespace std;

class SortedStack {
public:
    stack<int> st;
    stack<int> help;
    SortedStack() {

    }
    
    void push(int val) {
        while (!st.empty() && st.top()<val)//大的要放栈底
        {
            help.push(st.top());
            st.pop();
        }
        st.push(val);
        while (!help.empty())
        {
            st.push(help.top());
            help.pop();
        }
    }
    
    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }
    
    int peek() {
        if (st.empty()) {
            return -1;
        }
        return st.top();
    }
    
    bool isEmpty() {
        return st.empty();
    }
};
