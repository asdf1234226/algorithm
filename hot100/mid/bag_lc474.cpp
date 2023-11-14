// 给你一个二进制字符串数组 strs 和两个整数 m 和 n 。  
// 请你找出并返回 strs 的最大子集的大小，该子集中 最多 有 m 个 0 和 n 个 1 。

// 输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3  
// 输出：4  
// 解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
// 其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1 ，大于 n 的值



//背包容量m个0和n个1
//字符串体积，0和1的个数
//字符串价值  1
//转换成0-1背包问题

#include<iostream> 
#include<vector> 
#include<cstring> 
using namespace std;

int countNum(string str, int num){
    int count = 0;
    for (int i = 0; i < str.size(); i++)
    {
        int a = str[i]-'0';
        if (a==num)
        {
            count++;
        }
    }
    return count;
}

int findMaxForm(vector<string>& strs, int m, int n)
{
    int dp[m+1][n+1];
    memset(dp,0, sizeof dp);
    for (int i = 0; i < strs.size(); ++i) {
        int zeroCount = countNum(strs[i], 0);
        int oneCount = countNum(strs[i],1);
        for (int j = m; j >= zeroCount; j--) {
            for (int k = n; k >= oneCount ; k--) {
                dp[j][k] = max(dp[j][k],dp[j-zeroCount][k-oneCount]+1);
            }
        }
    }
    return dp[m][n];
}

int main(){
    vector<string> a = {"10", "0001", "111001", "1", "0"};
    cout << findMaxForm(a,5,3);
    return 0;
}