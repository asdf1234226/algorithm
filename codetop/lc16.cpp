// 输入：nums = -1,2,1,-4, target = 1
// 输出：2
// 解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。


#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

//保证只有唯一解，不需要去重
int threeSumClosest(vector<int>& nums, int target){
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int mindiff = INT_MAX;
    int res = -1;
    for (int i = 0; i+2 < n; i++)
    {
        int l = i+1, r = n-1;
        while (l<r)
        {
            int sum = nums[i]+nums[l]+nums[r];
            if (sum<target)
            {
                l++;
                if (abs(sum-target)<mindiff)
                {
                    mindiff=abs(sum-target);
                    res = sum;
                }
            }
            else if (sum==target)
            {
                return target;
            }else
            {
                r--;
                if (abs(sum-target)<mindiff)
                {
                    mindiff=abs(sum-target);
                    res = sum;
                }
            }
        }
    }
    return res;
}

int main(){
    vector<int> a = {-1,2,1,-4};
    cout << threeSumClosest(a,1);
    return 0;
}