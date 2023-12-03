//
// Created by SP on 2023/11/14.
//
//给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
//
//我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

//输入：nums = [2,0,2,1,1,0]
//输出：[0,0,1,1,2,2]

#include <iostream>
#include <vector>
using namespace std;


//对比lc283移动零  --- j左边的只能非0
void sortColors(vector<int>& nums) {
    int n = nums.size();
    //1. 将0全部移动到头部
    int j = 0;//j左边的只能是0
    for (int i = 0; i < n; ++i) {
        if (nums[i]==0){
            swap(nums[i], nums[j]);
            j++;
        }else{
            continue;
        }
    }
    //j现在指向最后一个0的下一个位置，将1继续移动到剩余部分的头部
    for (int i = 0; i < n; ++i) {
        if (nums[i]==1){
            swap(nums[i], nums[j]);
            j++;
        }else{
            continue;
        }
    }
}

int main(){
    vector<int> a ={2,0,2,1,1,0};
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << " ";
    }
    return 0;
 }