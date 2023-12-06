// 几张卡牌 排成一行，每张卡牌都有一个对应的点数。点数由整数数组 cardPoints 给出。
// 每次行动，你可以从行的开头或者末尾拿一张卡牌，最终你必须正好拿 k 张卡牌。
// 你的点数就是你拿到手中的所有卡牌的点数之和。
// 给你一个整数数组 cardPoints 和整数 k，请你返回可以获得的最大点数。

// 输入：cardPoints = [1,2,3,4,5,6,1], k = 3
// 输出：12
// 解释：第一次行动，不管拿哪张牌，你的点数总是 1 。但是，先拿最右边的卡牌将会最大化你的可
// 获得点数。最优策略是拿右边的三张牌，最终点数为 1 + 6 + 5 = 12 。


#include<iostream>
#include<vector>
using namespace std;


//总和固定，拿的最大点数<==> 剩余的点数最小  只会从开头或结尾拿，剩余的是中间的连续n-k个数
// n-k个连续子数组的最小和
//前缀和
int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    vector<int> preSum(n+1,0);//preSum[i]前i个数
    for (int i = 1; i <= n; i++)
    {
        preSum[i]=preSum[i-1]+cardPoints[i-1];
    }
    int min_sum = 0x3f3f3f3f;
    for (int i = 1; i+n-k-1 <= n; i++)  //(i+n-k-1)-i+1=n-k
    {
        min_sum=min(preSum[i+n-k-1]-preSum[i-1], min_sum);//公式pre[r]-pre[l-1]
    }
    return preSum[n]-min_sum;
}

int main(){
    vector<int> a = {1,2,3,4,5,6,1};
    cout << maxScore(a,3);
    return 0;
}