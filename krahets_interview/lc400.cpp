//
// Created by SP on 2023/12/21.
//

// 给你一个整数 n ，请你在无限的整数序列 [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...] 中
// 找出并返回第 n 位上的数字。
// 示例 1：
// 输入：n = 3
// 输出：3
// 示例 2：
// 输入：n = 11
// 输出：0
// 解释：第 11 位数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是 0 ，它是 10 的一部分。


// 1~9           9个       每个长度1
// 10~99         90个      每个长度2
// 100~999       900个     每个长度3

// 9*1+90*2+900*3+9000*4...

#include<iostream>
using namespace std;


int findNthDigit(int n) {
    int count = 9;  //总个数
    int digitLen = 1; //数字长度
    int start = 1;  
    while(n>count){
        n-=count;
        digitLen++;
        start*=10;
        count=start*digitLen*9;
    }
    //所在元素
    //为什么用n-1不用n，假如是100的最后一个0，此时n为3，如果用n则n/3=1，会算到num是101这个数，index是0（结果是101的百位的1）
    //                 假如是100的1，此时n为1,会算到num是100，但是index是1(100中十位上的0)
    // 为了n从1到digitLen都要落在同一个num上，要对应n-1； 同时因为下面用string的index， 所以index要对应n-1
    long num = start + (n-1)/digitLen;
    int index =(n-1)%digitLen;
    return to_string(num)[index]-'0';
}

int main(){
    cout << findNthDigit(11);
    return 0;
}