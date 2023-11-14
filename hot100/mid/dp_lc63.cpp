

// 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
// 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

// 输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
// 输出：2 解释

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;


int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    int f[m+1][n+1];
    memset(f, 0, sizeof f);
    for (int j = 0; j < n; j++)
    {
        if (obstacleGrid[0][j]==0){
            f[0][j] =1;
        } else{
            break;
        }
        //f[0][j] = obstacleGrid[0][j]==0?1:0;
    }
    for (int i = 0; i < m; i++)
    {
        if (obstacleGrid[i][0]==0){
            f[i][0]=1;
        } else{
            break;
        }
        //f[i][0] = obstacleGrid[i][0]==0?1:0;
    }
    //f[i][j]由f[i-1][j]和f[i][j-1]转移而来，但是如果obstacleGrid[i][j]==1, f[i][j]=0
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (obstacleGrid[i][j] == 0)
            {
                f[i][j] = f[i-1][j] +f[i][j-1];
            }
        }   
    }
    return f[m-1][n-1];  
}


int main(){
    vector<vector<int>> a = {{0,0,0},{0,1,0},{0,0,0}};
    cout << uniquePathsWithObstacles(a);
    return 0;
}