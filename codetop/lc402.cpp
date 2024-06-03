// 给你一个以字符串表示的非负整数 num 和一个整数 k ，移除这个数中的 k 位数字，使得剩下的数字最小。
// 请你以字符串形式返回这个最小的数字。

// 输入：num = "1432219", k = 3
// 输出："1219"
// 解释：移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219

// 输入：num = "10200", k = 1
// 输出："200"
// 解释：移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。

#include<iostream>
using namespace std;

//会爆内存
string del(string s, int i){
    if (i==0)
    {
        return s.substr(1,s.size()-1);
    }else
    {
        string res = s.substr(0,i) + s.substr(i+1);
        return res; 
    }
    
}
//像是移除降序对 (4,3), (3,2)
string removeKdigits(string num, int k) {
    if(k==num.size()) return "0";
    while (k--)
    {
        int index = -1;
        for (int i = 0; i+1 < num.size(); i++)
        {
            if(num[i]>num[i+1]){
                num = del(num,i);
                index = i;
                break;
            }
        }
        if (index==-1){
            num=del(num,num.size()-1);
        }
    }
    //去除前导0
    int index = 0;
    while (num[index]== '0')
    {
        index++;
    }
    return num.substr(index)==""?"0":num.substr(index);
}

int main(){
    cout << removeKdigits("1432219", 3);
    return 0;
}