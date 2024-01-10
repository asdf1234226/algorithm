// 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，
// 并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

// 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
// 输出：[[1,6],[8,10],[15,18]]
// 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end());
    int st = INT32_MIN, ed = INT32_MIN;
    vector<vector<int>> ans;
    for(auto it: intervals){
        if(ed<it[0]){
            if(st!=INT32_MIN){
                ans.push_back({st,ed});
            }
            st=it[0];
            ed=it[1];
        }else
        {
            ed=max(ed,it[1]);
        }
    }
    if(st!=INT32_MIN){
        ans.push_back({st,ed});
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