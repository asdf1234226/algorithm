//
// Created by SP on 2023/12/21.
//

//在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。
//输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
//输出：4

#include <iostream>
#include <vector>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {

}

int main(){
    return 0;
}



//前缀和+二分
class Solution {
public:
    static const int N = 310;
    int s[N][N]; // 前缀和数组

    bool check(int m, int n, int x)
    {
        // 枚举符合条件的子矩阵
        for(int i = 0; i <= m - x; i++)
        {
            for(int j = 0; j <= n - x; j++)
            {
                int x1 = i + 1, y1 = j + 1; // 子矩阵的左上角
                int x2 = x1 + x - 1, y2 = y1 + x - 1; // 右下角
                int t = s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1]; // 子矩阵的前缀和
                if(t == x * x) // 存在返回true
                    return true;
            }
        }

        return false;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + matrix[i-1][j-1] - '0'; // 前缀和计算

        int l = 0, r = min(m, n);

        // 二分答案
        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
            if(check(m, n, mid)) l = mid;
            else r = mid - 1;
        }

        return l * l;
    }
};


int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    //dp[i][j]为(i,j)为右下角能形成的最大正方形边长
    //取决于 左边点， 上边点 和 左上角点 项能形成的最大正方形边长，等于三者最小的+1
    vector<vector<int>> dp(m,vector<int>(n,0));
    int ans = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]=='1'){
                if(i==0 || j==0){
                    dp[i][j]=1;
                }else
                {
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j], dp[i][j-1]))+1;

                }
                ans=max(ans,dp[i][j]);//更新最大边长
            }

        }

    }
    return ans*ans;//返回边长*边长
}