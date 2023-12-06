// 给定一个表示 DNA序列 的字符串 s ，
// 返回所有在 DNA 分子中出现不止一次的 长度为 10 的序列(子字符串)。  

// 输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
// 输出：["AAAAACCCCC","CCCCCAAAAA"]

#include<iostream>
#include<set>
#include <map>
#include<vector>
using namespace std;   


vector<string> findRepeatedDnaSequences(string s) {
    vector<string> ans;
    set<string> st;//去重
    if (s.size()<10)
    {
        return ans;
    }
    map<string, int> mp;
    for (int end = 9; end < s.size(); end++)
    {
        string str = s.substr(end-9,10);//固定长度的滑动窗口
        mp[str]++;
        if (mp[str]>1)
        {
            st.insert(str);
        }
    }
    for(auto it: st){
        ans.push_back(it);
    }
    return ans;
}

int main(){
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> a = findRepeatedDnaSequences(s);
    for (size_t i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}