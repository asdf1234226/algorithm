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
#include<vector>
using namespace std;

//vector<stack<int>> 来模拟
class StackOfPlates {
public:
    vector<stack<int>> vec;
    int capacity;
    StackOfPlates(int cap) {
        capacity=cap;
    }
    
    void push(int val) {
        if (capacity==0)//判断容量为0的特殊情况
        {
            return;
        }
        if (vec.empty() || vec.back().size()==capacity)
        //没栈要新建栈; vec中最后一个栈满了也要新建栈
        {
            stack<int> a;
            vec.push_back(a);
        }
        vec.back().push(val);//应该操作的栈
    }
    
    int pop() {
        if (vec.empty())
        {
            return -1;
        }else
        {
            stack<int>& st = vec.back(); //不能在副本上操作，对vec没影响
            int x = st.top();
            st.pop();
            if (st.empty())//如果当前操作栈空了要删除
            {
                vec.pop_back();
            }
            return x;
        }
    }
    
    //如果popAt所在的index空了，是等价于pop()?
    int popAt(int index) {
        if (index<0 || index>=vec.size())
        {
            return -1;
        }
        if (vec.empty())
        {
            return -1;
        }
        stack<int>& st = vec[index];
        int x = st.top();
        st.pop();
        if (st.empty())
        {
            vec.erase(vec.begin()+index);
        }
        return x;
    }
};

int main(){
    StackOfPlates a(1);
    a.push(1);
    a.push(2);
    cout << a.popAt(1);
    cout << a.pop();
    cout << a.pop();
    return 0;
}