// 给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。

// 输入: 10
// 输出: 36
// 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
// 说明: 你可以假设 n 不小于 2 且不大于 58。

#include<iostream>
#include<cstring>
using namespace std;

int integerBreak(int n){
    int f[n+1];
    memset(f,0, sizeof f);
    f[2]=1;
    for (int i = 3; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            //f[i]由f[j]转移而来，j的可能取值是1,2...i-1
            //因为f[j]也至少是两个正整数的和，所以f[i]只从f[j]转移，f[i]至少拆分3个数
            //还要补上f[i]拆分两个数的情况,(i-j)*j
            f[i] = max(f[i], max(f[j]*(i-j), (i-j)*j));
        }
    }
    return f[n];
}

int main(){
    cout << integerBreak(10);
    return 0;
}