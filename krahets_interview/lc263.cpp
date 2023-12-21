// 丑数就是只包含质因数 2、3 和5 的正整数。
// 给你一个整数n ，请你判断n 是否为丑数。如果是，返回true ；否则，返回false 

#include<iostream>
using namespace std;

// 如果 n 不是正整数（即小于等于 0）：必然不是丑数，直接返回 false。
// 如果 n 是正整数：我们对 n 执行 2 3 5 的整除操作即可
// 注意，2 3 5 先除哪一个都是可以的，因为乘法本身具有交换律。

bool isUgly(int n) {
    if (n<=0)
    {
        return false;
    }
    while (n%2==0)
    {
        n/=2;
    }
    while (n%3==0)
    {
        n/=3;
    }
    while (n%5==0)
    {
        n/=5;
    }
    return n==1;
}
