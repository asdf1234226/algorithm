//给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
//
//输入: [3,2,3,1,2,4,5,5,6], k = 4
//输出: 4

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//小顶堆，大小为k，堆顶元素就是
int findKthLargest(vector<int>& nums, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < nums.size(); i++)
    {
        if(pq.size()<k){
            pq.push(nums[i]);
        }else
        {
            if (pq.top()<nums[i])
            {
                pq.pop();
                pq.push(nums[i]);
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