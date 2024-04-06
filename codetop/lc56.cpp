// 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
// 输出：[[1,6],[8,10],[15,18]]
// 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals){
    vector<vector<int>> ans;
    if (intervals.size()==0)
    {
        return ans;
    }
    int st = INT_MIN, ed=INT_MIN;
    for(auto it: intervals){
        if (ed<it[0])
        {
            if (st!=INT_MIN)
            {
                ans.push_back({st,ed});
            }
            st=it[0];
            ed=it[1];
        }else
        {
            ed=max(ed,it[1]);
        }
    }
    if (st!=INT_MIN)
    {
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