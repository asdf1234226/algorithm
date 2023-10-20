// 3 3
// 1 2 -1
// 2 3 4
// 3 1 -4
// 输出yes

//n个点m条边有向图，可能重边和自环，边权可能负, 判断负环
//1<=n,m<=1e5
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N =1e5+10;
int dist[N];
int e[N], ne[N], w[N], idx, cnt[N];   //**************cnt[]存储1~i边数********
int h[N];
int n, m;
queue<int> q;
bool inq[N]; //存放是否在队列中

void add(int a, int b, int c){
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}

bool spfa(){
    //memset(dist, 0x3f, sizeof dist);
    //dist[1]=0;
    //q.push(1);
    //inq[1]=true;
    for(int i=1;i<=n;i++){  //**********所有节点加入q, 所以也不用初始化了
        q.push(i);
        inq[i]=true;
    }
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        inq[p]=false; //p不在队列中
        for (int i = h[p]; i !=-1; i=ne[i]) //遍历t能到底的所有点
        {
            int j = e[i]; //边的另一个点
            if(dist[p]+w[i]<dist[j]) //如果j的距离被更新
            {
                dist[j]=dist[p]+w[i];
                cnt[j]=cnt[p]+1;
                if (cnt[j]>=n)   //***********n条边,经过n+1个点，一共n个点，有负环
                {
                    return true;
                }            
                if(!inq[j]){
                    q.push(j);
                    inq[j]=true;
                }
            }
        }  
    }
    return false; 
}

int main(){
    cin >> n >>m;
    memset(h,-1,sizeof h);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >>c;
        add(a,b,c);
    }
    if (spfa()) 
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
    return 0;
}