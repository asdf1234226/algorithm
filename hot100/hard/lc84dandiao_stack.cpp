//
// Created by SP on 2023/11/5.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;


int largestRectangleArea(vector<int>& heights) {
    //遍历h[i],h[i]为高度的矩形面积为，左边小于h[i]的下标l， 右边小于h[i]的下标r，（r-l-1）*h[i]
    int n = heights.size();
    int l[n], r[n];// r[i]存储h[i]右边第一个比h[i]小的元素下标
    //memset(l,-1,sizeof l);
    //memset(r,n,sizeof r); //************memset是按字节分配，只用于赋值0，-1，0x3f
    for (int i = 0; i <n ; ++i) {
        l[i]=-1;//如果左边没有比它小的柱子，-1表示没找到左边界，这样计算面积时默认是直方图的边界
        //比如只有h[0]一个元素时，l[0]=-1, r[0]=1, 面积计算(1-(-1)-1)*h[0]
        r[i]=n;
    }
    //l[i]存储h[i]左边第一个比h[i]小的元素下标
    stack<int> st_r;
    for (int i = 0; i < n; ++i) {
        while (!st_r.empty()&& heights[i] > heights[st_r.top()]){
            r[st_r.top()]=i;
            st_r.pop();
        }
        st_r.push(i);
    }
    stack<int> st_l;
    for (int i = n-1; i >=0 ; i--) {
        while (!st_l.empty()&& heights[i] < heights[st_l.top()]){
            l[st_l.top()]=i;
            st_l.pop();
        }
        st_l.push(i);
    }
    int ans = 0;
    for (int i = 0; i <n ; ++i) {
        ans=max(ans,(r[i]-l[i]-1)*heights[i]);
    }
    return ans;
}

int main(){
    vector<int> a = {2,1,5,6,2,3};
    cout <<largestRectangleArea(a);
    return 0;
}