#include<iostream>
#include<vector>
using namespace std;
// 给定一个  无重复元素 的 有序 整数数组 nums 。
// 返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表 。
// 也就是说，nums 的每个元素都恰好被某个区间范围所覆
// 输入：nums = [0,1,2,4,5,7]
// 输出：["0->2","4->5","7"]
// 解释：区间范围是：
// [0,2] --> "0->2"
// [4,5] --> "4->5"
// [7,7] --> "7"

// 输入：nums = [0,2,3,4,6,8,9]
// 输出：["0","2->4","6","8->9"]
// 解释：区间范围是：
// [0,0] --> "0"
// [2,4] --> "2->4"
// [6,6] --> "6"
// [8,9] --> "8->9"
vector<string> summaryRanges(vector<int>& nums) {
    int n = nums.size();
    vector<string> ans;
    if (n==0)
    {
        return ans;
    }
    int start = 0, end = 0;
    while (start <n && end<n)
    {
        while (end+1 < n && nums[end+1]==nums[end]+1)
        {
            end++;
        }
        if (end==start)
        {
            string s = std::to_string(nums[start]);
            ans.push_back(s);
            start++;
            end++;
        }else
        {
            string s = std::to_string(nums[start]) + "->" + std::to_string(nums[end]);
            ans.push_back(s);
            start=end+1;
            end=start;
        } 
    } 
    return ans;
}

int main(){
    vector<int> a = {0,2,3,4,6,8,9};
    vector<string> b = summaryRanges(a);
    for(auto i: b){
        cout << i << " ";
    }
    return 0;
}