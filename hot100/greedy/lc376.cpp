//
// Created by SP on 2023/11/12.
//

//如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为 摆动序列
//例如， [1, 7, 4, 9, 2, 5] 是一个 摆动序列 ，因为差值 (6, -3, 5, -7, 3) 是正负交替出现的。
//相反，[1, 4, 7, 2, 5] 和 [1, 7, 4, 5, 5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。
//给定一个整数序列，返回作为摆动序列的最长子序列的长度。 通过从原始序列中删除一些（也可以不删除）元素来获得子序列，剩下的元素保持其原始顺序。

// 输入：nums = [1,17,5,10,13,15,10,5,16,8]
// 输出：7
// 解释：这个序列包含几个长度为 7 摆动序列。
// 其中一个是 [1, 17, 10, 13, 10, 16, 8] ，各元素之间的差值为 (16, -7, 3, -3, 6, -8) 。

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int N = 1010;
int dp[N][2];

// dp[i][0]  前i个数，第i个数作为山谷的最大长度
// dp[i][1]  前i个数，第i个数作为山峰的最大长度
// dp[i][0]  山谷一定由山峰转移而来，所以当nums[i]<nums[j]时由dp[j][1]转移而来, j=1,2,...i-1

int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < n; i++)
    {
        dp[i][0]=1;
        dp[i][1]=1;
        for (int j = 0; j < i; j++)
        {
            if (nums[i]<nums[j])
            {
                dp[i][0] = max(dp[i][0], dp[j][1]+1);
            }
            else if(nums[i]>nums[j])//必须要同步更新
            {
                dp[i][1] = max(dp[i][1], dp[j][0]+1);
            }     
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp[i][0]);
        ans = max(ans, dp[i][1]);
    }
    return ans; 
    
}

int main(){
    vector<int> a ={1, 17, 10, 13, 10, 16, 8};
    cout << wiggleMaxLength(a);
    return 0;
}