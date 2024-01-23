// 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
// 输出：["((()))","(()())","(())()","()(())","()()()"]

#include<iostream>
#include<vector>
using namespace std;

//TODO  要记住思路 
//cnt_l和cnt_r计数
//添加左括号的条件  cnt_l < n
//添加右括号的条件  cnt_r < n && cnt_r<cnt_l

vector<string> res;
vector<char> path;
void dfs(int n, int cnt_l, int cnt_r){
    if (cnt_l>n || cnt_r>n)
    {
        return;
    }
    if (cnt_l==n && cnt_r==n)
    {
        string s = "";
        for(auto it: path){
            s+=it;
        }
        res.push_back(s);
        return;
    }
    if (cnt_l<n)
    {
        path.push_back('(');
        dfs(n,cnt_l+1,cnt_r);
        path.pop_back();
    }
    if (cnt_r<n && cnt_r<cnt_l)
    {
        path.push_back(')');
        dfs(n, cnt_l,cnt_r+1);
        path.pop_back();
    }
}
vector<string> generateParenthesis(int n) {
    dfs(n,0,0);
    return res;
}

int main(){
    vector<string> a = generateParenthesis(3);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}