
// 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
// 输出：[3,3,5,5,6,7]

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//只有更大更新的会进队列
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> res;
    deque<int> q;
    for(int i=0;i<n;i++){
        if(q.empty()){
            q.push_back(i);
        }else
        {
            //移除比nums[i]更老更小的
            while (!q.empty() && nums[q.back()]<nums[i])
            {
                q.pop_back();
            }
            q.push_back(i);//形成一个非递增的
        }
        
        if(i>=k-1){
            if (q.front()<i-k+1)//已经出队的
            {
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