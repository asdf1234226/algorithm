#include<iostream>
using namespace std;

int s[5][5];
int presum(int q[4][4], int x1, int y1, int x2, int y2)
{
    for (int i = 1; i <= 4; i++)
    {
        for(int j=1;j<=4;j++)
        {
            //s[i][j]是第i个数和第j个数为下标的前缀和
            s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+q[i-1][j-1]; //i-1是第i个数,j-1是第j个数
        }
    }
    return s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1];
}

int main()
{
    const int n = 4; //*********数组的大小必须是编译时常量, int n=4接着初始化就不行
    int q[n][n] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    //**********初始化q[][]不能省略第二维大小
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << q[i][j] << " ";
        }
        cout << endl;
    }
    cout << presum(q,1,2,3,4);

}