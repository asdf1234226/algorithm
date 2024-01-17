// 二进制数转字符串。给定一个介于0和1之间的实数（如0.72），类型为double，打印它的二进制表达式。
// 如果该数字无法精确地用32位以内的二进制表示，则打印“ERROR”。

// 示例1:
//  输入：0.625
//  输出："0.101"
// 示例2:
//  输入：0.1
//  输出："ERROR"
//  提示：0.1无法被二进制准确表示
 
// 提示：
// 32位包括输出中的 "0." 这两位。
// 题目保证输入用例的小数位数最多只有 6 位

#include<iostream>
#include<vector>
using namespace std;

string printBin(double num) {
    // 这个应该和01背包问题不一样，这个更类似计算二进制？？
    vector<double> a = {0.5,0.25,0.125,0.0625,0.03125,0.015625};
    string res = "0.";
    for (int i = 0; i < 6; i++)
    {
        if (num-a[i]>0)
        {
            num-=a[i];
            res+="1";
            
        }else if (num-a[i]==0)
        {
            num-=a[i];
            res+="1";
            break;
        }else//如果<0，那就加"0"继续下一个
        {
            res+="0";
        }
    }
    return num==0.0?res:"ERROR";
}

int main(){
    cout << printBin(0.1);
    return 0;
}