// 输入：nums = [4,5,6,7,0,1,2]
// 输出：0
// 解释：原数组为 [0,1,2,4,5,6,7] ，旋转 3 次得到输入数组。

#include<iostream>
#include<vector>
using namespace std;

//旋转点，左边满足>=nums[0]

int findMin(vector<int>& nums) {
    int n = nums.size();
    if(n==0) return -1;
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
    if(l+1<n){//直接返回nums[l+1]可能会越界
        return nums[l+1];
    }else
    {
        return nums[0];
    }
    
}

int main(){
    vector<int> a ={7,0,1,2,4,5,6};
    cout << findMin(a);
    return 0;
}