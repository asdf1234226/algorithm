#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;


//找出三个数,a+b+c=0;
vector<vector<int>> threeSum(vector<int>& nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n = nums.size();
    if(n<3) return ans;
    for (int i = 0; i+2 < n; i++)
    {
        if (i>0 && nums[i]==nums[i-1])//去重
        {
            continue;
        }
        
        int target = -nums[i];
        int l = i+1;
        int r = n-1;
        while (l<r)
        {
            if (nums[l]+nums[r]<target)
            {
                l++;
            }else if (nums[l]+nums[r]>target)
            {
                r--;
            }
            else
            {
                ans.push_back({nums[i], nums[l], nums[r]});
                while (l<r&&nums[l]==nums[l-1]) l++;//去重
                while (l<r && nums[r]==nums[r+1]) r--;
                l++;
                r--;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> a = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = threeSum(a);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j<3; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}