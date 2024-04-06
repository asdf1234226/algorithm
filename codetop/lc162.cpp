#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    if(n==1) return 0;
    if (nums[0]>nums[1])
    {
        return 0;
    }
    if(nums[n-1]>nums[n-2]) return n-1;
    for (int i = 1; i < n-1; i++)
    {
        if (nums[i]>nums[i-1]&&nums[i]>nums[i+1])
        {
            return i;
        }
    }
    return -1;
}

int findPeakElement_opt(vector<int>& nums) {
    //nums[-1]=nums[n+1]=INT_MIN
    //一定有峰值
    // nums[mid]>nums[mid+1]时，nums[mid+1]必然不是峰值，nums[mid]可能是峰值
    // 二分不止满足0/1特性（满足/不满足），满足0？（不满足/不一定满足）也可以二分
    int n = nums.size();
    if(n==1) return 0;
    int l = 0;
    int r = n-1;
    while (l<r)
    {
        int mid=(l+r)>>1;
        if(nums[mid]>nums[mid+1]){
            r=mid;
        }else
        {
            l=mid+1;
        }
    }
    return l;
}

int main(){
    return 0;
}