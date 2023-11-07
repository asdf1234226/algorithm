//
// Created by SP on 2023/11/6.
//

//输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
//输出：[[7,4,1],[8,5,2],[9,6,3]]
// n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度

#include<iostream>
#include<vector>
using namespace std;

//先转置再翻转
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n/2; j++)
        {
            swap(matrix[i][j], matrix[i][n-1-j]);
        }
        
    }
    
}

int main(){
    vector<vector<int>> a = {{1,2,3},{4,5,6},{7,8,9}};
    rotate(a);
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}