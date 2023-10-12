#include<iostream>
#include<vector>
using namespace std;

//给定排序数组和目标值，找到目标值并返回索引，目标值不存在返回插入位置
int searchInsert(vector<int> nums, int t)
{
    int n = nums.size();
    int l = 0, r = n-1;
    while (l<r)
    {
        int mid=(l+r+1)>>1;
        if (nums.at(mid)<=t) //移动l的条件
        {
            l=mid;
        }else
        {
            r=mid-1;
        }
    }
    // if (nums.at(l)==t)
    // {
    //     return l;
    // }
    // else if (nums.at(l)<t) //如果t比nums.at(l)大，就要放l+1位置
    // {
    //     return l+1;
    // }
    // else{
    //     return l;
    // }
    
    return nums.at(l)>=t?l:l+1;
}
int main()
{
    vector<int> nums = {1,3,5,6};
    cout << searchInsert(nums, 0) << endl;
    return 0;
}
