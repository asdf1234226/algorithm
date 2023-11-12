//
// Created by SP on 2023/11/11.
//
//输入: numRows = 5
//输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    for (int i = 0; i < numRows; ++i) {//初始化三角形矩阵，值为1
        vector<int> a;
        for (int j = 0; j <=i ; ++j) {
                a.push_back(1);
        }
        ans.push_back(a);
    }

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j <=i ; ++j) {
            if (j==0 || j== i) continue;//第一列和对角线列不变
            ans[i][j]=ans[i-1][j-1] + ans[i-1][j];

        }
    }
    return ans;

}

void print_v(vector<vector<int>>& a){
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    vector<vector<int>> a = generate(5);
    print_v(a);
    return 0;
}