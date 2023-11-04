#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_map>
using namespace std;
typedef pair<int, int> PII;

int help(vector<vector<int>>& grid)
{
    int ans=0;
    int m = grid.size();
    int n = grid[0].size();
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    unordered_map<int, int> mp;
    queue<PII> q;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j]==2)
            {
                q.push({i,j});
                mp[i*n+j]=0;
                grid[i][j]=-1;//标记访问过
            } 
        }   
    }
    while (!q.empty())
    {
        PII p = q.front();
        q.pop();
        int x = p.first, y = p.second;
        int step = mp[x*n+y];
        ans=max(ans,step);
        for (int i = 0; i < 4; i++)
        {
            int nx = x+ dx[i], ny=y+dy[i];
            if (nx>=0 && nx <m && ny >=0 && ny < n && grid[nx][ny]==1)
            {
                q.push({nx,ny});
                grid[nx][ny]=-1;
                mp[nx*n+ny]=step+1;
            }
        }  
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j]==1)
            {
                return -1;
            } 
        }   
    }
    return ans;
}




int main(){
    vector<vector<int>> a = {{2,1,1}, {1,1,0}, {0,1,1}};
    cout << help(a);
    return 0;
}