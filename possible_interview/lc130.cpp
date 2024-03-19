// 给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，
// 并将这些区域里所有的 'O' 用 'X' 填充。

// 输入：board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
// 输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
// 解释：被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 
// 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，
// 则称它们是“相连”的。

#include<iostream>
#include<vector>
using namespace std;

int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
void dfs(vector<vector<char>>& board, int x, int y){
    board[x][y]='A';//标记访问过
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0&& nx<board.size() && ny>=0 && ny<board[0].size() && board[nx][ny]=='O'){
            dfs(board,nx,ny);
        }
    }

}
//任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'
void solve(vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); i++)
    {
        if (board[i][0]=='O')
        {
            dfs(board,i,0);
        }
        if (board[i][board[0].size()-1]=='O')
        {
            dfs(board,i,board[0].size()-1);
        }
    }
    for (int j = 0; j < board[0].size(); j++)
    {
        if (board[0][j]=='O')
        {
            dfs(board,0,j);
        }
        if (board[board.size()-1][j]=='O')
        {
            dfs(board,board.size()-1,j);
        }
    }
    for (int i = 0; i < board.size(); i++)
    {
        for(int j=0;j<board[0].size();j++){
            if (board[i][j]=='O')//不在边界，或不在边界相连的
            {
                board[i][j]='X';
            }else if (board[i][j]=='A')//在边界或相连
            {
                board[i][j]='O';
            }
        }
    }
}

int main(){
    vector<vector<char>> a = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    solve(a);
    for (int i = 0; i < a.size(); i++)
    {
        for(int j=0;j<a[0].size();j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}