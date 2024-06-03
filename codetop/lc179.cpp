// 给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。
// 注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。

// 示例 1：
// 输入：nums = [10,2]
// 输出："210"
// 示例 2：
// 输入：nums = [3,30,34,5,9]
// 输出："9534330"

#include<iostream>
#include<vector>
using namespace std;

//TODO quick_sort模版，base选l，下一轮递归是(l,j)和(j+1,r)
// void quick_sort(vector<int>& nums, int l_, int r_){
//     if (l_>=r_)
//     {
//         return;
//     }
//     int l = l_, r= r_;
//     int base = nums[(l+r) >> 1];
//     while (l<r)
//     {
//         while (l<r && to_string(nums[l])+to_string(base)>to_string(base)+to_string(nums[l]))
//         {
//             l++;
//         }
//         //while (l<r && nums[l]>base)
//         while(l<r && to_string(nums[r])+to_string(base)<to_string(base)+to_string(nums[r])){
//             r--;
//         }
//         if (l<r)
//         {
//             swap(nums[l++], nums[r--]);
//         }
//     }
//     quick_sort(nums,l_,r);
//     quick_sort(nums,r+1,r_);
// }

////老老实实用模板，不香吗？？？
void quick_sort(vector<int>& nums, int l, int r) {
    if (l >= r) return; // Base case for recursion

    int i = l - 1, j = r + 1;
    string x = to_string(nums[(l + r) >> 1]); //极端情况也是和nums[l]等价，如l=0,r=1

    while (i < j) {
        do {
            i++;
        } while (i < r && to_string(nums[i]) + x > x + to_string(nums[i]));

        do {
            j--;
        } while (j > l && to_string(nums[j]) + x < x + to_string(nums[j]));

        if (i < j) {
            swap(nums[i], nums[j]);
        }
    }

    quick_sort(nums, l, j);
    quick_sort(nums, j+1, r);
}
//搭配   如果(l+r)>>1，就要(l,j)和(j+1,r)； 如果(l+r+1)>>1,就要(l,i-1)和(i,r)
string largestNumber(vector<int>& nums){
    int n = nums.size();
    quick_sort(nums,0,n-1);
    string res = "";
    if(nums[0]==0) return "0";
    for (auto i: nums)
    {
        cout << i << " ";
        res+=to_string(i);
    }
    return res;
}

int main(){
    vector<int> a = {10,2,9,39,17};
    cout << largestNumber(a);
    return 0;
}