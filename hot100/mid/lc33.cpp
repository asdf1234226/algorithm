//
// Created by SP on 2023/11/6.
//

//旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1
//nums = [4,5,6,7,0,1,2], target = 0
//输出4

#include <iostream>
#include <vector>
using namespace std;

int help(vector<int>& nums, int l, int r, int target){
    while (l<r){
        int mid = (l+r+1)>>1;
        if (nums[mid]<=target){
            l=mid;
        } else{
            r=mid-1;
        }
    }
    cout << l << ":" << r <<endl;
    return nums[l]==target?l:-1;
}

int search(vector<int>& nums, int target) {
    int n = nums.size();
    if (n == 0) return -1;
    if (n == 1) return nums[0] == target ? 0 : -1;  //要判断特殊情况
    //1.先找旋转点
    //满足前半段>=nums[0],后半段<nums[0]
    int l = 0, r =n-1;
    while (l<r){
        int mid = (l+r+1)>>1;
        if(nums[mid]>=nums[0]){
            l=mid;
        } else{
            r=mid-1;
        }
    }
    cout << "xuanzhuan: " << l << endl;
    //两段有序的数组查找target
    // int ans = help(nums, 0, l, target);
    // if (ans==-1 && l+1 <= n-1){//一定要加判断条件，不然可能数组访问越界
    //     ans= help(nums, l+1,n-1,target);
    // }
    // return ans;

    //通过和 nums[0] 进行比较，得知 target 是在旋转点的左边还是右边
    //target>=nums[0] 在[0,l],否则[l+1,n-1]
    if (target>=nums[0]){
        return help(nums, 0, l, target);
    }else if (target<nums[0]&&l+1<=n-1)
    {
        return help(nums, l+1,n-1,target);
    }
    return -1;

}

int main(){
    vector<int> a ={4,5,6,7,0,1,2};
    cout << search(a,0);
    //vector<int> a ={1,3};
    //cout << search(a,0);
    return 0;
}