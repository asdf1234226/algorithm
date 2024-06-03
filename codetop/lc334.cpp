// 给定一个未排序的数组，判断这个数组中是否存在长度为 3 的递增子序列。
// 数学表达式如下:
// 如果存在这样的 i, j, k,  且满足 0 ≤ i < j < k ≤ n-1，
// 使得 arr[i] < arr[j] < arr[k] ，返回 true ; 否则返回 false 。
// 说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1) 。

// 示例 1:
// 输入: [1,2,3,4,5]
// 输出: true
// 示例 2:
// 输入: [5,4,3,2,1]
// 输出: false

//区别于LIS问题，LIS的时间复杂度是O(n^2)

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

bool increasingTriplet(vector<int>& nums){
    if (nums.size()<3)
    {
        return false;
    }
    int min_1 = INT_MAX;
    int min_2 = INT_MAX;
    int min_3 = INT_MAX;
    //一次遍历，先更新最小值，如果下一个数大于当前最小值，说明这个数可以作为次小值；
    //维护三个变量，分别记录最小值，第二小值，第三小值。只要我们能够填满这三个变量就返回 true，否则返回 false。
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i]<=min_1){
            min_1 = nums[i];
        }else if (nums[i]<=min_2)
        {
            min_2 = nums[i];
        }else
        {
            return true;
        }
    }
    return false;
} 

int main(){
    vector<int> a = {1,6,3,4,1};
    if (increasingTriplet(a))
    {
        cout << "true";
    }else
    {
        cout << "false";
    }
    return 0;
}