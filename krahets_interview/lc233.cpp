
// 给定一个整数n，计算所有小于等于n 的非负整数中数字1 出现的个数。 
// 示例1： 输入：n = 13 输出：6 

//思路：n在某位上1的个数
// 分三种情况，如在十位上1的个数
// 1.2403  0010~2319  24*10(high*digit)
// 2.2413  0010~2413  24*10+(3+1) 3+1对应2410~2413 （high*digit+low+1）
// 3.24x3  0010~2419 (x在2~9之间)  25*10  (high+1)*digit

//初始化
// high = n/10
// cur = n%10;
// low = 0;
//digit = 1;

//迭代下一轮
//  low+=cur*digit
//  cur = high%10
//  high %=10
// digit*=10


#include<iostream>
using namespace std;

int countDigitOne(int n){
    int ans = 0;
    int high = n/10, cur=n%10, low =0, digit=1;
    while(high>0||cur>0){
        if(cur==0){
            ans+=high*digit;
        }else if (cur==1)
        {
            ans+=high*digit+low+1;
        }else
        {
            ans+=(high+1)*digit;
        }
        low+=cur*digit;
        cur=high%10;
        high/=10;
        digit*=10;
    }
    return ans;
}

int main(){
    cout << countDigitOne(13);
    return 0;
}