
// 给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。

// 输入: nums = [1,2,3,4,5,6,7], k = 3
// 输出: [5,6,7,1,2,3,4]
// 解释:
// 向右轮转 1 步: [7,1,2,3,4,5,6]
// 向右轮转 2 步: [6,7,1,2,3,4,5]
// 向右轮转 3 步: [5,6,7,1,2,3,4]

//你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗

#include<iostream>
#include<vector>
using namespace std;

//方法一：
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k=k%n;
    vector<int> tmp;
    for (int i = 0; i < n; i++)
    {
        tmp.push_back(nums[i]);
    }
    // 以k=2为例 模拟一下
    for (int i = 0; i < k; i++)
    {
        nums[i]=tmp[n-k+i];//i=k-1时相加要等于n-1
    }
    for (int i = k; i < n; i++)
    {
        nums[i]=tmp[i-k];
    }
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
}

//方法二：
// tmp用两个nums拼一起，就不用分段算了

//方法三：
//如何空间O(1)

//这样会超时
void rotate_1(vector<int>& nums, int k) {
    int n = nums.size();
    k=k%n;
    while (k--)
    {
        for(int i=0;i<n-1;i++){//n-1次交换第i个元素和最后一个元素的位置
            swap(nums[i], nums[n-1]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }   
}

void reverse(vector<int>& nums, int l, int r){
    while (l<r){
        swap(nums[l], nums[r]);
        l++;
        r--;
    }
}
//小技巧
void rotate_2(vector<int>& nums, int k) {
    int n = nums.size();
    k=k%n;
    reverse(nums,0,n-1);////整个数组反转，右边的k个就会到左边，但是是倒序
    reverse(nums,0,k-1);//左边k翻转
    reverse(nums,k,n-1);//右边翻转
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
}

int main(){
    vector<int> a ={1,2,3,4,5,6,7};
    rotate_1(a,2);
    return 0;
}