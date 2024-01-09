// 配对交换。编写程序，交换某个整数的奇数位和偶数位，尽量使用较少的指令
// （也就是说，位0与位1交换，位2与位3交换，以此类推）。
// num的范围在[0, 2^30 - 1]之间，不会发生整数溢出

// 示例1:
//  输入：num = 2（或者0b10）
//  输出 1 (或者 0b01)

//0xAAAAAAAA  A对应1010,从右往左数，偶数位置是1，奇数位是0， 获取所有偶数位
//0x55555555  5对应0101，从右往左数，奇数位1偶数位0，获取所有奇数位
//所有偶数位右移 | 所有奇数位左移

#include<iostream>
using namespace std;

int exchangeBits(int num) {
    return ((num& 0xAAAAAAAA)>>1) | ((num&0x55555555)<<1);
}

int main(){
    cout << exchangeBits(2);
    return 0;
}