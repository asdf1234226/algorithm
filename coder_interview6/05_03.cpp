// 给定一个32位整数 num，你可以将一个数位从0变为1。请编写一个程序，找出你能够获得的最长的一串1的长度。
// 示例 1：
// 输入: num = 1775(11011101111)
// 输出: 8



#include<iostream>
#include<vector>
using namespace std;

int reverseBits(int num) {
    vector<int> a(32,0);
    int copy = num;
    for (int i = 0; i < 32; i++)
    {
        if ((copy&1)==1)//==的优先级比&高
        {
            a[31-i]=1;
        }
        copy >>=1;
    }
    // for (int i = 0; i < 32; i++)
    // {
    //     cout << a[i] << " ";
    // }
    int start = 0;
    int count = 0;//对窗口的1计数
    int res = 0;
    for (int end = 0; end < 32; end++)
    {
        if (a[end]==0)
        {
            count++;
        }
        while (count>1&&start<=end)//直到窗口合法
        {
            if(a[start]==0){
                count--;
            }
            start++;
        }
        res=max(end-start+1,res);
    }
    return res;
}


int main(){
    cout << reverseBits(1775);
    return 0;
}
