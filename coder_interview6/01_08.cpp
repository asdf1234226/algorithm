// 编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。

// 示例 2：
// 输入：
// [
//   [0,1,2,0],
//   [3,4,5,2],
//   [1,3,1,5]
// ]
// 输出：
// [
//   [0,0,0,0],
//   [0,4,5,0],
//   [0,3,1,0]
// ]


#include<iostream>
#include<vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<bool> row(m,false);
    vector<bool> col(n,false);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j]==0)
            {
                row[i]=true;
                col[j]=true;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++){
            if (row[i]||col[j])
            {
                matrix[i][j]=0;
            }
        }
    }
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
}

int main(){
    vector<vector<int>> a = {{0,1,2,0}, {3,4,5,2}, {1,3,1,5}};
    setZeroes(a);
    
    return 0;
}