// 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
// 你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
// 返回 滑动窗口中的最大值 。

// 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
// 输出：[3,3,5,5,6,7]

// 6,5,4,3,2,1


#include<iostream>
#include <queue>
#include<vector>
using namespace std;   

//会TLE
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    priority_queue<int> pq;
    vector<int> ans;
    int start = 0;
    queue<int> tmp;
    for(int end =0; end<n;end++){
        pq.push(nums[end]);
        if(end==k-1){
            int top = pq.top();
            ans.push_back(top);
        }
        else if(end>k-1){
            ////不能这么移除，每次只能移除nums[start]对应的，所以要用queue暂存
            while(!pq.empty()&&pq.top()>nums[start]){
                int num = pq.top();
                tmp.push(num);
                pq.pop();
            }
            if (!pq.empty()&&pq.top()==nums[start]){//移除nums[start]
                pq.pop();
            }
            while(!tmp.empty()){
                pq.push(tmp.front());
                tmp.pop();
            }
            /////
//            if (nums[start]==pq.top())//如果当前队列最大的元素正好是窗口中要被移除的nums[start]
//            {
//                pq.pop();
//            }
            int top = pq.top();
            ans.push_back(top);
            start++;//维护窗口大小为k
        }
    }
    return ans;
}

//最小的k个数：给定一个数组和一个数k，要求找出数组中最小的k个数。这也是单调队列的一个应用。

vector<int> maxSlidingWindow_final(vector<int>& nums, int k)
{
    deque<int> q;
    //维护单调队列，队头最大值，每次取队头
    vector<int> results;
    for (int i = 0; i < nums.size(); i++) {
        // 移除队列中比当前元素小的元素（nums[i]比队尾的更大，更新）
        while (!q.empty() && nums[i]>nums[q.back()]) {
            q.pop_back();
        }

        // 将当前元素添加到队列中
        q.push_back(i);

        // 移除队列中已经滑出窗口的元素
        if (q.front() <= i - k) {
            q.pop_front();
        }

        // 如果窗口已经形成，则将窗口中的最大值添加到结果中
        if (i >= k - 1) {
            results.push_back(nums[q.front()]);
        }
    }
    return results;
}
int main(){
    vector<int> a = {9,10,9,-7,-4,-8,2,-6};
    vector<int> ans = maxSlidingWindow(a,5);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}

