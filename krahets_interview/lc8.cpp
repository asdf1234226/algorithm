// 请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数（类似 C/C++ 中的 atoi 函数）。

// 函数 myAtoi(string s) 的算法如下：

//     读入字符串并丢弃无用的前导空格
//     检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
//     读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
//     将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
//     如果整数数超过 32 位有符号整数范围 [−231,  231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被固定为 −231 ，大于 231 − 1 的整数应该被固定为 231 − 1 。
//     返回整数作为最终结果。

// 注意：

//     本题中的空白字符只包括空格字符 ' ' 。
//     除前导空格或数字后的其余字符串外，请勿忽略 任何其他字符

#include<iostream>
#include <climits>
using namespace std;

int myAtoi(string s) {
    int n = s.size();
    if (n==0)
    {
        return 0;
    }
    //去前导空格
    int index = 0;
    while (index<n && s[index]==' ')
    {
        index++;
    }
    if (index==n)
    {
        return 0;
    }
    int sign = 1;//记录符号
    if(s[index]=='-'){
        sign=-1;
        index++;
    }else if (s[index]=='+')
    {
        index++;
    }else if (s[index]<'0'||s[index]>'9')//如果去掉前导空格后，第一个字符不是-,+,还有0~9，就说明这个字符串无效
    {
        return 0;
    }
    //index是第一位数字
    while (index<n && s[index]=='0')
    {
        index++;//去前导0
    }
    int res = 0;
    int boundary = INT_MAX/10;
    //int的范围是-2147483648,2147483647
    while (index<n && s[index]>='0'&&s[index]<='9')
    {
        if (res<boundary||(res==boundary&&s[index]<'7'))
        {
            res=res*10+(s[index]-'0');
            cout << res << " ";
        }else if (res==boundary && s[index]<'8'&&sign==-1){//特殊处理"-2147483647"
            res=res*10+(s[index]-'0');
        }else
        {//越界
            return sign==1?INT_MAX:INT_MIN;
        }
        index++;
    }
    return sign==1?res:-res;
}


int main(){
    cout << myAtoi("-2147483647");
    return 0;
}