// 输入：nums = [5,7,7,8,8,10], target = 8
// 输出：[3,4]

#include<iostream>
#include<vector>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target) {
    //移动l获得是右边界，移动r获得的是左边界
    vector<int> res = {-1,-1};
    int n = nums.size();
    int l = 0, r =n-1;
    while (l<r)
    {
        int mid = (l+r+1)>>1;
        if(nums[mid]<=target){
            l=mid;
        }else
        {
            r=mid-1;
        }
    }
    if(nums[l]!=target){
        return {-1,-1};
    }
    res[1]=l;
    l=0,r=n-1;
    while (l<r)
    {
        int mid = (l+r)>>1;
        if(nums[mid]>=target){
            r=mid;
        }else
        {
            l=mid+1;
        }
    }
    res[0]=l;
    return res;
}

int main(){
    vector<int> a ={5,7,7,8,8,10};
    vector<int> ans = searchRange(a,8);
    cout << ans[0] << ":" << ans[1];
    return 0;
}