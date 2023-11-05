
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;


//找出三个数,a+b+c=0;
vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> ans;
    int n = nums.size();
    if (n<=2)
    {
        return ans;
    }
    sort(nums.begin(),nums.end());
    for (int i = 0; i+2 < n; i++)//遍历i，将l和r初始化i+1, n-1
    {
        if (i>0 && nums[i]==nums[i-1]) continue;//i-1作为最左端点的组合已经加入过
        int l = i+1, r = n-1;
        if (nums[i]>0) break; //nums[i]作为最左端的都大于0，后面的nums[l]和nums[r]>=nums[i]
        while(l<r){
            int sum = nums[i]+nums[l]+nums[r];
            //每次移动l或者移动r，都要跳过重复的； {nums[i], nums[l], nums[r]}nums[i]确定后nums[l]是唯一的，nums[i]可以等于nums[l]
            if (sum>0){
                while(l<r && nums[r]==nums[r-1]) r--;//跳过重复的nums[r]
                r--;//r左移才可能使sum=0
            } else if (sum<0){
                while (l<r && nums[l]==nums[l+1]) l++;
                l++;
            } else{
                ans.push_back({nums[i],nums[l],nums[r]});
                while (l<r && nums[l]==nums[l+1]) l++;
                while (l<r && nums[r]==nums[r-1]) r--;
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