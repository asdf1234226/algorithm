#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int help(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int f[m+1][n+1];
    memset(f,0x3f,sizeof f);
    //初始化
    f[0][0]=grid[0][0];
    for (int i = 1; i < m; i++)
    {
        f[i][0]=f[i-1][0]+grid[i][0];
    }
    for (int j = 1; j < n; j++)
    {
        f[0][j]=f[0][j-1]+grid[0][j];
    }
    
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            f[i][j]=min(f[i-1][j], f[i][j-1])+grid[i][j];
        }
        
    }
    return f[m-1][n-1];

}


int main()
{
    vector<vector<int>> a = {{1,3,1},{1,5,1},{4,2,1}};
    cout << help(a);
    return 0;
}