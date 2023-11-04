#include<iostream>
#include<cstring>
using namespace std;

int help(int m, int n)
{
    int f[m+1][n+1];
    memset(f,0,sizeof f);
    //初始化
    f[0][0]=1;
    for (int i = 1; i < m; i++)
    {
        f[i][0]=1;
    }
    for (int j = 1; j < n; j++)
    {
        f[0][j]=1;
    }
    
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            f[i][j]=f[i-1][j]+f[i][j-1];
        }
        
    }
    return f[m-1][n-1];
}


int main()
{
    int m=3,n=7;
    cout << help(m,n);
    return 0;
}