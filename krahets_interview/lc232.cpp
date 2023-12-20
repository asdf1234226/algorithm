//
// Created by SP on 2023/12/14.
//

// 请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
// 实现 MyQueue 类：

// void push(int x) 将元素 x 推到队列的末尾
// int pop() 从队列的开头移除并返回元素
// int peek() 返回队列开头的元素
// boolean empty() 如果队列为空，返回 true ；否则，返回 false

#include<iostream>
#include<stack>
using namespace std;

class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {

    }
    // push的时候将最新的x放入栈底,st1作为主栈，st2作为辅助栈暂存
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
        return x;
    }

    int peek() {
        return st1.top();
    }

    bool empty() {
        return st1.empty();
    }
};

int main(){
    MyQueue q;
    cout << q.empty()<<endl;
    q.push(1);
    q.push(2);
    cout << q.peek()<<endl;
    cout << q.pop() << endl;
    cout << q.peek()<<endl;
    cout << q.empty()<<endl;
    return 0;
}