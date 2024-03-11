#include<iostream>
#include<vector>
using namespace std;

// 给你一个有序数组 nums ，请你 原地 删除重复出现的元素，
// 使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。

// 不要使用额外的数组空间，你必须在 原地 修改输入数组 
// 并在使用 O(1) 额外空间的条件下完成。

// 输入：nums = [0,0,1,1,1,1,2,3,3]
// 输出：7, nums = [0,0,1,1,2,3,3]
int removeDuplicates(vector<int>& nums) {
    if(nums.size()<2){
        return nums.size();
    }
    int cnt = 0;
    int num = nums[0];
    int cnt2 = 1;
    int del = 0;
    for(int i =1;i<nums.size();i++){
        if(nums[i]==num){
            cnt2++;
            if(cnt2>2 && cnt <2){
                del++;
                cnt++;
            }
        }else
        {
            num = nums[i];
            cnt2=1;
        }
    }
    return nums.size()-del;
}
int main(){
    vector<int> a = {0,0,1,1,1,1,2,3,3};
    cout << removeDuplicates(a);
    return 0;
}