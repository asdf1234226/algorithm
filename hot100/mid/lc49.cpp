//
// Created by SP on 2023/11/1.
//

//对每个字符串，统计26个字母出现的次数，拼接作为map的key
#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
using namespace std;

int cnt[26];


vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> cnt_map;
    for (int i = 0; i < strs.size(); ++i) {
        memset(cnt,0, sizeof  cnt);
        for (int j = 0; j < strs[i].length(); ++j) {
            char c = strs[i][j];
            cnt[c-'a']++;
        }
        string key ="";
        for (int j = 0; j < 26; ++j) {
            key+=cnt[j];
        }
        auto it = cnt_map.find(key);
        if (it!=cnt_map.end()){
            it->second.push_back(strs[i]);
        } else{
            vector<string> newv;
            newv.push_back(strs[i]);
            cnt_map.insert(make_pair(key,newv));
        }
    }
    vector<vector<string>> ans;
    for (auto it: cnt_map) {
        ans.push_back(it.second);
    }
    cout << ans.size();
    return ans;
}

int main(){
    vector<string> a = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = groupAnagrams(a);
    return 0;
}