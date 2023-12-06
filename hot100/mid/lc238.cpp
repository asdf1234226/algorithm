
// 给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中
// 除 nums[i] 之外其余各元素的乘积 。

// 输入: nums = [1,2,3,4]
// 输出: [24,12,8,6]


#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> preMult(n+1,1), endMult(n+1,1);
    for (int i = 1; i <= n; i++)
    {
        preMult[i]=preMult[i-1]*nums[i-1];
    }
    for(int j = 1;j<=n;j++){//从后往前数，前j个数的乘积
        endMult[j]=endMult[j-1]*nums[n-j];
    }
    vector<int> ans(n,0);
    for (int i = 0; i < n; i++)
    {
        //下标i是i+1个数，左边是i个数，右边有n-i-1个数
        ans[i]=preMult[i]*endMult[n-i-1]; 
    }
    return ans;
}

int main(){
    vector<int> a = {1,2,3,4};
    vector<int> b = productExceptSelf(a);
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}