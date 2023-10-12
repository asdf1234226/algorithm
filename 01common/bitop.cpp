#include<iostream>
using namespace std;

//求出给定数x的二进制表示中1的个数

int lowbit(int x)
{
    return x & -x; //返回x的最后一位1,如12是1100, lowbit(x)=100=4
}

int cacbit(int a){
    int res = 0;
    while (a>0)
    {
        a-=lowbit(a);
        res++;
    }
    return res;
    
}

int main()
{
    int a = 13;
    cout << cacbit(a);

}