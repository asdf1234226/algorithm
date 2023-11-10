//
// Created by SP on 2023/11/8.
//

//输入：s = "25525511135"
//输出：["255.255.11.135","255.255.111.35"]
//有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0

#include<iostream>
#include<vector>
using namespace std;

vector<string> ans;
vector<string> path;
bool isValid(string s, int l ,int r){//判断是有效ip
    int res = 0;
    while (l<=r)
    {
        res= res*10+ s[l]-'0';
        l++;
    }
    return res>=1 && res<=255; 
}

void dfs(string s, int start){
    if (start>s.size())
    {
        return;
    }
    
    if (path.size()==4)//四个部分
    {
        if (start==s.size())//并且刚好走到s的结尾
        {
            string str="";
            for (int i = 0; i < 3; i++)
            {
                str+=path[i];
                str+=".";
            }
            str+=path[3];
            ans.push_back(str);
        }
        return;
    }
    for (int i = start; i < start+3; i++)//每次最少一个，最多三个作为ip的一部分
    {
        if (isValid(s, start, i))
        {
            path.push_back(s.substr(start, i-start+1));
            dfs(s,i+1);
            path.pop_back();
        }
    }
}
vector<string> restoreIpAddresses(string s) {
    dfs(s,0);
    return ans;
}

int main(){
    vector<string> res = restoreIpAddresses("25525511135");
    for(auto it : res){
        cout << it << endl;
    }
    return 0;
}