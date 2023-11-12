//
// Created by SP on 2023/11/12.
//

#include <iostream>
#include <stack>
using namespace std;
class MinStack {
public:
    stack<int> st;
    stack<int> help;//存储插入时被弹出的元素
    stack<int> min_s;//维护所有元素的单调栈
    MinStack() {

    }

    void push(int val) {
        st.push(val);
        while(!min_s.empty() && min_s.top()< val){ //栈底到栈顶4 3 2， 插入5
            help.push(min_s.top());
            min_s.pop();
        }
        min_s.push(val);
        while(!help.empty()){
            min_s.push(help.top());
            help.pop();
        }

    }

    void pop() {
        int a = top();
        st.pop();
        //去掉min_s中的a
        while(!min_s.empty() && min_s.top() != a){
            help.push(min_s.top());
            min_s.pop();
        }
        min_s.pop();
        while(!help.empty()){
            min_s.push(help.top());
            help.pop();
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
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.top() << endl;
    cout << minStack.getMin() << endl;
    return 0;
}