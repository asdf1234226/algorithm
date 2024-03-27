// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[1,2,3,6,9,8,7,4,5]


#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int m = matrix.size(), n = matrix[0].size();
    int up = 0, down = m-1, left =0, right=n-1;
    while (true)
    {
        for (int j = left; j <= right; j++)
        {
            ans.push_back(matrix[up][j]);
        }
        up++;
        if (up>down)
        {
            break;
        }
        for (int i = up; i <= down; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;
        if (left>right)
        {
            break;
        }
        for (int j = right; j >= left; j--)
        {
            ans.push_back(matrix[down][j]);
        }
        down--;
        if (up>down)
        {
            break;
        }
        for (int i = down; i >= up; i--)
        {
            ans.push_back(matrix[i][left]);
        }
        left++;
        if (left>right)
        {
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