//
// Created by SP on 2023/11/12.
//


//给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
//
//输入: [3,2,3,1,2,4,5,5,6], k = 4
//输出: 4

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//k-1个  k   n-k个
//大根堆, n个元素, 第k大是堆顶 n-k大小的堆
//小根堆，第k大是堆顶  k大小的堆
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq;//维护n-k大小的大根堆
    int n = nums.size();
    for (int i = 0; i < n-k; ++i) {
        pq.push(nums[i]);
    }
    for (int i = n-k; i < n; ++i) {
        if (nums[i]<pq.top()){
            pq.pop();
            pq.push(nums[i]);
        }
    }
    return pq.top();
}
//TODO 修正

int main(){
    vector<int> a = {3,2,3,1,2,4,5,5,6};
    cout << findKthLargest(a,4);
    return 0;
}