//
// Created by SP on 2023/11/7.
//

//给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
//输入：s = "aab"
//输出：[["a","a","b"],["aa","b"]]

#include<iostream>
#include<vector>
using namespace std;

vector<vector<string>> ans;
vector<string> path;

bool isHui(string s, int l, int r){
    while (l<r)
    {
        if (s[l]==s[r])
        {
            l++;
            r--;
        }else
        {
            return false;
        }
    }
    return true;
    
}
void dfs(string s, int start){
    if (start==s.size())
    {
        ans.push_back(path);
        return;
    }
    
    for (int i = start; i < s.size(); i++)
    {
        if (isHui(s,start,i))
        {
            //substring的第一个参数是起始位置，第二个参数是长度
            path.push_back(s.substr(start,i-start+1));
            dfs(s,i+1);
            path.pop_back();
        }
        else
        {
            continue;
        }
    }
    

}
vector<vector<string>> partition(string s) {
    dfs(s,0);
    return ans;
}


int main(){
    string s = "aab";
    vector<vector<string>> a = partition(s);
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}