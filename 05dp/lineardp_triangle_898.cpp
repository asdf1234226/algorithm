// 5
// 7
// 3 8
// 8 1 0 
// 2 7 4 4
// 4 5 2 6 5
// 输出 30
#include<iostream>
using namespace std;
int n;
const int N=1010;
const int INF = 0x3f3f3f3f;
int path[N][N];
int f[N][N];//从起点走向(i,j)的距离


//f(i,j)由f(i-1,j)和f(i-1,j-1)，从上往下
int max_path(){
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= i+1; j++) //i+1是为了初始化右边
        {
            f[i][j]=-INF; //初始化
        }
    }

    f[1][1]=path[1][1];
    for (int i = 2; i <=n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            f[i][j]=max(f[i-1][j-1], f[i-1][j]) + path[i][j];
        }
    }
    int res = -INF;
    for (int i = 1; i <= n; i++)
    {
        res=max(res, f[n][i]);
    }
    return res;
}

int max_path1() //从下往上f[i][j]，由f[i+1][j]和f[i+1][j+1]转移而来
//好处是不用初始化处理边界
{
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i==n)
            {
                f[i][j]=path[i][j];
            }else
            {
                f[i][j]=max(f[i+1][j], f[i+1][j+1])+path[i][j];
            }
        }
    }
    return f[1][1];
    
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> path[i][j];
        }
    }
    cout << max_path1();
    return 0;
}