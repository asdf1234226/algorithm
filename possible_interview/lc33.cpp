#include<iostream>
#include<vector>
using namespace std;

// 输入：nums = [4,5,6,7,0,1,2], target = 0
// 输出：4

//左半段满足nums[mid]<=target
int help(vector<int>& nums, int left, int right, int target){
    if(left>right) return -1;//要做判断
    int l =left,r=right;
    while (l<r)
    {
        int mid=(l+r+1)>>1;
        if(nums[mid]<=target){
            l=mid;
        }else
        {
            r=mid-1;
        }
    }
    return nums[l]==target?l:-1;
}

//先找旋转点
//以旋转点为分界再寻找左半段还是右半段
int search(vector<int>& nums, int target) {
    //1.旋转点，左边满足>=nums[0]
    int n = nums.size();
    if(n==0) return -1;
    if(n==1) return nums[0]==target?0:-1;//判断边界
    int l=0,r=n-1;
    while (l<r)
    {
        int mid=(l+r+1)>>1;
        if(nums[mid]>=nums[0]){
            l=mid;
        }else
        {
            r=mid-1;
        }
    }
    //2.二分查找左半段还是右半段
    int index=help(nums,0,l,target);
    if(index==-1){
        //或者在这要判断l+1<=n-1
        index=help(nums,l+1,n-1,target);
    }
    return index;
}

int main(){
    vector<int> a ={4,5,6,7,0,1,2};
    cout << search(a,0);
    //vector<int> a ={1,3};
    //cout << search(a,0);
    return 0;
}