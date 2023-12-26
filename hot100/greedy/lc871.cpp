// 汽车从起点出发驶向目的地，该目的地位于出发位置东面 target 英里处。
// 沿途有加油站，每个 station[i] 代表一个加油站，它位于出发位置东面 station[i][0] 
// 英里处，并且有 station[i][1] 升汽油。

// 假设汽车油箱的容量是无限的，其中最初有 startFuel 升燃料。
// 它每行驶1英里就会用掉1升汽油。

// 当汽车到达加油站时，它可能停下来加油，将所有汽油从加油站转移到汽车中。

// 为了到达目的地，汽车所必要的最低加油次数是多少？如果无法到达目的地，则返回 -1。
// 注意：如果汽车到达加油站时剩余燃料为0，它仍然可以在那里加油。
// 如果汽车到达目的地时剩余燃料为0 ，仍然认为它已经到达目的地。

// 输入：target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
// 输出：2
// 解释：
// 我们出发时有 10 升燃料。
// 我们开车来到距起点 10 英里处的加油站，消耗 10 升燃料。将汽油从 0 升加到 60 升。
// 然后，我们从 10 英里处的加油站开到 60 英里处的加油站（消耗 50 升燃料），
// 并将汽油从 10 升加到 50 升。然后我们开车抵达目的地。
// 我们沿途在1两个加油站停靠，所以返回 2 


#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations){
   int n =stations.size();
   //dp[i][j]前i个加油站([0,i-1])，最多加j次油，能走的最远距离
   //第i个加油站加还是不加(下标i-1)
   //加   dp[i-1][j-1]+stations[i-1][1]
   //不加  dp[i-1][j]
   vector<vector<int>> dp(n+1,vector<int>(n+1,0));
   for (int i = 0; i <= n; i++)
   {
      dp[i][0]=startFuel;
   }
   
   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= i; j++)//如果每个加油站都是最少的1升油，那j也要<=i
      {
         if (dp[i-1][j-1]>=stations[i-1][0])//要能到达下标i-1才行
         {
            dp[i][j]=max(dp[i-1][j], dp[i-1][j-1]+stations[i-1][1]);//加不加
         }else
         {
            dp[i][j]=dp[i-1][j]; //如果到达不了下标i-1, 那只能不加
         }
      }
   }
   for (int j = 0; j <=n ; j++)
   {
      cout << dp[n][j] << " ";
      if (dp[n][j]>=target)
      {
         return j;
      }
   }
   return -1;
}

//贪心更好理解
//remain代表剩余油量， distance代表已经走过的距离，ans代表答案
//(1)只要distance < target, distance还可以再行驶remain距离, 同时将沿途的加油站放入优先队列pq
//(2)再次检查，如果还是distance < target，remain已经被清0，就要从pq中获取最大的加油站加油更新remain（加油后弹出）
//        distance还可以再行驶remain距离，同时将沿途的加油站放入pq    
//直到distance>=target或者pq中无加油站可加油
int minRefuelStops_final(int target, int startFuel, vector<vector<int>>& stations){
   int n = stations.size();
   priority_queue<int> pq;
   int remain = startFuel;
   int idx = 0;//标记沿途加油站下标
   int distance = 0;
   int ans = 0;
   while (distance<target)
   {
      //remain的获取，要么通过初始化，要么是pq中弹出的最大的加油站
      if (remain==0)//从pq中弹出
      {
         if (!pq.empty())
         {
            ans++;
            remain = pq.top();
            pq.pop();
         }else
         {
            return -1;//没油可加了
         }
      }
      distance += remain;
      remain = 0;  //清空remain
      while (idx< n && stations[idx][0]<=distance)//将沿途加油站加入pq
      {
         pq.push(stations[idx][1]);
         idx++;
      }
   }
   return ans;
}

int main(){
   int target = 100, startFuel = 10;
   vector<vector<int>> a = {{10,60},{20,30},{30,30},{60,40}};
   cout << minRefuelStops_final(target,startFuel,a);
   return 0;
}

// int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
//    priority_queue<int> q;
//    int n = stations.size(), idx = 0;
//    int remain = startFuel, loc = 0, ans = 0;
//    while (loc < target) {
//       if (remain == 0) {
//             if (!q.empty() && ++ans >= 0) {
//                remain += q.top();
//                q.pop();
//             } else {
//                return -1;
//             }
//       }
//       loc += remain; remain = 0;
//       while (idx < n && stations[idx][0] <= loc) q.push(stations[idx++][1]);
//    }
//    return ans;
// }