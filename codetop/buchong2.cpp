//圆环上有10个点，编号为0~9。从0点出发，每次可以逆时针和顺时针走一步，问走n步回到0点共有多少种走法。
// 输入: 2
// 输出: 2
// 解释：有2种方案。分别是0->1->0和0->9->0

#include<iostream>
using namespace std;

//dp[i][j],走i步到j的方法
//dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1]
//防越界，j-1要变成(j-1+len)%len，j+1变成(j+1)%len
//return dp[n][0]
int backToOrigin(){

}

int main(){
    return 0;
}