#include<iostream>


//TODO: 改成long防越界，还有c++ int的最大最小值，java有Integer.MAX_VALUE
int mult(int x, int y);
//要求： 不用除法实现整除a/b， 10/3=3
//思路：除数非0，|b|>=1,0*3,1*3,2*3，3*3...10*3
//所以在（0，a）中找到k, 使得k*b<=a<(k+1)*b
int divide(int a, int b)
{
    bool isNegative = false;
    if (a*b<0)
    {
        isNegative = true;
    }
    
    if (a<0)
    {
        a = -a;
    }
    if (b<0)
    {
        b=-b;
    }
    int l = 0, r = a;

    //什么时候移动l, 前半段满足<=a,后半段满足>a
    while (l<r)
    {
        int mid = (l+r+1)>>1;
        if (mult(mid,b)<=a)
        {
            l=mid;
        }else
        {
            r=mid-1;
        } 
    }
    int ans = isNegative?-l:l;
    if (ans>a||ans<-a)//越界
    {
        return -124535;
    }
    return ans;
      
}

//倍乘模板
//10=（1*2^3+0*2^2+1*2^1+0*2^0）只有除2余1的时候才会加起来，不然继续倍加
int mult(int x, int y)
{
    int res = 0;
    while (x>0)
    {
        if (x%2==1)
        {
            res += y;
        }
        x>>=1; //x>>1并不会改变x的值...
        y+=y;     
    }
    return res;  
}
int main()
{
    /* code */

    std::cout << divide(10,-3);
    return 0;
}
