// 给定一个整数n，返回n！结果中尾随零的数量
// 输入：n = 5
// 输出：1
// 解释：5! = 120 ，有一个尾随 0

#include<iostream>
using namespace std;

//转换成[1,n]中能拆出多少个2和5
//[1,n]能拆出1个5的个数，n/5； 能拆出2个5的个数n/25... 能拆出k个5的个数n/(5^k)
//能拆出5的个数等于上面的这些相加
//2<5，所以拆出2的个数肯定比5多，所以2*5=10，0的个数受限于5的个数
int trailingZeroes(int n){
    if(n==0){
        return 0;
    }
    return n/5+trailingZeroes(n/5);
}

int main(){
    cout << trailingZeroes(5);
    return 0;
}