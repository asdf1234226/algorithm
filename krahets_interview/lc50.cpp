// 实现 pow(x, n) ，即计算 x 的整数 n 次幂函数（即，xn ）。

// 输入：x = 2.10000, n = 3
// 输出：9.26100
// 输入：x = 2.00000, n = -2
// 输出：0.25000

#include<iostream>
using namespace std;
//3=2^0+2^1
//11=2^0+2^1+2^3
double myPow(double x, int n) {
    if (n<0)//幂指数为负数的情况
    {
        n=-n;
        x=1/x;
    }
    double res = 1.0;
//    1. 当 n&1=1 时：将当前 x 乘入 res。
//    2. 执行x=x^2。
//    3. n右移。
    while (n>0)
    {
        if (n&1==1)
        {
            res*=x;
        }
        x*=x;
        n>>=1;
    }
    return res;
}

int main(){
    cout << myPow(2.10000,3);
    return 0;
}

    // public double myPow(double x, int n) {
    //     if(x == 0.0f) return 0.0d;
    //     long b = n;
    //     double res = 1.0;
    //     if(b < 0) {
    //         x = 1 / x;
    //         b = -b;
    //     }
    //     while(b > 0) {
    //         if((b & 1) == 1) res *= x;
    //         x *= x;
    //         b >>= 1;
    //     }
    //     return res;
    // }