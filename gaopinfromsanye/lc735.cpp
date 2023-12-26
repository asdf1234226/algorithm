// 给定一个整数数组 asteroids，表示在同一行的行星。
// 对于数组中的每一个元素，其绝对值表示行星的大小，正负表示行星的移动方向（正表示向右移动，负表示向左移动）。
// 每一颗行星以相同的速度移动，找出碰撞后剩下的所有行星。
// 碰撞规则：
// 两个行星相互碰撞，较小的行星会爆炸。
// 如果两颗行星大小相同，则两颗行星都会爆炸。
// 两颗移动方向相同的行星，永远不会发生碰撞。


// 输入：asteroids = [5,10,-5]
// 输出：[5,10]
// 解释：10 和 -5 碰撞后只剩下 10 。 5 和 10 永远不会发生碰撞。
// 示例 2：

// 输入：asteroids = [8,-8]
// 输出：[]
// 解释：8 和 -8 碰撞后，两者都发生爆炸。
// 示例 3：

// 输入：asteroids = [10,2,-5]
// 输出：[10]
// 解释：2 和 -5 发生碰撞后剩下 -5 。10 和 -5 发生碰撞后剩下 10 。

//[10,-2,3,-4,5]
//[10,5]

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

//如果一个向左移动的小行星在向右移动的小行星之前，这两个小行星实际上不会碰撞
//两个小行星大小相同，那么两者都应该被销毁
vector<int> asteroidCollision_err(vector<int>& asteroids) {
    int n = asteroids.size();
    vector<int> ans;
    if (n==0) return ans;//特殊情况

    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int tmp = asteroids[i];
        while (!st.empty())
        {
            int top = st.top();
            st.pop();
            if (top*asteroids[i]<0)//异号会相撞
            {
                tmp = abs(top)>abs(asteroids[i])?top:asteroids[i];   
            }else
            {
                break;
            }
        }
        st.push(tmp);
    }
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

//从前往后处理，使用栈存储当前未被抵消的行星
//栈顶元素向右，并且当前行星向左才会抵消
vector<int> asteroidCollision(vector<int>& asteroids) {
    int n = asteroids.size();
    stack<int> st;
    for (int i = 0; i < n; i++)
    {   
        if (asteroids[i]>0) //当前行星向右
        {
            st.push(asteroids[i]);
        }else
        {
            //是否存活
            bool alive = true;
            while (alive && !st.empty() && asteroids[i]<0 && st.top()>0)//抵消
            {
                alive = abs(asteroids[i])>st.top(); //只有比栈顶的绝对值大才能存活
                if (abs(asteroids[i])>=st.top()) //栈顶要被粉碎-- 栈顶绝对值小于或者等于 
                {
                    st.pop();
                }
                //如果栈顶大于当前行星，那么只需要将当前行星加入就可以
            }
            if (alive)
            {
                st.push(asteroids[i]);
            }
        }
    }
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

std::vector<int> asteroidCollision_1(std::vector<int>& asteroids) {
    std::stack<int> stack;
    for (int asteroid : asteroids) {
        if (asteroid > 0) {
            stack.push(asteroid);
        } else {
            bool alive = true;
            while (alive && !stack.empty() && stack.top() > 0) {
                alive = stack.top() < std::abs(asteroid);
                if (stack.top() <= std::abs(asteroid)) {
                    stack.pop();
                }
            }
            if (alive) {
                stack.push(asteroid);
            }
        }
    }
    std::vector<int> ans(stack.size());
    for (int i = stack.size() - 1; i >= 0; --i) {
        ans[i] = stack.top();
        stack.pop();
    }
    return ans;
}


int main(){
    vector<int> a = {10,2,-5};
    vector<int> res = asteroidCollision(a);
    for(auto i : res){
        cout << i << " ";
    }
    return 0;
}

// 从前往后处理所有的 ，使用栈存储当前未被抵消的行星，当栈顶元素方向往右，
// 当前  方向往左时，会发生抵消操作，抵消过程根据规则进行即可

//     vector<int> asteroidCollision(vector<int>& asteroids) {
//         deque<int> d;
//         for (int t : asteroids) {
//             bool ok = true;
//             while (ok && !d.empty() && d.back() > 0 && t < 0) {
//                 int a = d.back(), b = -t;
//                 if (a <= b) d.pop_back();
//                 if (a >= b) ok = false;
//             }
//             if (ok) d.push_back(t);
//         }
//         vector<int> ans(d.begin(), d.end());
//         return ans;
//     }


    // public int[] asteroidCollision(int[] asteroids) {
    //     Deque<Integer> stack = new ArrayDeque<>();
    //     for (int asteroid : asteroids) {
    //         //大于0 直接入栈
    //         if (asteroid > 0) {
    //             stack.push(asteroid);
    //         } else {
    //             //是否存活
    //             boolean alive = true;
    //             //当前元素存活 并且栈不是空 并且栈顶元素大于0
    //             while (alive && !stack.isEmpty() && stack.peek() > 0) {
    //                 //只有栈顶元素小于当前元素的绝对值，才会存活
    //                 alive = stack.peek() < Math.abs(asteroid);
    //                 //栈顶元素爆炸（出栈）
    //                 if (stack.peek() <= Math.abs(asteroid)) {
    //                     stack.pop();
    //                 }
    //             }
    //             if (alive) {
    //                 stack.push(asteroid);
    //             }
    //         }
    //     }
    //     //结果输出
    //     int[] ans = new int[stack.size()];
    //     int i = 0;
    //     while (!stack.isEmpty()) {
    //         ans[i++] = stack.pollLast();
    //     }
    //     return ans;
    // }
