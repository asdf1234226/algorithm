#include<iostream>
using namespace std;

// 4 返回2
// 8 返回2，只保留整数部分

//二分  TODO 不熟悉
//i*i<=x, (i+1)*(i+1)>x  (i的范围1...x)
int mySqrt(int x){
    if(x<=1) return x;
    long l = 1;
    long r = x;
    while (l<r)
    {
        long mid = (l+r+1)>>1;//可能会越界，用long
        if(mid<=x/mid){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    return l;
}

int main(){
    cout << mySqrt(4);
    return 0;
}