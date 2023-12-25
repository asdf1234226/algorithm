//
// Created by SP on 2023/12/21.
//

//给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。
//你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。
//
//示例 1：
//输入：num1 = "11", num2 = "123"
//输出："134"
//示例 2：
//输入：num1 = "456", num2 = "77"
//输出："533"

#include <iostream>
#include <algorithm>
using namespace std;

string addStrings(string num1, string num2) {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(),num2.end());
    int n1 =num1.size();
    int n2=num2.size();
    int n = max(n1,n2);
    int add = 0;//进位
    string res ="";
    for (int i = 0; i < n; ++i) {
        int a = 0, b= 0;
        if (i<n1){
            a=num1[i]-'0';
        }
        if (i<n2){
            b=num2[i]-'0';
        }
        int sum = a+b+add;
        res = res + to_string(sum%10);
        add=sum/10;
    }
    if (add==1){
        res+= to_string(add);
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    cout << addStrings("456","77");
    return 0;
}