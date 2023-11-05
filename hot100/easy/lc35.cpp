//
// Created by SP on 2023/11/2.
//

#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();
    int l = 0, r = n-1;
    while (l<r){
        int mid = (l+r+1)>>1;
        if(nums[mid]<=target){
            l=mid;
        } else{
            r=mid-1;
        }
    }
    int ans = 0;
    if (nums[l]==target){
        ans=l;
    } else if (nums[l]<target){//target>nums[l],就要把target放在l+1的位置保证有序性
        ans=l+1;
    } else{// target<l可以把target插到l，原来l--->l+1，能保证有序性
        ans=l;
    }
    return ans;
}

int main(){
    vector<int> a = {1,3,5,6};
    int t = 0;
    cout << searchInsert(a,t);
    return 0;
}