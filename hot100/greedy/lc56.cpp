// 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 
// 请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 

// 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
// 输出：[[1,6],[8,10],[15,18]]
// 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(const vector<int>& a,vector<int>& b){
    return a[0]<b[0];
}
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    vector<vector<int>> ans;
    int start = -0x3f3f3f3f;
    int end = -0x3f3f3f3f;
    sort(intervals.begin(),intervals.end(), cmp);
    for (auto interval: intervals)
    {
        if (end<interval[0])//当前维护右端点在当前区间左边
        {
            if(start!=-0x3f3f3f3f){
                ans.push_back({start,end});
            }
            start=interval[0];//开新区间
            end=interval[1];
        }else
        {
            end=max(end,interval[1]);//更新右端点
        }
    }
    if (start!=-0x3f3f3f3f)//前面的只会在有新区间才会放入ans，遍历结束后也要添加当前维护的左右端点
    {
        ans.push_back({start,end});
    }
    
    return ans;
    
}

int main(){
    vector<vector<int>> a ={{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans = merge(a);
    for(auto vec: ans){
        cout << vec[0] << " " << vec[1];
        cout << endl;
    }
}