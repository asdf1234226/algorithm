//
// Created by SP on 2023/12/26.
//

//输入：points = [[10,16],[2,8],[1,6],[7,12]]
//输出：2
//解释：气球可以用2支箭来爆破:
//-在x = 6处射出箭，击破气球[2,8]和[1,6]。
//-在x = 11处发射箭，击破气球[10,16]和[7,12]。



//就是区间选点问题
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//运算符重载
static bool cmp(const vector<int>& a, const vector<int>& b){
    return a[1]<b[1];
}
int findMinArrowShots(vector<vector<int>>& points) {
    int n = points.size();
    //调用
    sort(points.begin(),points.end(), cmp);
    int ans =0;
    int right = -0x3f3f3f3f;
    for (int i = 0; i < n; ++i) {
        if (right<points[i][0]){ //当前维护的右端点 < 下一个区间的左端点
            right=points[i][1];//就要多放一个点在下一个区间的右端点上
            ans++;
        }
    }
    return ans;

}

int main(){
    vector<vector<int>> a = {{9,12},{1,10},{4,11},{8,12},{3,9},{6,9},{6,7}};
    cout << findMinArrowShots(a);
    return 0;
}