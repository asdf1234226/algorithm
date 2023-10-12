#include<iostream>
using namespace std;

bool check(int x){return true;} //检查x是否满足某种属性
//寻找右边界
int bsearch_left(int l, int r)
{
    while (l<r)
    {
        int mid = (l+r+1)>>1; //向下取整 --> 向上取整
        if (check(mid)) //a[mid]满足左半边性质，应该在[mid, r]继续 
        {
            l=mid;
        }else r=mid-1;  //a[mid]不满足，应该去[l,mid-1]
    }
    return l; //如果不一定存在左半边边界，要做if判断
}

//寻找左边界
int bsearch_right(int l, int r)
{
    while(l<r)
    {
        int mid = (l+r)>>1;
        if (check(mid))
        {
            r=mid;
        }
        else l=mid+1;
    return l;
    }
}

int main()
{
    return 0;
}

