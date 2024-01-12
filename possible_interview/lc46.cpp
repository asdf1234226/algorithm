#include<iostream>
#include<vector>
using namespace std;

vector<int> path;
const int N = 1e5+10;
bool visit[1010];
void dfs(vector<int>& nums, vector<vector<int>>& res){//如果作为res参数传递，要用引用
    if(path.size()==nums.size()){
        res.push_back(path);//递归终止条件
        return;
    }
    for(int i = 0;i< nums.size();i++){
        if(!visit[i]){
            visit[i]=true;
            path.push_back(nums[i]);
            dfs(nums,res);
            path.pop_back();
            visit[i]=false;
        } 
    }
}


vector<vector<int>> permute(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> res;
    dfs(nums, res);
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
    vector<int> a ={1,2,3};
    vector<vector<int>> res = permute(a);
    print_v(res);
    return 0;
}