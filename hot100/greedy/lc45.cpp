//
// Created by SP on 2023/11/12.
//

// 返回到达 nums[n - 1] 的最小跳跃次数。
// 输入: nums = [2,3,1,1,4]
// 输出: 2
// 解释: 跳到最后一个位置的最小跳跃数是 2。
// 从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。

#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

int jump(vector<int>& nums) {
    int n = nums.size();
    //每次跳，选和下一跳加一起最远的， 比如当前nums[0]=2可以选nums[1]和nums[2]，
    //选nums[1]能到达的最远距离是1+3=4,选nums[2]能到达的最远距离是2+1=3,所以选nums[1]
    int i = 0;
    int step = 0;
    while (i<n)
    {
        int next = -1;//下一跳的下标
        int maxDis = 0;//当前所能到的最远距离
        for(int j = 1; j <= nums[i] && j+i < n; j++){
            if (maxDis<i+j+nums[i+j])
            {
                maxDis = i+j+nums[i+j];
                next = i+j;
            }
        }
        step++;
        if(-1==next){//如果next没更新，说明下一跳最远是原地踏步
            return -1;
        }
        if (next >= n-1){
            return step;
        }
        i = next;
    }
    return step;
}

int jump_bfs(vector<int>& nums) {
    int n = nums.size();
    queue<int> q;
    map<int,int> mp;
    vector<bool> visited(n, false);
    q.push(0);
    mp[0]=0;
    while (!q.empty())
    {
        int index = q.front();
        q.pop();
        int step = mp[index];
        if (index==n-1)
        {
            return step;
        }
        for (int i = 1; i <= nums[index]; i++)
        {
            int next = index+i;
            if (next < n && !visited[next])
            {
                q.push(next);
                mp[next]=step+1;
                visited[next] = true;
            }
        } 
    }
    return -1;
}

int main(){
    vector<int> a = {3,2,1};
    cout << jump_bfs(a);
    return 0;
}

//     public int jump(int[] nums) {
//         int n = nums.length;
//         int ans = 0;
//         boolean[] st = new boolean[n];
//         Deque<Integer> d = new ArrayDeque<>();
//         st[0] = true;
//         d.addLast(0);
//         while (!d.isEmpty()) {
//             int size = d.size();
//             while (size-- > 0) {
//                 int idx = d.pollFirst();
//                 if (idx == n - 1) return ans;
//                 for (int i = idx + 1; i <= idx + nums[idx] && i < n; i++) {
//                     if (!st[i]) {
//                         st[i] = true;
//                         d.addLast(i);
//                     }
//                 }
//             }
//             ans++;
//         }
//         return ans;
//     }

// https://leetcode.cn/problems/jump-game-ii/solutions/775090/gong-shui-san-xie-xiu-gai-shu-ju-fan-wei-wylq/

class Solution {
public int jump(int[] nums) {
        int n = nums.length;
        int[] f = new int[n];
        for (int i = 1, j = 0; i < n; i++) {
            while (j + nums[j] < i) j++;
            f[i] = f[j] + 1;
        }
        return f[n - 1];
    }
}