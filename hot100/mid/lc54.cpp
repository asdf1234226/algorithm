//
// Created by SP on 2023/11/6.
//

//给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素
#include <iostream>
#include <vector>
using namespace std;

//https://leetcode.cn/problems/spiral-matrix/solutions/2362055/54-luo-xuan-ju-zhen-mo-ni-qing-xi-tu-jie-juvi/?envType=study-plan-v2&envId=top-100-liked
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    //up,down,left,right四个边界来模拟
    int m = matrix.size();
    int n =matrix[0].size();
    int up=0,down=m-1;
    int left=0,right=n-1;
    vector<int> ans;
    while(true){
        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[up][i]);
        }
        up++;
        if(up>down){
            break;
        }
        
        for (int i = up; i <= down; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;
        if(right<left){
            break;
        }

        for(int i=right;i>=left;i--){
            ans.push_back(matrix[down][i]);
        }
        down--;
        if(down<up){
            break;
        }
        for(int i=down;i>=up;i--){
            ans.push_back(matrix[i][left]);
        }
        left++;
        if(left>right){
            break;
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> a = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> res = spiralOrder(a);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    
    //输出{1,2,3,6,9,8,7,4,5}
}