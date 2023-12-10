//
// Created by SP on 2023/12/3.
//

//给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n），可知至少存在一个重复的整数。
//假设 nums 只有 一个重复的整数 ，返回 这个重复的数

#include <iostream>
#include <vector>
using namespace std;

//lc41 原地哈希
//将[1,n]的数，分别放在 0,1,..n-1的位置上，n位置上的数就是多余的数
int findDuplicate(vector<int>& nums) {
    int n = nums.size()-1;
    for(int i = 0;i<=n;i++){//遍历数组所有元素
        while(nums[i]!=i+1 && nums[i] !=nums[nums[i]-1]){//i=0时，nums[0]应该为1，i=1时,nums[i]应该为2
            swap(nums[i], nums[nums[i]-1]);
        }
    }
    return nums[n];
}
int findDuplicate_final(vector<int>& nums) {
    int n = nums.size()-1;
    for(int i = 0;i<=n;i++){//遍历数组所有元素
        while(nums[i]!=i+1){//i=0时，nums[0]应该为1，i=1时,nums[i]应该为2
            if (nums[i]==nums[nums[i]-1]&&nums[i]!=nums[nums[i]-1])
            {
                return nums[i];//提前return
            }
            else
            {
                swap(nums[i], nums[nums[i]-1]);//nums[i]应该放在nums[i]-1的下标
            }
        }
    }
    return nums[n];
}
int main(){
    vector<int> a = {1,3,4,2,2};
    cout << findDuplicate_final(a);
    return 0;

}

