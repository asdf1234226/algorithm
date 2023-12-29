// 堆盘子。设想有一堆盘子，堆太高可能会倒下来。因此，在现实生活中，
// 盘子堆到一定高度时，我们就会另外堆一堆盘子。请实现数据结构SetOfStacks
// ，模拟这种行为。SetOfStacks应该由多个栈组成，并且在前一个栈填满时新建一个栈。
// 此外，SetOfStacks.push()和SetOfStacks.pop()应该与普通栈的操作方法相同（
// 也就是说，pop()返回的值，应该跟只有一个栈时的情况一样）。 
// 进阶：实现一个popAt(int index)方法，根据指定的子栈，执行pop操作。

// 当某个栈为空时，应当删除该栈。当栈中没有元素或不存在该栈时，pop，
// popAt 应返回 -1.

// 示例1:
//  输入：
// ["StackOfPlates", "push", "push", "popAt", "pop", "pop"]
// [[1], [1], [2], [1], [], []]
//  输出：
// [null, null, null, 2, 1, -1]

// 示例2:
//  输入：
// ["StackOfPlates", "push", "push", "push", "popAt", "popAt", "popAt"]
// [[2], [1], [2], [3], [0], [0], [0]]
//  输出：
// [null, null, null, null, 2, 1, 3]


#include<iostream>
#include<stack>
#include<map>
using namespace std;

class StackOfPlates {
public:
    int capacity;
    int idx; //已经操作到第几个stack
    map<int, stack<int>> mp;
    StackOfPlates(int cap) {
        capacity = cap;
        idx = 0;
        stack<int> st0;
        mp[0]=st0;
    }
    
    void push(int val) {
        if(mp[idx].size()==capacity)//已经满了
        {
            idx++;
            stack<int> newst;//开新栈
            mp[idx]=newst;
        }else
        {
            mp[idx].push(val);
        }
    }
    
    int pop() {
        if (mp[idx].empty())//所在栈空了，尝试找下一个栈
        {
            idx--;
            if (idx>=0)
            {
                int x = mp[idx].top();
                mp[idx].pop();
                return x;
            }else
            {
                return -1;
            }
        }else
        {
            int x = mp[idx].top();
            mp[idx].pop();
            return x;
        }
        
    }
    
    //如果popAt所在的index空了，是等价于pop()?
    int popAt(int index) {
        // if (index>idx)   //index不合规怎么办？
        // {
        //     /* code */
        // }
        
    }
};