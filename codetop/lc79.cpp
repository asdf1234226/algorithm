#include<iostream>
#include<vector>
using namespace std;
// 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
// 同一个单元格内的字母不允许被重复使用。

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
const int N = 1010;
bool visit[N][N];

bool dfs(vector<vector<char>>& board, string word, int index, int x, int y){
    if (index == word.size()-1)//访问到最后一个字母
    {
        return true;
    }
    bool res = false;
    for (int i = 0; i < 4; i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (nx>=0 && nx < board.size() && ny>=0 && ny < board[0].size() && board[nx][ny]==word[index+1])
        {
            //下一个字母也在word中（只有在word中的才会被加入下轮）
            visit[nx][ny]=true;
            res |= dfs(board,word,index+1,nx,ny);
            visit[nx][ny]=true;
        }
    }
    return res;
}
bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j<board[0].size();j++)
        {
            if (board[i][j]==word[0])
            {
                return dfs(board, word, 0, i, j);
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