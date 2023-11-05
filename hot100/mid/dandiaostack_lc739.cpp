//
// Created by SP on 2023/11/5.
//
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;
//https://leetcode.cn/problems/daily-temperatures/solutions/609485/739-mei-ri-wen-du-dan-diao-zhan-xiang-ji-8kl5/
//找到x右边第一个比x大的元素的下标
// 3,2,1,4,5为例模拟一下
vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<int> st;
    int n = temperatures.size();
    vector<int> ans(n,0);
    st.push(0);//先入栈0
    for (int i = 1; i < n; ++i) {
        if (temperatures[i]<temperatures[st.top()]){
            st.push(i);
        } else if (temperatures[i]==temperatures[st.top()]){
            st.push(i);
        } else{
            while (!st.empty() && temperatures[i]>temperatures[st.top()]){//当前元素>栈顶元素时才更新
                ans[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
    }
    return ans;
}

int main(){
    vector<int> a ={73,74,75,71,69,72,76,73};
    vector<int> res = dailyTemperatures(a);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    return 0;
}