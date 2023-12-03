//
// Created by SP on 2023/11/12.
//

//m * n
//每行的元素从左到右升序排列。
//每列的元素从上到下升序排列。
//输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
//输出：true

#include <iostream>
#include <vector>
using namespace std;

//左下角或者右上角的点
//以右上角点为例，逆时针旋转45°，
//  15
// 11 19
//类似二叉搜索树
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int i = 0;
    int j = matrix[0].size()-1;
    while (i<matrix.size() && j>=0){
        if (target>matrix[i][j]){
            i++;
        } else if (target<matrix[i][j]){
            j--;
        }
        else
        {
            return true;
        }
    }
    return false;
}
