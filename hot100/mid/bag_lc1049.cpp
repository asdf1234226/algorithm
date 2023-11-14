
// 有一堆石头，每块石头的重量都是正整数。每一回合，从中选出任意两块石头，然后将它们一起粉碎
// 最后，最多只会剩下一块石头。返回此石头最小的可能重量。如果没有石头剩下，就返回 0。
// 输入：[2,7,4,1,8,1]
// 输出：1

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

//尽可能把石头分为重量相同的两堆
int lastStoneWeightII(vector<int>& stones)
{
    int n = stones.size();
    int sum = 0;
    for(auto it: stones){
        sum+=it;
    }
    int target = sum/2;
    int f[target+1];
    memset(f,0,sizeof f);
    //0, 1背包
    for (int i = 0; i < n; i++)
    {
        for(int j = target; j>=stones[i]; j--){
            f[j]=max(f[j], f[j-stones[i]]+stones[i]);//体积stones[i]，价值stones[i]
        }
    }
    return sum -f[target] -f[target];//一堆重量为f[target]，另一堆重量为sum-f[target]
    
}

int main(){
    vector<int> a = {2,7,4,1,8,1};
    cout << lastStoneWeightII(a);
    return 0;
}