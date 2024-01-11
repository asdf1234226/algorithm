// 输入：n = 3
// 输出：3
// 解释：有三种方法可以爬到楼顶。
// 1. 1 阶 + 1 阶 + 1 阶
// 2. 1 阶 + 2 阶
// 3. 2 阶 + 1 阶
int climbStairs(int n) {
    if(n==1 || n==2) return n;
    vector<int> dp(n+1,0);
    for(int i=3;i<=n;i++){
        dp[n]=dp[n-1]+dp[n-2];
    }
    return dp[n];

}

// int a = 1, b =2;
for(int i=3;i<=n;i++){
    a=a+b;
    b=a;
}
return a;