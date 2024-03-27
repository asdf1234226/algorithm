// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
// 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
// 输出：6
// 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。


#include<iostream>
#include<vector>
using namespace std;

//能接的雨水  min(左边最高的柱子高度，右边最高的柱子)-当前柱子高度
int trap(vector<int>& height) {
    int n = height.size();
    vector<int> l(n,0);
    vector<int> r(n,0);
    int l_max=0;
    for(int i=1;i<n;i++){//l_max记录左边柱子的最高值
        //第一根柱子（i=0）的左边最高值为0
        l_max=max(l_max,height[i-1]);
        l[i]=l_max;
    }
    int r_max=0;
    for(int i=n-2;i>=0;i--){
        r_max=max(r_max, height[i+1]);
        r[i]=r_max;
    }
    int score = 0;
    for(int i=0;i<n;i++){
        score+=min(l[i],r[i])-height[i]>0?min(l[i],r[i])-height[i]:0;
    }
    return score;
}

int main(){
    vector<int> a = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(a);
    return 0;
}