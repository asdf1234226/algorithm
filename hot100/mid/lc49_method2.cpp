//
// Created by SP on 2023/11/1.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

//对每个字符串排序后作为key
vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    unordered_map<string, vector<string>> mp;
    for (auto str: strs) {
        string key = str;
        sort(key.begin(),key.end());
        mp[key].push_back(str);
    }
    vector<vector<string>> ans;
    for (auto it: mp) {
        ans.push_back(it.second);
    }
    return ans;
}

int main(){
    vector<string> a = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = groupAnagrams(a);
    return 0;
}