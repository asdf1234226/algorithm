//
// Created by SP on 2023/11/5.
//

//给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法
//matrix = [[1,1,1],[1,0,1],[1,1,1]]
//[[1,0,1],[0,0,0],[1,0,1]]


#include<iostream>
#include<vector>
#include<set>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    set<int> row;
    set<int> line;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j]==0)
            {
                row.insert(i);
                line.insert(j);
            }     
        }    
    }
    for(auto it: row){
        for (int j = 0; j < matrix[0].size(); j++)
        {
            matrix[it][j]=0;
        }
    }
    for(auto it: line){
        for (int i = 0; i < matrix.size(); i++)
        {
            matrix[i][it]=0;
        }
    }

}


int main(){
    vector<vector<int>> a = {{1,1,1}, {1,0,1}, {1,1,1}};
    setZeroes(a);
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[0].size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}