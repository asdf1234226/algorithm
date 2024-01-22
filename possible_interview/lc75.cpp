// 输入：nums = [2,0,2,1,1,0]
// 输出：[0,0,1,1,2,2]

#include<iostream>
#include<vector>
using namespace std;

void sortColors(vector<int>& nums) {
    int count0 = 0;
    int n = nums.size();
    int l = 0, r=n-1;
    while (l<r)
    {
        while (l<r && nums[l]==0)
        {
            l++;
        }
        while (l<r&&nums[r]!=0)
        {
            r--;
        }
        if (l<r)
        {
            swap(nums[l], nums[r]);
            l++;
            r--;
            count0++;
        }
    }
    
    l = 0;
    r=n-1;
    while (nums[l]==0)
    {
        l++;
    }
    
    while (l<r)
    {
        while (l<r && nums[l]==1)
        {
            l++;
        }
        while (l<r&&nums[r]!=1)
        {
            r--;
        }
        if (l<r)
        {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
}

int main(){
    vector<int> a = {2,0,2,1,1,0};
    sortColors(a);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}