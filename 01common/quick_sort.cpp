#include<iostream>
using namespace std;

void quick_sort(int q[],int l, int r)
{
    if (l>=r) return; //递归终止条件
    int i = l-1, j= r+1, x = q[l+r>>1];
    while(i<j)
    {
        while(q[++i]<x);
        while(q[--j]>x);
        if (i<j)
        {
            swap(q[i],q[j]);
        }
    }
    quick_sort(q,l,j);
    quick_sort(q,j+1,r);
}
int main()
{
    int nums[] = {5,3,6,8,2,8};
    quick_sort(nums,0,5);
    for (size_t i = 0; i < 6; i++)
    {
        cout<< nums[i];
    }
    
}