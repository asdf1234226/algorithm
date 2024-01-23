// 输入：candidates = [2,3,6,7], target = 7
// 输出：[[2,2,3],[7]]
// 解释：
// 2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
// 7 也是一个候选， 7 = 7 。
// 仅有这两种组合。

// 1 <= candidates.length <= 30
// 2 <= candidates[i] <= 40
// candidates 的所有元素 互不相同
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> res;
vector<int> path;
void dfs(vector<int>& candidates, int target, int start){
    if (target<0)
    {
        return;
    }
    if (target==0)
    {
        res.push_back(path);
        return;
    }
    for (int i = start; i < candidates.size(); i++)
    {
        path.push_back(candidates[i]);
        dfs(candidates, target-candidates[i], i);//note: 为什么要用start，要求的是组合不是排列，要求无序
        //为什么下一个dfs是i而不是i+1, candidates[i]可重复使用
        path.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    dfs(candidates, target, 0);
    return res;
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