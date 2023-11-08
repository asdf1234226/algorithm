//
// Created by SP on 2023/11/7.
//

//找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
//只使用数字1到9, 每个数字 最多使用一次
//k = 3, n = 9
//[[1,2,6], [1,3,5], [2,3,4]]


#include<iostream>
#include<vector>
using namespace std;
//所有三个数的组合，且和为n

vector<vector<int>> ans;
vector<int> path;
void dfs(int k, int n, int start, int sum){
    if (path.size()==k)//递归终止条件
    {
        if (n==sum)//只有和等于n才能加入答案
        {
            ans.push_back(path);
        }  
        return;
    }
    if (sum>n)
    {
        return;
    }
    for (int i = start; i <= 9; i++)
    {
        path.push_back(i);
        dfs(k,n,i+1,sum+i);//i+1避免重复选a[i]
        path.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    dfs(k,n,1,0);
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
    vector<vector<int>> a =combinationSum3(3,9);
    print_v(a);
    return 0;
}