#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int tmp[N];
void merge_sort(int q[], int l, int r)
{
    if (l>=r) return;
    int mid = (l+r)>>1;
    merge_sort(q, l, mid);
    merge_sort(q, mid+1, r);
    //合并两个有序数组
    int k = 0, i = l, j =mid+1;
    while (i<=mid && j <=r)
    {
        if (q[i]<=q[j])
        {
            tmp[k++] = q[i++];
        }
        else
        {
            tmp[k++] =q[j++];
        }
    }
    while (i<=mid)
    {
        tmp[k++]=q[i++];
    }
    while (j<=r)
    {
        tmp[k++]=q[j++];
    }
    // for (int i = l,j=0; i <=r; i++,j++)
    // {
    //     q[i] = tmp[j]; //复制到q(l,r)
    // }
    for (int i = 0; i < k; i++)
    {
        q[i+l]=tmp[i];//复制到q(l,r)
    }
}
int main()
{
    // int nums[] = {5,3,6,8,2,8};
    // merge_sort(nums,0,5);
    // for (size_t i = 0; i < 6; i++)
    // {
    //     cout<< nums[i];
    // }
    int num[] = {2,5,7,8,4};
    int len = sizeof(num)/sizeof(num[0]);
    merge_sort(num,0,len-1);
    for(int i = 0;i<len;i++){
        cout<<num[i]<< " ";
    }
}