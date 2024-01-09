// 整数转换。编写一个函数，确定需要改变几个位才能将整数A转成整数B。

// 示例1:
// 输入：A = 29 （或者0b11101）, B = 15（或者0b01111）
// 输出：2


//每位异或，不同为1 count++

#include<iostream>
using namespace std;
int convertInteger(int A, int B) {
    int count = 0;
    while (A!=0 || B !=0)
    {
        count += (A&1)^(B&1);
        A>>=1;
        B>>=1;
    }
    return count;
}

int main(){
    cout << convertInteger(29,15);
    return 0;
}