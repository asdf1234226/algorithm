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

// 堆大小为k，堆顶是要返回的元素，所以用小顶堆
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; ++i) {
        pq.push(nums[i]);
    }
    //堆只存前k个大的元素
    for (int i = k; i < nums.size(); ++i) {
        if (nums[i]>pq.top()){
            pq.pop();
            pq.push(nums[i]);
        }
    }
    return pq.top();
}

int findKthLargest1(vector<int>& nums, int k) {
    priority_queue<int> pq;
    //大顶堆，全放入
    for (int i = 0; i < nums.size(); ++i) {
        pq.push(nums[i]);
    }
    //弹出k-1个，剩下的堆顶就是第k大
    while (k-1>0){
        pq.pop();
        k--;
    }
    return pq.top();
}


int main(){
    vector<int> a = {3,2,3,1,2,4,5,5,6};
    cout << findKthLargest(a,4);
    return 0;
}


