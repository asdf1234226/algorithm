#include<iostream>
#include<vector>
using namespace std;

#include<iostream>
#include<vector>
using namespace std;

const int N = 1010;
bool visit[N][N];
//TODO   就用这个版本
bool dfs(vector<vector<char>>& board, string word, int x, int y, int index){
        if (index == word.size()) return true;
        int m = board.size();
        int n= board[0].size();
        if (x >= 0 && x < m && y >= 0 && y < n && !visit[x][y] && board[x][y] == word[index]){
            visit[x][y] = true;
            if (dfs(board,word,x - 1, y, index + 1) || dfs(board,word,x + 1, y, index + 1) || dfs(board,word,x, y - 1, index + 1) || dfs(board,word,x, y + 1, index + 1)) return true;
            visit[x][y] = false;
        }
        return false;
}
bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(dfs(board,word,i,j,0)){
                return true;
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
