// 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

// 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
// 输入：nums = [100,4,200,1,3,2]
// 输出：4
// 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。

#include<iostream>
#include<vector>
#include<set>
using namespace std;

//TODO  思路忘记了
//O(n)要求不能排序
//起点num[i]-1不在，终点的条件num[i]+1不在
int longestConsecutive(vector<int>& nums){
    int n = nums.size();
    set<int> st;
    for(auto it: nums){
        st.insert(it);
    }
    int res = 0;
    for (auto it: st)
    {
        if (st.find(it-1)==st.end())
        {
            int len = 0;
            int target = it;
            while (st.find(target)!=st.end())
            {
                target++;
                len++;
                res=max(res,len);
            }
        } 
    }
    return res;
    
}

int main(){
    vector<int> a = {0,3,7,2,5,8,4,6,0,1};
    cout << longestConsecutive(a);
    return 0;
}