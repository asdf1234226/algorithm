//
// Created by SP on 2023/11/5.
//

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
//当前index能存储水的单位取决于，min(index左边的最大值，index右边的最大值)和height[index]的大小
//height小于时，才可能存水
//如何计算index左边最大值和index右边最大值：   用数组存储，分别从左到右遍历和从右向左遍历

int trap(vector<int>& height) {
    int n = height.size();
    if (n<=2){
        return 0;
    }
    int max_left[n];
    int max_right[n];
    memset(max_left,0,sizeof max_left);
    memset(max_right,0,sizeof max_right);
    int max_l = 0;
    for (int i = 1; i < n; ++i) {
        max_l = max(height[i-1],max_l);
        max_left[i]=max_l;
    }
    int max_r =0;
    for (int j = n-2; j >=0 ; j--) {
        max_r=max(height[j+1],max_r);
        max_right[j]=max_r;
    }
    int ans =0;
    for (int i = 1; i <n-1 ; ++i) {
        int cur = min(max_left[i],max_right[i])-height[i];
        if (cur >0){
            ans+=cur;
        }
    }
    return ans;
}

int main(){
    vector<int> a ={0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(a);
    return 0;
}