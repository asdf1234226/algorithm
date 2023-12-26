// 在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
// 你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。
// 你从其中的一个加油站出发，开始时油箱为空。

// 给定两个整数数组 gas 和 cost ，如果你可以按顺序绕环路行驶一周，
// 则返回出发时加油站的编号，否则返回 -1 。如果存在解，则 保证 它是 唯一 的。

// 输入: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
// 输出: 3
// 解释:
// 从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
// 开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
// 开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
// 开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
// 开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
// 开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
// 因此，3 可为起始索引。

#include<iostream>
#include<vector>
using namespace std;

//[-2,-2,-2,3,3]
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    vector<int> diff(n,0);
    int sum = 0;
    // 只要总油量 >= 总消耗，就一定有解（某站加的油大于消耗，多出来的油可以填补其他站的亏空）
    for (int i = 0; i < n; i++)
    {
        diff[i]=gas[i]-cost[i];
        sum+=diff[i];
    }
    if (sum<0) //总油量<总消耗
    {
        return -1;
    }

    int start = 0; //出发点
    int curSum = 0; //从出发点出发的剩余油量
    for(int i=0;i<n;i++){
        curSum+=diff[i];
        if (curSum<0) //已经到达不了下个点，就要清状态并从下一个点作为开始点
        {
            start=i+1;
            curSum=0;
        }
    }
    return start;
}

int main(){
    vector<int> a = {1,2,3,4,5};
    vector<int> b ={3,4,5,1,2};
    cout << canCompleteCircuit(a,b);
    return 0;
}