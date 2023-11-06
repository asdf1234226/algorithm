//
// Created by SP on 2023/11/5.
//

//需要 n 阶你才能到达楼顶。
//每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
//n=3时，结果3

#include<iostream>
#include<cstring>
using namespace std;


int climbStairs(int n) {
    int f[n+1];
    memset(f, 0, sizeof f);
    f[0]=1;
    f[1]=1;
    for (int i = 2; i <= n; i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    return f[n];

}

int main(){
    cout << climbStairs(3);
    return 0;
}