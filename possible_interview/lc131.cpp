#include<iostream>
#include<vector>
using namespace std;
// 输入：s = "aab"
// 输出：[["a","a","b"],["aa","b"]]
vector<vector<string>> res;
vector<string> path;

bool isHui(string s, int l, int r){
    while (l<r)
    {
        if (s[l]!=s[r])
        {
            return false;
        }else
        {
            l++;
            r--;
        }
    }
    return true;
}
//组合，要有start, 想象那张图,同一行可以取的i从start到s.size()-1
void dfs(string s, int start){
    if (start==s.size())
    {
        res.push_back(path);
        return;
    }
    for (int  i = start; i < s.size(); i++)
    {
        if (isHui(s,start,i))
        {
            path.push_back(s.substr(start,i-start+1));
            dfs(s,i+1);//下一层的开始下标是i+1
            path.pop_back();
        }else
        {
            continue;
        }
    }
}
vector<vector<string>> partition(string s) {
    dfs(s,0);
    return res;
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