// 给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，
// 使它们的和与 target 最接近。
// 返回这三个数的和。
// 假定每组输入只存在恰好一个解。

// 输入：nums = [-1,2,1,-4], target = 1
// 输出：2
// 解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//由于保证输入只存在一个解，所以没必要去重
int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(),nums.end());
    int mindiff = 0x3f3f3f3f;
    for (int i = 0; i < n-2; i++)
    {
        //和nums[l]==nums[l+1]写法统一
        //if(i+1<n-2 && nums[i]==nums[i+1]) continue;//i作为最左端点的组合已经加入过
        int l = i+1, r = n-1;
        while (l<r)
        {
            int diff = nums[i]+nums[l]+nums[r]-target;
            mindiff = abs(diff) < abs(mindiff)?diff:mindiff;
            if (diff>0)
            {
//                while (r-1>=0 && nums[r]==nums[r-1])//去重
//                {
//                    r--;
//                }
                r--;
            }else if(diff==0){
                mindiff = 0;//题目保证了只有一个解
                break;
            }else//diff < 0
            {
//                while (l+1<n && nums[l]==nums[l+1])//去重
//                {
//                    l++;
//                }
                l++;
            }
        }
    }
    return target+mindiff;
}

int main(){
    vector<int> a = {-1,2,1,-4};
    cout << threeSumClosest(a,1);
    return 0;
}