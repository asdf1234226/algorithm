// 给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。
// 返回 需要移除区间的最小数量，使剩余区间互不重叠 。

// 示例 1:
// 输入: intervals = [[1,2],[2,3],[3,4],[1,3]]
// 输出: 1
// 解释: 移除 [1,3] 后，剩下的区间没有重叠。

// 示例 2:
// 输入: intervals = [ [1,2], [1,2], [1,2] ]
// 输出: 2
// 解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。

// 示例 3:
// 输入: intervals = [ [1,2], [2,3] ]
// 输出: 0
// 解释: 你不需要移除任何区间，因为它们已经是无重叠的了。


// 本题其实和452.用最少数量的箭引爆气球非常像，
// 弓箭的数量就相当于是非交叉区间的数量，只要把弓箭那道题目代码里射爆气球的判断条件加个等号（
// 认为[0，1][1，2]不是相邻区间），然后用总区间数减去弓箭数量 就是要移除的区间数量了。


#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

//直接求重叠区间个数，左端点排序
//维护当前区间st,ed； 如果it[0]在ed右边，则更新当前区间，不重叠
//否则有重叠，更新ed, min{ed, it[1]}，优先保留最小的
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.size()==0)
    {
        return 0;
    }
    
    sort(intervals.begin(), intervals.end());
    int ans = 0;
    int st = INT_MIN, ed = INT_MIN;
    for(auto it: intervals){
        if (ed<=it[0])//没重叠
        {
            st=it[0];
            ed=it[1];
            continue;
        }
        else{//与合并区间不同的是，这个ed更新为min(ed, it[1])，
        //因为要尽可能缩短当前区间的右边界，为下一个区间留空间
            ed = min(ed, it[1]);
            ans++;
        }
    }
    return ans;
}


int main(){
    vector<vector<int>> a = {{1,2},{1,2},{1,2},{1,3}};
    cout << eraseOverlapIntervals(a);
    return 0;
}