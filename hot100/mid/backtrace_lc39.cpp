//
// Created by SP on 2023/11/7.
//

//candidates 中的 同一个 数字可以 无限制重复被选取
//输入：candidates = [2,3,6,7], target = 7
//输出：[[2,2,3],[7]]

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> ans;
vector<int> path;

void dfs(vector<int>& candidates, int target, int start){
    if (target==0)
    {
        ans.push_back(path);
        return;
    }
    if (target<0)//剪枝
    {
        return;
    }
    for (int i = start; i < candidates.size(); i++)
    {
        path.push_back(candidates[i]);
        dfs(candidates,target-candidates[i],i);
        path.pop_back();
    }

}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    dfs(candidates,target,0);
    return ans;
}

void print_v(vector<vector<int>>& a){
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    } 
}


int main(){
    vector<int> a ={2,3,6,7};
    vector<vector<int>> res = combinationSum(a,7);
    print_v(res);
    return 0;
}