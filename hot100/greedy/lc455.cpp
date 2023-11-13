//
// Created by SP on 2023/11/12.
//

// 对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，都有一个尺寸 s[j] 。
// 如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。

// 输入: g = [1,2], s = [1,2,3]
// 输出: 2
// 解释:
// 你有两个孩子和三块小饼干，2个孩子的胃口值分别是1,2。
// 你拥有的饼干数量和尺寸都足以让所有孩子满足。
// 所以你应该输出2.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(int a, int b){
    return a>b;
}
int findContentChildren(vector<int>& g, vector<int>& s) {
    //尽可能把大饼干分配给大胃口的孩子
    sort(g.begin(), g.end(), compare);
    sort(s.begin(), s.end(), compare);
    int ans = 0;
    int index = 0;
    for (int i = 0; i < g.size(); i++)
    {
        if (index < s.size() && g[i]<= s[index])
        {
            index++;
            ans++;
        }  
    }
    return ans;
    
}

int main(){
    vector<int> a ={1,2};
    vector<int> b = {1,2,3};
    cout << findContentChildren(a,b);
    return 0;
}