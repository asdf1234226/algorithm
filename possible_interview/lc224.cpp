// 1 <= s.length <= 3 * 105
// s 由数字、'+'、'-'、'('、')'、和 ' ' 组成
// s 表示一个有效的表达式
// '+' 不能用作一元运算(例如， "+1" 和 "+(2 + 3)" 无效)
// '-' 可以用作一元运算(即 "-1" 和 "-(2 + 3)" 是有效的)
// 输入中不存在两个连续的操作符
// 每个数字和运行的计算将适合于一个有符号的 32位 整数

// 输入：s = "(1+(4+5+2)-3)+(6+8)"
// 输出：23

#include<iostream>
#include<stack>
using namespace std;

// s[i] = (
// s[i] = )
// s[i] = 数字  要计算
// s[i] = +
// s[i] = -
int calculate(string s) {
    int res = 0;
    for(int i=0;i<s.size();i++){
        if (s)
        {
            /* code */
        }
        
    }
}

int main(){
    return 0;
}