// 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// 输出：true

#include<iostream>
#include<vector>
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
const int N = 1010;
bool visit[N][N];
bool dfs(vector<vector<char>>& board, string word, int x, int y, int index){
    if (index==word.size()-1)//访问到最后一个字母
    {
        return true;
    }
    bool flag = false;
    for (int i = 0; i < 4; i++)
    {
        int nx =x+dx[i];
        int ny=y+dy[i];
        if (nx>=0&&nx<board.size()&&ny>=0&&ny<board[0].size()&&!visit[nx][ny]&&word[index+1]==board[nx][ny])
        {
            visit[nx][ny]=true;
            flag |= dfs(board,word,nx,ny,index+1);
            visit[nx][ny]=false;
        }
    }
    return flag;
}
bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j]==word[0])
            {
                visit[i][j]=true;//要标记
                if(dfs(board,word,i,j,0)){
                    return true;
                }
                visit[i][j]=false;//要撤回
            }
        }
    }
    return false;
}

int main(){
    vector<vector<char>> board = {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    if (exist(board, "ABCCED"))
    {
        cout << "yes";
    } else{
        cout << "no";
    }
    return 0;
}