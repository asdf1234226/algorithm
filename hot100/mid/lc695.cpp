//
// Created by SP on 2023/11/8.
//

//岛屿的最大面积
//m x n 的二进制矩阵 grid 。可以假设最外围被水包围
//输入：grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],
//[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
//输出：6

#include<iostream>
#include<vector>
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int dfs(vector<vector<int>> grid, int x, int y){
    int count = 1;
    grid[x][y]=2;
    for (int i = 0; i < 4; i++)
    {
        int nx= x+dx[i];
        int ny= y+dy[i];
        if (nx>=0 && nx <grid.size() && ny>=0 && ny< grid[0].size() && grid[nx][ny]==1)
        {
            count+=dfs(grid,nx,ny);
        }
    }
    return count;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j]==1)
            {
                ans=max(ans, dfs(grid,i,j));
            }
        }
    }
    return ans;
}


int main(){
    vector<vector<int>> a = {{0,0,1,0,0,0,0,1,0,0,0,0,0}, {0,0,0,0,0,0,0,1,1,1,0,0,0}, {0,1,1,0,1,0,0,0,0,0,0,0,0}, 
        {0,1,0,0,1,1,0,0,1,0,1,0,0}, {0,1,0,0,1,1,0,0,1,1,1,0,0}, {0,0,0,0,0,0,0,0,0,0,1,0,0}, {0,0,0,0,0,0,0,1,1,1,0,0,0}, {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    cout << maxAreaOfIsland(a);
    return 0;
}