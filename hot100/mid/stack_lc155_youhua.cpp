//
// Created by SP on 2023/11/12.
//

#include <iostream>
#include <stack>
using namespace std;
class MinStack {
public:
    stack<int> st;
    stack<int> min_s;//不必维护所有元素，只把比当前栈顶小的入栈
    MinStack() {

    }

    void push(int val) {
        st.push(val);
        if (min_s.empty() || min_s.top() >= val){//只需要入栈比min_s小的元素
            min_s.push(val);
        }

    }

    void pop() {
        int a = st.top();
        st.pop();
        if (min_s.top()==a){//只有删除的元素在min_s栈顶时才入栈
            min_s.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return min_s.top();
    }
};

int main(){
    MinStack minStack;
    minStack.push(0);
    minStack.push(1);
    minStack.push(0);
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.top() << endl;
    cout << minStack.getMin() << endl;
    return 0;
}