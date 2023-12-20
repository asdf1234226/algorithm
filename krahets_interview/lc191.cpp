//
// Created by SP on 2023/12/14.
//

// 编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为汉明重量）。
// 输入：n = 00000000000000000000000000001011
// 输出：3
// 解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。
// 示例 2：
// 输入：n = 00000000000000000000000010000000
// 输出：1
// 解释：输入的二进制串 00000000000000000000000010000000 中，共有一位为 '1'。

#include<iostream>
using namespace std;

int lowbit(int x){
    return x&(-x);
}
int hammingWeight(uint32_t n) {
    int res = 0;
    while (n!=0)
    {
        n-=lowbit(n);//返回x的最后一位1,如12是1100, lowbit(x)=100=4
        res++;
    }
    return res;
}

int main(){
    cout << hammingWeight(5);    
    return 0;
}
