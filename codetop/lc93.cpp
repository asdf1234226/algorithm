//输入：s = "25525511135"
//输出：["255.255.11.135","255.255.111.35"]
//有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0
#include<iostream>
#include<vector>
using namespace std;

vector<string> ans;
vector<string> path;

//TODO  不熟悉
bool isValid(string& s, int start, int end){
    int num = 0;
    if (s[start]=='0')
    {
        return end==start;//不能有前导0 
    }
    for (int i = start; i <= end; i++)
    {
        num=num*10+s[i]-'0';
    }
    return num>=0 && num<=255;
}
void dfs(string& s, int start){
    if (start>s.size())
    {
        return;
    }
    if (path.size()==4)//path.size()==4判断是否已经到结尾
    {
        if (start==s.size())
        {
            string str = path[0]+"."+path[1]+"."+path[2]+"."+path[3];
            ans.push_back(str);
        }
        return;
    }
    for (int i = start; i < start+3; i++)
    {
        if(isValid(s,start,i)){
            path.push_back(s.substr(start,i-start+1));
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