// 输入：n = 4
// 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

#include<iostream>
#include<vector>
using namespace std;

const int N = 10;
bool row[N];
bool col[N];
//斜线上是  y=x+b; y=-x+b ----> b=y-x; b= y+x
bool digit[N*2];
bool anti_digit[N*2];

void dfs(vector<vector<string>>& res, vector<string>& path, int index, int n){
    if(index==n){
        res.push_back(path);
        return;
    }
    for(int j = 0;j<n;j++){//[index,j],每行放一个
        if(row[index]||col[j]||digit[index+j]||anti_digit[j-index+n]){
            continue;
        }
        row[index]=col[j]=digit[index+j]=anti_digit[j-index+n]=true;
        path[index][j]='Q';
        dfs(res,path,index+1,n);
        path[index][j]='.';
        row[index]=col[j]=anti_digit[j-index+n]=digit[index+j]=false;
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> path;
    for (int i = 0; i < n; i++)
    {
        string str = "";
        for(int j=0;j<n;j++){
            str+=".";
        }
        path.push_back(str);
    }
    dfs(res,path,0,n);
    return res;
    
}

int main()
{
    vector<vector<string>> ans = solveNQueens(4);
    for(auto it: ans){
        for (int i = 0; i < it.size(); i++)
        {
            cout << it[i] << endl;
        }
        cout << "next....."<<endl;
    }
    
    return 0;
}