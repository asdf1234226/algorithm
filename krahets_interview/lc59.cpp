//
// Created by SP on 2023/12/14.
//

//输入：n = 3
//输出：[[1,2,3],[8,9,4],[7,6,5]]
//给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n,vector<int>(n,0));
    int index = 1;
    int up = 0, down=n-1, left=0,right=n-1;
    while (true)
    {
        for (int j = left; j <=right; j++)//第一行
        {
            res[up][j]=index++;
        }
        up++;
        if (up>down)
        {
            break;
        }
        
        for (int i = up; i <= down; i++)//右边列
        {
            res[i][right]=index++;
        }
        right--;
        if (left>right)
        {
            break;
        }
        
        for(int j=right;j>=left;j--)//下边行
        {
            res[down][j]=index++;
        }
        down--;
        if (up>down)
        {
            break;
        }
        for (int i = down; i >= up; i--)//左边行
        {
            res[i][left]=index++;
        }
        left++;
        if (left>right)
        {
            break;
        }
    }
    return res;
}

int main(){
    vector<vector<int>> a = generateMatrix(3);
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}