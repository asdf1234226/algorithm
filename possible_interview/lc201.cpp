#include<iostream>
using namespace std;
// 给你两个整数 left 和 right ，表示区间 [left, right] ，
// 返回此区间内所有数字 按位与 的结果（包含 left 、right 端点）。
// 输入：left = 5, right = 7
// 输出：4
// 输入：left = 1, right = 2147483647
// 输出：0

//求公共前缀
//left是xxxx0xxx， right是xxxx1xxx， 0和1是第一个对应位上不同的数字，0xxx到1xxx之间一定会经过1000
//这样所有按位与后，后面的这半段都是0，===> 转化为求公共前缀
int rangeBitwiseAnd(int left, int right) {
    int ans = 0;
    int mask = 1 << 31;
    for (int i = 0; i <= 31; i++)
    {
        if ((mask&left)==(mask&right))
        {
            ans|=(mask&left);
            mask>>=1;
        }else
        {
            break;
        }
    }
    return ans;
}

int main(){
    cout << rangeBitwiseAnd(1,1);
    return 0;
}