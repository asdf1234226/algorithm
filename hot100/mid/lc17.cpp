#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<vector<char>> mp = {{},{},{'a','b','c'}, {'d','e','f'}, {'g','h','i'}, {'j','k','l'}};
vector<string> ans;
string path;

void dfs(string digits, int x){
    if(x==digits.size()){//越界，已经加过最后一个字母了
        ans.push_back(path);
        return;
    }
    int num = digits[x]-'0';
    vector<char> chars = mp[num];//数字对应的字母集合，如2对应a,b,c
    for (int i = 0; i < chars.size(); i++)
    {
        path+=chars[i];
        dfs(digits,x+1);
        path.pop_back();//撤销选择
    }
}
void help(string digits)
{
    dfs(digits,0);
}



int main(){
    string s = "23";
    help(s);
    for (auto str: ans)
    {
        cout << str << endl;
    }
    
    return 0;
}