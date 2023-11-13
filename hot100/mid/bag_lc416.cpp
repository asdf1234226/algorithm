//
// Created by SP on 2023/11/12.
//

//是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
//输入：nums = [1,5,11,5]
//输出：true
//解释：数组可以分割成 [1, 5, 5] 和 [11]

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum+=nums[i];
    }
    if (sum%2==1) return false;
    int target = sum/2; //转换成0，1背包问题
    int f[target+1];
    memset(f,0, sizeof f);
    for (int i = 0; i < n; ++i) {
        for (int j = target; j >= nums[i]; j--) {
            //体积1，价值也是1，只要求target容量的背包的最大价值（最大就是target即装满的情况）
            f[j]=max(f[j-nums[i]]+nums[i], f[j]);
        }
    }
    return f[target]==target;
}


int main(){
    vector<int> a = {1,5,11,5};
    if (canPartition(a)){
        cout << "y";
    } else{
        cout << "no";
    }
    return 0;
}