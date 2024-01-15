// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[1,2,3,6,9,8,7,4,5]


#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    int m = matrix.size();
    int n = matrix[0].size();
    int l = 0, r = n-1, u = 0, d = m-1;
    while (true)  //TODO   忘了这个while(true)循环，后面才能搭配break
    {
        for(int j=l;j<=r;j++){
            res.push_back(matrix[u][j]);
        }
        u++;
        if(u>d){
            break;
        }
        for(int i=u;i<=d;i++){
            res.push_back(matrix[i][r]);
        }
        r--;
        if(l>r){
            break;
        }
        for(int j=r;j>=l;j--){
            res.push_back(matrix[d][j]);
        }
        d--;
        if(u>d){
            break;
        }
        for(int i =d;i>=u;i--){
            res.push_back(matrix[i][l]);
        }
        l++;
        if(l>r){
            break;
        }
    }
    return res;
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