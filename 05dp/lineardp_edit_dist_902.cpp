//
// Created by SP on 2023/10/29.
//

#include<iostream>
#include<cstring>
using namespace std;

//删除   dp[i-1][j]+1
//插入   dp[i][j-1]+1
//替换   a[i]==b[j]   dp[i-1][j-1] 否则 dp[i-1][j-1]+1
int min_d(string word1, string word2){
    int n = word1.length();
    int m = word2.length();
    int dp[n+1][m+1];
    memset(dp,0x3f,sizeof dp);
    for (int i=0;i<=n;i++){
        dp[i][0]=i;
    }
    for (int j = 0; j <= m; ++j) {
        dp[0][j]=j;
    }
    for (int i = 1; i <=n ; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j]=min(dp[i-1][j]+1, dp[i-1][j-1]+1);
            if (word1[i-1]==word2[j-1]){
                dp[i][j]=min(dp[i][j], dp[i-1][j-1]);
            }
            else{
                dp[i][j]=min(dp[i][j], dp[i-1][j-1]+1);
            }
        }
    }
    return dp[n][m];
}


int main(){
    cout << min_d("horse", "ros");
    return 0;

}