//
// Created by SP on 2023/11/2.
//
//
// Created by SP on 2023/11/1.
//

#include <iostream>
#include <vector>
using namespace std;

//核心思想：每次循环时，当前遍历到的所有元素中不为0的都在j左边
//所以遍历到的为0，不需要处理；遍历到不为0时，要使它在j左边，就需要交换i,j同时j+1
void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i]==0) continue;
        else{
            swap(nums[i], nums[j]);
            j++;
        }
    }
}

int main(){
    vector<int> nums={0,1,0,3,12};
    moveZeroes(nums);
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    return 0;
}