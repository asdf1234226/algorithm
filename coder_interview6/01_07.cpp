// 给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。
// 不占用额外内存空间能否做到？

// 给定 matrix = 
// [
//   [1,2,3],
//   [4,5,6],
//   [7,8,9]
// ],

// 原地旋转输入矩阵，使其变为:
// [
//   [7,4,1],
//   [8,5,2],
//   [9,6,3]
// ]

#include<iostream>
#include<vector>
using namespace std;

//先转置，再对折翻转
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j<i;j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n/2; j++)
        {
            swap(matrix[i][j], matrix[i][n-j-1]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<vector<int>> a = {{1,2,3},{4,5,6},{7,8,9}};
    rotate(a);
    return 0;
}