// 给你一个数组 points。求最多有多少个点在同一条直线上

// 输入：points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
// 输出：4

#include<iostream>
#include<vector>
using namespace std;

//两点确定一条直线，看有多少点在这条直线上
//暴力做法
//如何确定第三点在不在这条直线上 a(x1,y1),b(x2,y2), c(x3,y3)
// 斜率 (y3-y1)/(x3-x1) == (y2-y1)/(x2-x1), 为了避免除法的精度问题，要转换成乘法
// (y3-y1)*(x2-x1) == (y2-y1)*(x3-x1) 
int maxPoints(vector<vector<int>>& points){
    int n = points.size();
    if (n<=2)
    {
        return n;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> a = points[i];
        for (int j = i+1; j < n; j++)
        {
            vector<int> b = points[j];
            int cnt = 2;
            for (int k = j+1; k < n; k++)
            {
                vector<int> c = points[k];
                bool isSameLine = (c[1]-a[1])*(b[0]-a[0]) ==(b[1]-a[1])*(c[0]-a[0]);
                if (isSameLine)
                {
                    cnt++;
                }
            }
            ans=max(ans, cnt);
        }
        
    }
    return ans;
}

int main(){
    vector<vector<int>> a = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    cout << maxPoints(a);
    return 0;
}