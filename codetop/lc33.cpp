#include<iostream>
#include<vector>
using namespace std;

// 输入：nums = [4,5,6,7,0,1,2], target = 0
// 输出：4

int help(vector<int>& nums, int left, int right, int target){
    if(left>right) return -1;//要判断（因为不能保证传入的l+1<=n-1）
    while(left<right){
        int mid=(left+right+1)>>1;
        if(nums[mid]<=target){
            left=mid;
        }else
        {
            right=mid-1;
        }
    }
    return nums[left]==target?left:-1;
}

//前半段满足>=nums[0],后半段不满足，判断target在前半段还是后半段
//然后做有序数组的二分
int search(vector<int>& nums, int target) {
    int n = nums.size();
    if(n==1) return nums[0]==target?0:-1;//判断边界
    int l = 0, r = n-1;
    while (l<r)
    {
        int mid = (l+r+1)>>1;
        if (nums[mid]>=nums[0])
        {
            l=mid;
        }else
        {
            r=mid-1;
        }
    }
    if (target<nums[0])
    {
        //这里要判断l+1<=n-1
        return help(nums, l+1, n-1,target);
    }else if (target>nums[0])
    {
        return help(nums,0,l,target);
    }else
    {
        return 0;
    }
}

int main(){
    vector<int> a = {4,5,6,7,0,1,2};
    cout << search(a,0);
    return 0;
}