//
// Created by SP on 2023/11/2.
//
//
// Created by SP on 2023/11/1.
//

#include <iostream>
#include <vector>
using namespace std;

//遍历一遍元素，将所有不为0的元素重新赋值到nums[cnt]
void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int cnt = 0;//统计不为0的个数

    for (int i = 0; i < n; ++i) {
        if (nums[i]==0) continue;
        else{
            nums[cnt++]=nums[i];
        }
    }
    for (int i = cnt; i <n ; ++i) {//剩余元素赋0
        nums[i]=0;
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