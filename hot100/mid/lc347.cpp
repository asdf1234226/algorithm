//
// Created by SP on 2023/11/12.
//
//给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素
//输入: nums = [1,1,1,2,2,3], k = 2
//输出: [1,2]


#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

typedef pair<int, int> PII;


vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> mp;//统计个数
    priority_queue<PII> pq;//默认是降序
    for(auto i: nums){
        if (mp.find(i)!=mp.end()){
            mp[i]++;
        } else{
            mp[i]=1;
        }
    }
    for (auto p: mp) {
        pq.push(PII(p.second,p.first));
    }
    vector<int> ans;
    while (k>0){
        PII pi = pq.top();
        pq.pop();
        ans.push_back(pi.second);
        k--;
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