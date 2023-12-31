//
// Created by SP on 2023/12/14.
//

// 给你一个整数 n，请你判断该整数是否是 2 的幂次方。如果是，返回 true ；否则，返回 false 。
// 如果存在一个整数 x 使得 n == 2x ，则认为 n 是 2 的幂次方。

//如果是2的幂次方，那么二进制表示中有且只有一个1

#include<iostream>
using namespace std;
int lowbit(int x){
    return x&(-x);
}
bool isPowerOfTwo(int n) {
    return n-lowbit(n)==0;
}

int main(){
    int n = 4;
    cout << isPowerOfTwo(n);
    return 0;
}