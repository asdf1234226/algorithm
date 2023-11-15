//
// Created by SP on 2023/11/7.
//

//给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。

//输入：n = 13
//输出：2
//解释：13 = 4 + 9

#include<iostream>
#include<cstring>
using namespace std;
const int N = 10010;
int f[N];
//完全背包求最值
int numSquares(int n) {
	memset(f,0x3f,sizeof f);
    f[0]=0;
	for(int i=1; i<=n/i;i++){//i<=n/i可以防数据溢出
		for (int j = i*i; j <= n; j++)
		{
            //选i和不选i
			f[j]=min(f[j],f[j-i*i]+1);
            
		}
	}
	return f[n];

}


int main(){
    cout << numSquares(14);
    return 0;
}