// 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
// 输出：["((()))","(()())","(())()","()(())","()()()"]

#include<iostream>
#include<vector>
using namespace std;

//TODO   不熟悉
//思路，cnt_l记已有的(，cnt_r记已有的)
//cntl  无条件添加，只要<n
//cntr  cntr<n && cntr<cntl

//ATTENTION   不如用path存储

vector<string> ans;
void dfs(string s,int n, int l, int r){
    if (l>n || r>n)
    {
        return;
    }
    if (l==n&&r==n)
    {
        ans.push_back(s);
    }
    if (l<n)
    {
        //会创建新的字符串，所以无需回溯
        dfs(s+"(",n,l+1,r);
    }
    if (r<n && r<l)
    {
        dfs(s+")",n,l,r+1);
    }
}
vector<string> generateParenthesis(int n){
    dfs("",n,0,0);
    return ans;
}


int main(){
    vector<string> a = generateParenthesis(4);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}