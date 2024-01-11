
//前k个高频元素
// 输入: nums = [1,1,1,2,2,3], k = 2
// 输出: [1,2]

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    priority_queue<vector<int>> pq;
    map<int, int> mp;//统计个数
    for(auto num: nums){
        mp[num]++;
    }
    for(auto it: mp){
        pq.push({it.second, it.first});
    }
    vector<int> ans;
    while(k--){
        ans.push_back(pq.top()[1]);
        pq.pop();
    }
    return ans;
}

int main(){
    vector<int> a = {1,1,1,2,2,3};
    vector<int> res = topKFrequent(a,2);
    for(int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    return 0;
}