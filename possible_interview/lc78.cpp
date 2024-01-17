// 输入：nums = [1,2,3] 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

#include<iostream>
#include<vector>
using namespace std;

//TODO  又忘了
vector<vector<int>> res;
vector<int> path;
void dfs(vector<int>& nums, int start){
    res.push_back(path);
    if (start>=nums.size())//终止条件
    {
        return;
    }
    for (int i = start; i < nums.size(); i++)
    {
        path.push_back(nums[i]);
        dfs(nums,i+1);
        path.pop_back();
    }
}
vector<vector<int>> subsets(vector<int>& nums){
    dfs(nums,0);
    return res;
}

int main(){
    vector<int> a = {1,2,3};
    vector<vector<int>> res = subsets(a);     
    for (int i = 0; i < res.size(); i++)     
    {         
        for (int j = 0; j < res[i].size(); j++){             
            cout << res[i][j] << " ";         
        }         
        cout << endl;     
    }     
    cout << res.size();
}