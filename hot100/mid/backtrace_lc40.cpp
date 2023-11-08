//
// Created by SP on 2023/11/7.
//

//candidates 中的每个数字在每个组合中只能使用 一次 。
//解集不能包含重复的组合。

//输入: candidates = [10,1,2,7,6,1,5], target = 8,
//输出:[[1,1,6],[1,2,5],[1,7],[2,6]]


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int>> ans;
vector<int> path;
//要去重的是同一树层上的“使用过”，同一树枝上的都是一个组合里的元素，不用去重。
void dfs(vector<int>& candidates, bool used[], int target, int start){
    if (target==0)
    {
        ans.push_back(path);//加入答案集合的条件
        return;
    }
    if (target<0)//剪枝
    {
        return;
    }
    for (int i = start; i < candidates.size(); i++)
    {
        if (i>0 && candidates[i]==candidates[i-1] && !used[i-1])
        {
            continue;
        }
        
        int num = candidates[i];
        used[i]=true;
        path.push_back(num);
        dfs(candidates,used,target-num,i+1);
        path.pop_back();
        used[i]=false;
        
    }
    
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    int n = candidates.size();
    bool used[n];
    dfs(candidates,used,target,0);
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
    //vector<int> a = {10,1,2,7,6,1,5};
    vector<int> a = {2,2,2};
    vector<vector<int>> res = combinationSum2(a,2);
    print_v(res);
    return 0;
}