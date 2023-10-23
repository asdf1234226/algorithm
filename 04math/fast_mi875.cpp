#include<iostream>
using namespace std;
int n;
// 2
// 3 2 5    3^2 mod 5
// 4 3 9

void fast_mi(int a, int b, int p){
    long long res=1; //防止数据溢出
    //a^7=a * a^2 * a^4 (7=1+2+4=2^0+2^1+2^2),所以把b拆成二进制数，再相乘
    while (b)
    {
        if (b & 1 ==1) //迭代求k位是不是1
        {
            res=res*a%p;
        }
        b >>= 1; //b右移1位
        a=(long long)a*a%p; //更新a，依次为a, a^2, a^4, a^8...，1，2，4，8分别是2的0，1，2，3次幂
    }
    cout << res << endl;
}

int main(){
    cin >> n;
    while (n--)
    {
        int a, b, p;
        cin >> a >>b >> p;
        fast_mi(a,b,p);
    }
    
    return 0;
}