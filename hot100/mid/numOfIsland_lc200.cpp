#include<iostream>
#include<vector>
using namespace std;
//四条边被水包围，所以最少一个岛
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void dfs(vector<vector<int>>& grid, int x, int y){
    grid[x][y]=2;
    for (int i = 0; i < 4; i++)
    {
        int nx = x+dx[i], ny=y+dy[i];
        if (nx>=0 && nx<grid.size() && ny>=0 &&ny<grid[0].size() && grid[nx][ny]==1)
        {
            dfs(grid,nx,ny);
        }
    }
}

int help(vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    int ans =0;
    for (int i = 0; i < m; i++)
    {
        for(int j=0;j<n;j++){
            if (grid[i][j]==1)
            {
                dfs(grid,i,j);//每次遇到陆地，求一个最大连通量，岛屿数量+1
                ans++;
            }
            
        }
    }
    return ans;
}


int main(){
    vector<vector<int>> a = {{1,1,1,1,0}, {1,1,0,1,0}, {1,1,0,0,0},{0,0,0,0,0}};
    cout << help(a);
    return 0;
}