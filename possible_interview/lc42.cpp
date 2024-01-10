// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
// 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
// 输出：6
// 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。


#include<iostream>
#include<vector>
using namespace std;

int trap(vector<int>& height) {
    //每根柱子可以接雨水  --> min(左边最大值，右边最大值)-height[i]
    int n = height.size();
    vector<int> maxL(n,0);
    int max_l = 0;
    maxL[0]=0;
    for(int i = 1;i<n;i++){
        max_l=max(max_l,height[i-1]);
        maxL[i]=max_l;
    }

    vector<int> maxR(n,0);
    int max_r=0;
    for(int j =n-2;j>=0;j--){
        max_r=max(max_r,height[j+1]);
        maxR[j]=max_r;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int store = min(maxL[i],maxR[i])-height[i];
        if(store>0){
            ans+=store;
        }
    }
    return ans;
}

int main(){
    vector<int> a = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(a);
    return 0;
}