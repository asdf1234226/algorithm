// 给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素
// 输入：[
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// 输出：[1,2,4,7,5,3,6,8,9]


//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ],
//  [10, 11,12]
#include<iostream>
#include<vector>
using namespace std;

//共有m+n-1条对角线
//某条对角线的所有点(x,y) x+y=对角线编号,所以只要关心横坐标
//偶数对角线（从0开始）起点对角线编号 如 {7,5,3}这条，起点横坐标x=i;终点横坐标x=0
//                                   {11,9}这条，起点横坐标x=m-1,终点横坐标x=i-(n-1)
//                          综合看，起点应该是min(i,m-1)，终点max(0,i-n+1),顺序由下向上,x--
//奇数对角线                顺序和偶数对角线相反
vector<int> findDiagonalOrder(vector<vector<int>>& mat){
    int m = mat.size();
    int n = mat[0].size();
    vector<int> res;
    for(int i=0;i<m+n-1;i++)
    {
        if (i%2==0)
        {
            for (int x = min(i,m-1); x>=max(0,i-n+1); x--)
            {
                res.push_back(mat[x][i-x]);
            }
        }else
        {
            for (int x = max(0,i-n+1); x <= min(i,m-1); x++)
            {
                res.push_back(mat[x][i-x]);
            }
        }
    }
    return res;
}


int main(){
    vector<vector<int>> a = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans = findDiagonalOrder(a);
    for (auto it: ans)
    {
        cout << it << " ";
    }
    return 0;
}