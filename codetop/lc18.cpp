// 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组
//  [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：

//     0 <= a, b, c, d < n
//     a、b、c 和 d 互不相同
//     nums[a] + nums[b] + nums[c] + nums[d] == target

// 你可以按 任意顺序 返回答案 。

// 示例 1：
// 输入：nums = [1,0,-1,0,-2,2], target = 0
// 输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

// 示例 2：
// 输入：nums = [2,2,2,2,2], target = 8
// 输出：[[2,2,2,2]]

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int a = 0; a < n; a++)
    {
        if (a>0 && nums[a]==nums[a-1]) continue; //去重
        for (int b = a+1; b < n; b++)
        {
            if (b>a+1 && nums[b]==nums[b-1]) continue;
            
            int c = b+1, d = n-1;
            while (c<d)
            {
                int sum = nums[a]+nums[b]+nums[c]+nums[d];
                if (sum<target)
                {
                    c++;
                }else if (sum>target)
                {
                    d--;
                }else
                {
                    ans.push_back({nums[a], nums[b], nums[c], nums[d]});
                    while (c<d && nums[c]==nums[c-1]) c++;
                    while (c<d && nums[d]==nums[d+1]) d--;//TODO这样还是，c+1,d-1
                    c++;
                    d--;
                }
            }         
        }
    }
    return ans;
}

int main(){
    vector<int> a = {1,0,-1,0,-2,2};
    vector<vector<int>> b = fourSum(a, 0);
    for(auto it: b){
        cout << it[0] << " " << it[1] << " " << it[2] << " "<< it[3] << endl;
    }
    return 0;
}