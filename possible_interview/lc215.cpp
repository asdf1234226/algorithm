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

//优先队列，小顶堆，容量为k
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int,vector<int>,greater<int>> pq;
    for(auto it: nums){
        if(pq.size()<k){
            pq.push(it);
        }else
        {
            if(it>pq.top()){
                pq.pop();
                pq.push(it);
            }
        }
    }
    return pq.top();
}

int main(){
    vector<int> a = {3,2,3,1,2,4,5,5,6};
    cout << findKthLargest(a,4);
    return 0;
}