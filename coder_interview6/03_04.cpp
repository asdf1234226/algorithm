// 实现一个MyQueue类，该类用两个栈来实现一个队列。
// 示例：
// MyQueue queue = new MyQueue();
// queue.push(1);
// queue.push(2);
// queue.peek();  // 返回 1
// queue.pop();   // 返回 1
// queue.empty(); // 返回 false

#include<iostream>
#include<stack>
using namespace std;

class MyQueue {
public:
    // 1 2 3  
    stack<int> st1;
    stack<int> st2;
    MyQueue() {

    }
    
    void push(int x) {
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);
        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        int x = st1.top();
        st1.pop();
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        return st1.empty();
    }
};