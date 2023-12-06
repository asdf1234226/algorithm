// 给定一个长度为 n 的整数数组 nums 。
// 假设 arrk 是数组 nums 顺时针旋转 k 个位置后的数组，我们定义 nums 的 旋转函数  F 为：
// F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1]
// 返回 F(0), F(1), ..., F(n-1)中的最大值 

// 输入: nums = [4,3,2,6]
// 输出: 26
// 解释:
// F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
// F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
// F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
// F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
// 所以 F(0), F(1), F(2), F(3) 中的最大值是 F(3) = 26 。

//旋转数组，只要拼接成2n就可以4,3,2,6,4,3,2,6
//滑动窗口  
//TODO 前缀和应该怎么写才优雅


#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int maxRotateFunction(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        nums.push_back(nums[i]);
    }
    int ans = -0x3f3f3f3f;
    int window_sum = 0;
    int preSum[2*n+1];
    memset(preSum,0,sizeof preSum);
    for (int i = 1; i <= 2*n; i++)
    {
        preSum[i]=preSum[i-1]+nums[i-1];//i-1是第i个数
    }
    
    for (int end = 0; end < 2*n; end++)
    {
        if (end < n)
        {
            window_sum+=nums[end]*end;
        }else
        {
            window_sum+=nums[end]*(n-1);//新进入窗口的

            //原窗口的结束下标是end-1,开始下标是end-n，对应的前缀和数组是end合end-n+1(前end个数)
            window_sum-=(preSum[end]-preSum[(end-n+1-1)+1]);//假设原窗口a0,a1,a2,a3，这里要减去a1~a3
            ans = max(window_sum, ans);
        }
    }
    return ans;
}

int main(){
    vector<int> a ={4,3,2,6};
    cout << maxRotateFunction(a);
    return 0;
}