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

int findNthDigit(int n) {
    int digitLen = 1; //
    int count = 0; //总个数
    int multi = 9;  
    while (count<=n)
    {
        count+=digitLen*multi;
        multi*=10;
        digitLen++;
    }
    //这样跳出循环时，第n个数字所在的元素长度是digitLen-1
    int len = digitLen-1;
    count -=(digitLen-1)*(multi/10);
    
    //所在元素是
    
    


    

}