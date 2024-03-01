// 在一个由 'L' ,'R' 和 'X' 三个字符组成的字符串（例如 "RXXLRXRXL"）中进行移动操作。
// 一次移动操作指用一个 "LX" 替换一个 "XL"，或者用一个 "XR" 替换一个 "RX"。
// 现给定起始字符串 start 和结束字符串 end，请编写代码，当且仅当存在一系列移动操作
// 使得 start 可以转换成 end 时， 返回 True。

#include<iostream>
using namespace std;

//'L'只能向左移动， 'R'只能向右移动
//不考虑'X'的情况下，'L'和'R'在start和end的相对位置不变
//（一个向左移动，一个向右移动，多普勒位移一样，相对位置不变）

bool canTransform(string start, string end){
    if (start.size()!=end.size())
    {
        return false;
    }
    int n = start.size();
    int i =0, j = 0;
    while (i<n && start[i]=='X')
    {
        i++;
    }
    while (j<n && end[j] =='X')
    {
        j++;
    }
    if (i==n || j== n)//不判断可能会有越界
    {
        return i==j;
    }
    if (start[i]!=end[j])//第一个非'X'如果不同
    {
        return false;
    }
    if (i<n && start[i]=='L' && i<j) return false; //只能向左移动，所以i只能>=j
    if (i<n && start[i]=='R' && i>j) return false;
    return i==j;
}

int main(){
    return 0;
}