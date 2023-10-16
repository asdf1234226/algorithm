#include<iostream>
#include<cstring>
using namespace std;
const int N = 100010;
int e[2*N], ne[2*N], idx; //双向边
int h[N];//每个节点的单链表
int n;
bool vis[N];
int ans=0x3f3f3f3f;

void insert(int a, int b){//添加a-->b边
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx;
    idx++;
}

int dfs(int u){//返回以u为节点子树中点的数量
    int sum=1;//包括u
    int max_weight=0;
    vis[u] = true;
    for(int i = h[u]; i!=-1; i=ne[i])//遍历u为起点的链表,不需要进行越界判断
    {
        int j = e[i];
        if (!vis[j])
        {
            int size = dfs(j);
            max_weight=max(max_weight, size);
            sum+=size;
        }
    }
    max_weight=max(max_weight, n-sum);
    ans=min(ans,max_weight);
    return sum;
}

int main(){
    cin >> n;
    while (n--)
    {
        int a,b;
        cin >> a >>b;
        insert(a,b);
        insert(b,a);//无向边
    }
    // n = 9;
    // memset(h,-1,sizeof h);
    // int nums[8][2]={{1,2}, {1,7}, {1,4},{2,8},{2,5},{4,3}, {3,9},{4,6}};
    // for (int i = 0; i < 8; i++)
    // {
    //     insert(nums[i][0], nums[i][1]);
    //     insert(nums[i][1], nums[i][0]);
    // }
    int a = dfs(1);
    cout << ans;

}