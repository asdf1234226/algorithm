// 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

// 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
// 输入：nums = [100,4,200,1,3,2]
// 输出：4
// 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。


#include<iostream>
#include<vector>
#include<set>
using namespace std;

//如何判断nums[i]是不是连续序列起点, nums[i]-1不在set中
//如何判断终点 nums[i]+1不在set中，则nums[i]是终点
int longestConsecutive(vector<int>& nums) {
    if(nums.size()==0) return 0;
    set<int> st;
    for(auto num: nums){
        st.insert(num);
    }
    int ans = 1;
    for(auto i: st){
        if (st.find(i-1)==st.end())//起点
        {
            int len = 0;
            int target = i;
            while (st.find(target)!=st.end())//到终点为止
            {
                len++;
                target++;
                ans=max(ans,len);
            }
        }
    }
//    for (int i = 0; i < nums.size(); i++)
//    {
//        if (st.find(nums[i]-1)==st.end())//起点
//        {
//            int len = 0;
//            int target = nums[i];
//            while (st.find(target)!=st.end())//到终点为止
//            {
//                len++;
//                target++;
//                ans=max(ans,len);
//            }
//        }
//    }
    return ans;
}

int main(){
    vector<int> a = {0,3,7,2,5,8,4,6,0,1};
    cout << longestConsecutive(a);
    return 0;
}