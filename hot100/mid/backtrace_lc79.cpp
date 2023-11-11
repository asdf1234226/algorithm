//
// Created by SP on 2023/11/11.
//

//给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
//输出：true

#include <iostream>
#include <vector>
using namespace std;



int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
bool visit[10][10];
bool dfs(vector<vector<char>>& board, int x, int y, string word, int index){
    if (index==word.size()-1){
        return true;
    }
    bool f = false;
    for (int i = 0; i < 4; ++i) {
        int nx = x+dx[i], ny = y+dy[i];
        if (nx>=0 && nx < board.size() && ny >=0 && ny <board[0].size() && !visit[nx][ny] &&word[index+1]== board[nx][ny]){
            visit[nx][ny]=true;
            f =  f || dfs(board, nx, ny, word, index+1);
            visit[nx][ny]= false;
        }
    }
    return f;
}

bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            if (board[i][j]==word[0]){
                if (dfs(board,i,j,word,0)){
                    return true;
                }
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