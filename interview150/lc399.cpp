// 给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，其中 equations[i] = [Ai, Bi] 和 values[i] 共同表示等式 Ai / Bi = values[i] 。每个 Ai 或 Bi 是一个表示单个变量的字符串。
// 另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j 个问题，请你根据已知条件找出 Cj / Dj = ? 的结果作为答案。
// 返回 所有问题的答案 。如果存在某个无法确定的答案，则用 -1.0 替代这个答案。如果问题中出现了给定的已知条件中没有出现的字符串，也需要用 -1.0 替代这个答案。
// 注意：输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，且不存在任何矛盾的结果。
// 注意：未在等式列表中出现的变量是未定义的，因此无法确定它们的答案。

// 示例 1：
// 输入：equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
// 输出：[6.00000,0.50000,-1.00000,1.00000,-1.00000]
// 解释：
// 条件：a / b = 2.0, b / c = 3.0
// 问题：a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
// 结果：[6.0, 0.5, -1.0, 1.0, -1.0 ]
// 注意：x 是未定义的 => -1.0
// 示例 2：
// 输入：equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
// 输出：[3.75000,0.40000,5.00000,0.20000]
// 示例 3：
// 输入：equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
// 输出：[0.50000,2.00000,-1.00000,-1.00000]
//Ai, Bi, Cj, Dj 由小写英文字母与数字组成
//1 <= Ai.length, Bi.length <= 5

#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<map>
using namespace std;
const int N = 100;
int idx;
int e[N], ne[N], h[N];
double w[N];

void add(int a, int b, double v){
    e[idx]=b;
    ne[idx]=h[a];
    w[idx]=v;
    h[a]=idx++;
}
vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    memset(h,-1,sizeof h);
    //对出现的Ai, Bi, Cj编号
    map<string, int> mp;
    int cnt = 0;
    for(auto it: equations){
        if(mp.find(it[0])==mp.end()){
            mp[it[0]]=cnt++;
        }
        if(mp.find(it[1])==mp.end()){
            mp[it[1]]=cnt++;
        }
    }
    //建图存边
    for(int i=0;i<equations.size();i++){
        add(mp[equations[i][0]], mp[equations[i][1]], values[i]);
        add(mp[equations[i][1]], mp[equations[i][0]], 1.0/values[i]);
    }
    vector<double> ans;
    //bfs求值
    for (auto query: queries)
    {
        if(mp.find(query[0])==mp.end() || mp.find(query[1])==mp.end()){
            ans.push_back(-1.0);
            continue;
        }
        int x = mp[query[0]], y = mp[query[1]];
        if(x==y){
            ans.push_back(1.0);
            continue;
        }
        //对于每个query，查从x到y的距离， bfs
        vector<double> d(cnt, -1.0);
        queue<int> q;
        q.push(x);
        d[x]=1.0;
        while (!q.empty())
        {
            int c = q.front();
            q.pop();
            for(int j = h[c]; j!=-1; j=ne[j]){//遍历c开头的边
                int b = e[j];//下一个节点
                if(d[b]==-1.0)//没访问过
                {
                    d[b]=d[c]*w[j];
                }
                if(b==y){
                    break;
                }
            }
        }
        ans.push_back(d[y]);
    }
    return ans;
}

int main(){
    return 0;
}