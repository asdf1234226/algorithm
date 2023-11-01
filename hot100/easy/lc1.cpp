//
// Created by SP on 2023/10/31.
//

#include<iostream>
#include <vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int, int> help;
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        auto it = help.find(target-nums[i]);
        if (it!=help.end()){
            ans.push_back(i);
            ans.push_back(it->second);
            break;
        } else{
            help.insert(make_pair(nums[i], i));
        }
    }
    return ans;
}

int main(){
    vector<int> a = {2,7,11,15};
    vector<int> res = twoSum(a,9);
}