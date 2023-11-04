
#include<iostream>
#include <vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
#include<set>
using namespace std;

struct Compare
{
    bool operator()(const vector<int>& a, const vector<int>& b) const{
        return a<b;
    }
};


//找出三个数,a+b+c=0;
vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> ans;
    int n = nums.size();
    if (n<=2)
    {
        return ans;
    }
    set<vector<int>, Compare> st;
    for (int i = 0; i < n; i++)
    {
        int target = -nums[i];//a+b=-c，用两数之和思路
        unordered_map<int, int> mp;
        for (int j = 0; j < n && j!=i ; j++)
        {
            auto it = mp.find(target-nums[j]);
            if (it!=mp.end())
            {
                vector<int> vt = {nums[i],nums[j],nums[it->second]};
                sort(vt.begin(), vt.end());
                st.insert(vt);
            }
            else{
                mp[nums[j]]=j;
            }
        }  
    }
    ans.assign(st.begin(), st.end());
    return ans;
}

int main(){
    vector<int> a = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = threeSum(a);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j<3; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}