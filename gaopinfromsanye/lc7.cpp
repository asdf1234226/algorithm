#include<iostream>
using namespace std;
//翻转整数  123-->321  数据范围[-2^31,2^31-1]
//数据溢出返回0


//int的最大整数2147483647，7463847412不是int
//如果sum *10 + num %10 > 最大的int 或<最小的int负值
int reverse(int num)
{
    long sum = 0;
    while (num != 0)
    {
        sum = sum *10 + num %10; //这一步可能会整形溢出
        num /= 10;
    }
    return (int)sum == sum?(int)sum:0; 
}

//改进
#define MAX 0x7fffffff;
#define MIN -0x80000000;

//sum*10 + num%10 > MAX  (num>0时)
int reverse_enhance(int num)
{
    int max_int = MAX;
    int min_int = MIN;
    int sum = 0;
    while (num != 0)
    {
        if(num>0 && sum > (max_int-num%10)/10)
        {
            return 0;
        }
        if (num<0 && sum < (min_int-num%10)/10)
        {
            return 0;
        }
        
        sum = sum*10 + num%10;
        num/=10;
    }
    return sum;
    
}


int main()
{
    cout << reverse_enhance(-214748367) << endl;
    return 0;
}