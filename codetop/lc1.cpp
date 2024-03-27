#include<iostream>
#include <vector>
#include<map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
    map<int, int> mp;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if(mp.find(target-nums[i])!=mp.end()){
            ans.push_back(i);
            ans.push_back(mp[target-nums[i]]);
        }
        mp[nums[i]]=i;
    }
    return ans;
}

int main(){
    vector<int> a = {2,7,11,15};
    vector<int> res = twoSum(a,9);
    for(int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }
    return 0;
}