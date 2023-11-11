//
// Created by SP on 2023/11/11.
//

#include<iostream>
#include<vector>
using namespace std;

vector<string> ans;
vector<char> path;


void dfs(int n, int cnt_l, int cnt_r){
    if (cnt_l==n && cnt_r==n){
        string s = "";
        for (int i = 0; i < path.size(); ++i) {
            s+=path[i];
        }
        ans.push_back(s);
    }

    if (cnt_l<cnt_r)
    {
        return;
    }

    if (cnt_l < n){ //如果左括号的数量小于n
        //添加一个左括号
        path.push_back('(');
        dfs(n, cnt_l+1, cnt_r);
        path.pop_back();
    }

    if (cnt_r<cnt_l){ //如果右括号的数量小于左括号的数量
        path.push_back(')'); //添加一个右括号
        dfs(n, cnt_l, cnt_r+1);
        path.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    dfs(n,0,0);
    return ans;
}

int main(){
    vector<string> s = generateParenthesis(3);
    for (int i = 0; i < s.size(); ++i) {
        cout << s[i] << endl;
    }
    return 0;
}