#include<iostream>
#include<vector>
using namespace std;

// 如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
// 如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
// 如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
// 如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
// 给你 m x n 网格面板 board 的当前状态，返回下一个状态
// 注意：
//面板上所有格子需要同时被更新：你不能先更新某些格子，然后使用它们的更新后的值再更新其他格子。
// 输入：board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
// 输出：[[0,0,0],[1,0,1],[0,1,1],[0,1,0]]

//由于不能先更新一些，再使用更新后的值更新其他，所以要拷贝一份（类似快照），根据快照的来修改原值
void gameOfLife(vector<vector<int>>& board) {
    int dx[8] = {-1,0,1,0,-1,1,-1,1};
    int dy[8] = {0,-1,0,1,-1,1,1,-1};
    vector<vector<int>> copyBoard = board;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            int live = 0;
            for(int k=0;k<8;k++){
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(nx>=0&&nx<board.size()&&ny>=0&&ny<board[0].size()&&copyBoard[nx][ny]==1){
                    live++;
                }
            }
            //规则1 或 规则3
            if ((live<2 || live >3)&& copyBoard[i][j]==1)
            {
                board[i][j]=0;
            }
            //规则4
            if (copyBoard[i][j]==0 && live==3){
                board[i][j]=1;
            }            
        }
    }
}

//由于不能先更新一些，再使用更新后的值更新其他，所以要拷贝一份（类似快照），根据快照的来修改原值
void gameOfLife(vector<vector<int>>& board) {
    int dx[8] = {-1,0,1,0,-1,1,-1,1};
    int dy[8] = {0,-1,0,1,-1,1,1,-1};

    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            int live = 0;
            for(int k=0;k<8;k++){
                if (board[i][j]&1==1)
                {
                    board[i][j]|=2;//倒数第二位上记录1
                }
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(nx>=0&&nx<board.size()&&ny>=0&&ny<board[0].size()&&(board[nx][ny]&1)==1){
                    live++;
                }
            }    
            //规则1 或 规则3
            if ((live<2 || live >3)&& (board[i][j]&1)==1)
            {
                //倒数第二位清零
                board[i][j]&=(~2);
            }
            //规则4
            if ((board[i][j]&1)==0 && live==3){
                board[i][j]|=2;
            }   
        }
    }
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            board[i][j]>>=1;//右移1位
        }
    }
}



int main(){
    vector<vector<int>> a = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    gameOfLife_opt(a);
    for (int i = 0; i < a.size(); i++)
    {
        for(int j=0;j<a[0].size();j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}