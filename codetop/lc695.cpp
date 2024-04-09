#include<iostream>
#include<vector>
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int dfs(vector<vector<int>>& grid, int x, int y){
    int count = 1;
    grid[x][y]=2;
    for (int i = 0; i < 4; i++)
    {
        int nx = x+dx[i], ny=y+dy[i];
        if(nx>=0&&nx<grid.size()&&ny>=0&&ny<grid[0].size()&&grid[nx][ny]==1){
            count+=dfs(grid,nx,ny);
        }
    }
    return count;
}

int maxAreaOfIsland(vector<vector<int>>& grid){
    int res = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j]==1)
            {
                res=max(dfs(grid,i,j),res);
            }
        }
    }
    return res;
    
}

int main(){
    vector<vector<int>> a = {{0,0,1,0,0,0,0,1,0,0,0,0,0}, {0,0,0,0,0,0,0,1,1,1,0,0,0}, {0,1,1,0,1,0,0,0,0,0,0,0,0}, 
        {0,1,0,0,1,1,0,0,1,0,1,0,0}, {0,1,0,0,1,1,0,0,1,1,1,0,0}, {0,0,0,0,0,0,0,0,0,0,1,0,0}, {0,0,0,0,0,0,0,1,1,1,0,0,0}, {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    cout << maxAreaOfIsland(a);
    return 0;
}