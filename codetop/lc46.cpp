#include<iostream>
#include<vector>
using namespace std;

const int N = 1010;
vector<int> path;
bool visit[N];

void dfs(vector<vector<int>>& res,vector<int>& nums){
    if (path.size()==nums.size())
    {
        res.push_back(path);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (!visit[i])
        {
            path.push_back(nums[i]);
            visit[i]=true;
            dfs(res,nums);
            visit[i]=false;
            path.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int>& nums){
    vector<vector<int>> ans;
    if (nums.size()==0)
    {
        return ans;
    }
    dfs(ans, nums);
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
    vector<int> a ={1,2,3};
    vector<vector<int>> res = permute(a);
    print_v(res);
    return 0;
}