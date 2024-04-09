// 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
// 输出：[3,3,5,5,6,7]

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//单调队列，将结果存入队头
//deque，要双端弹出，q.front(), q.back()
// q.push_back(), q.pop_back(), q.pop_front()
vector<int> maxSlidingWindow(vector<int>& nums, int k){
    deque<int> q;
    vector<int> res;
    int n = nums.size();
    for(int i=0;i<n;i++){
        if(q.empty()){
            q.push_back(i);
        }else{
            while(!q.empty()&&nums[q.back()]<nums[i]){
                q.pop_back();
            }
            q.push_back(i);
        }
        if(i>=k-1){
            if(i-q.front()+1>k){
                q.pop_front();
            }
            res.push_back(nums[q.front()]);
        }
    }
    return res;
}

int main(){
    vector<int> a ={1,3,-1,-3,5,3,6,7};
    vector<int> res = maxSlidingWindow(a,3);
    for(auto i: res){
        cout << i << ":";
    }
    return 0;
}