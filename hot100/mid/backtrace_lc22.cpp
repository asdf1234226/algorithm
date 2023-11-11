//
// Created by SP on 2023/11/11.
//

#include<iostream>
#include<vector>
using namespace std;

vector<string> ans;
vector<int> path;

int getCount(vector<int> path, int a){
    int count=0;
    for(auto it: path){
        if (it==a){
            count++;
        }
    }
    return count;
}

void dfs(int n){
    if (getCount(path,-1)==n && getCount(path,1)>= getCount(path,1)){
        for(int i = path.size() ;i<2*n;i++){
            path.push_back(1);//补全右括号
        }
        string str = "";
        for (auto it : path) {
            if (it == -1){
                str+="(";
            } else if (it==1){
                str+=")";
            }
        }
        ans.push_back(str);
        return;
    }
    if (getCount(path,-1)< getCount(path,1))
    {
        return;
    }
    for (int i = -1; i <=1&& i!=0; ++i) {//要么放0，要么放1
        if (getCount(path,-1)<n && getCount(path,-1)>= getCount(path,1)){//剪枝，任何时候path中的-1个数应该>= 1
            path.push_back(i);
            dfs(n);
            path.pop_back();
        }
    }
}

vector<string> generateParenthesis(int n) {
    dfs(n);
    return ans;
}

int main(){
    vector<string> s = generateParenthesis(3);
    for (int i = 0; i < s.size(); ++i) {
        cout << s[i] << endl;
    }
    return 0;
}