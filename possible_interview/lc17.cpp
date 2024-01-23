// 输入：digits = "23"
// 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]

#include<iostream>
#include<vector>
using namespace std;

vector<string> res;
vector<char> path;
vector<string> letters = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void dfs(string digits, int start){
    if (path.size()==digits.size())
    {
        string str = "";
        for(auto it: path){
            str+=it;
        }
        res.push_back(str);
        return;
    }
    for (int i = start; i < digits.size(); i++)
    {
        int num = digits[i]-'0';
        for (int j=0;j<letters[num].size();j++)
        {
            path.push_back(letters[num][j]);
            dfs(digits, i+1);
            path.pop_back();
        }
    }
}
vector<string> letterCombinations(string digits) {
    dfs(digits,0);
    return res;
}

int main(){
    vector<string> a = letterCombinations("23");
    for(auto it: a){
        cout << it << " ";
    }
    return 0;
}