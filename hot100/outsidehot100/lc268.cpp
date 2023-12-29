// 给定一个包含 [0, n] 中 n 个数的数组 nums ，
// 找出 [0, n] 这个范围内没有出现在数组中的那个数。
//你能否实现线性时间复杂度、仅使用额外常数空间的算法解决此问题?

// 示例 1：
// 输入：nums = [3,0,1]
// 输出：2
// 解释：n = 3，因为有 3 个数字，所以所有的数字都在范围 [0,3] 内。2 是丢失的数字，
// 因为它没有出现在 nums 中。

#include<iostream>
#include<vector>
using namespace std;

//位运算
//异或0到n（共n+1个数）  和 nums[0]到nums[n-1]（共n个数），
//只有没出现的数字出现了一次, 其他数字出现了两次
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res^=(i^nums[i]);
    }
    res^=n;
    return res;
}

int main(){
    vector<int> a = {3,0,1};
    cout << missingNumber(a);
    return 0;
}