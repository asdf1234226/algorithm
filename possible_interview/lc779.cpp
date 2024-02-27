// 首先在第一行我们写上一个 0。
// 接下来的每一行，将前一行中的 0 替换为 01，1 替换为 10。
// 例如，对于 n = 3，第 1 行是 0 ，第 2 行是 01，第 3 行是 0110 。
// 给定行数 n 和序数 k，返回第 n 行中第 k 个字符。（ k 从索引 1 开始

// 输入: n = 2, k = 2
// 输出: 1
// 解释:
// 第一行: 0
// 第二行: 01

//  0
//  0 1
//  0 1 1 0
//  0 1 1 0 1 0 0 1
//  0 1 1 0 1 0 0 1 1 0 0 1 0 1 1 0

#include<iostream>
using namespace std;

//倒推验证，r表示行,c表示列，val表示r行c列的元素值
int dfs(int r, int c, int val){
    if (r==1)
    {
        return val;
    }
    // 在10所在的组，由上一行的1转换而来， 所以如果c是奇数并且val是1对应10的1
    if ((c%2==1 && val == 1) || (c%2==0 && val == 0))
    {
        // 3,4对应上一行的2，所以(c+1)/2
        return dfs(r-1, (c+1)/2, 1);
    }else
    {
        return dfs(r-1,(c+1)/2,0);
    }
}
int kthGrammar(int n, int k)
{
    return  dfs(n,k,0)==0?0:1;
}

int main(){
    return 0;
}