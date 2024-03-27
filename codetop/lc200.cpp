#include<iostream>
#include<vector>
using namespace std;

int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

void dfs(vector<vector<char>>& grid, int x, int y){
    grid[x][y]='2';//要在入口处标记访问过，不需要标记下一个
    for(int i=0;i<4;i++){
        int nx = x+ dx[i];
        int ny = y+dy[i];
        if(nx>=0&&nx<grid.size()&&ny>=0&&ny<grid[0].size()&&grid[nx][ny]=='1'){
            //grid[nx][ny]='2';
            dfs(grid,nx,ny);
        }
    }
}
int numIslands(vector<vector<char>>& grid) {
    int ans = 0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]=='1'){
                dfs(grid,i,j);
                ans++;
            }
        }
    }
    return ans;
}
int main(){
    vector<vector<char>> a = {{'1','1','1','1','0'}, {'1','1','0','1','0'}, {'1','1','0','0','0'},{'0','0','0','0','0'}};
    cout << numIslands(a);
    return 0;
}