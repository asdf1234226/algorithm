// 输入：heights = [2,1,5,6,2,3]
// 输出：10
// 解释：最大的矩形为图中红色区域，面积为 10

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//以heights[i]为高度的矩形面积是，heights[i]右边第一个比heights[i]小的数，下标r
//heights[i]左数第一个比heights[i]小的数，下标l， heights[i]*(r-l+1)
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> right(n,n);//注意初始化，如果找不到右边比heights[i]小的数，初始化为n
    stack<int> st_r;
    for(int i=0;i<n;i++){
        while (!st_r.empty() && heights[st_r.top()]>heights[i])
        {
            right[st_r.top()]=i;
            st_r.pop();
        }
        st_r.push(i);
    }
    vector<int> left(n,-1);//注意初始化，找不到左边比heights[i]小的数，初始化-1
    stack<int> st_l;
    for(int i=n-1;i>=0;i--){
        while (!st_l.empty() && heights[st_l.top()]>heights[i])
        {
            left[st_l.top()]=i;
            st_l.pop();
        }
        st_l.push(i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        //right[i]-1是heights[i]为高度矩形的右边界
        //left[i]+1,==> (r-1)-(l+1)+1;
        ans=max(ans, heights[i]*(right[i]-left[i]-1));
    }
    return ans;
}

int main(){
    vector<int> a = {2,1,5,6,2,3};
    cout << largestRectangleArea(a);
    return 0;
}