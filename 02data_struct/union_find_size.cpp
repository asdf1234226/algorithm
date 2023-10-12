#include<iostream>
using namespace std;

const int N = 100010;
int p[N], size[N]; //维护size，只有祖宗节点的size有意义

int find(int x)
{
    if(p[x]!=x){
        p[x]=find(p[x]);
    }
    return p[x];
}
// 5 3
// M 1 4
// M 1 5
// F 2 3

int main()
{
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        p[i]=i;
        size[i]=1;//初始化

    }
    while(m--){
        char op;
        int a, b;
        cin >> op >> a >> b;
        if (op=='M')
        {
            // cout <<"before "<< find(a) << ":" <<find(b) << "size " << size[find(a)] << ":" <<size[find(b)]<< endl;
            // size[find(b)]+=size[find(a)];//先合并数量，再把a的祖宗节点连到b的祖宗节点上
            // p[find(a)]=find(b);
            // cout <<"after " << find(a) << ":" <<find(b) << "size " << size[find(a)] << ":" <<size[find(b)]<<endl;

            int pa = find(a);
            int pb = find(b);
            if (pa!=pb)
            {
                size[pb]+=size[pa];
                p[pa]=pb;//先合并数量，再把a的祖宗节点连到b的祖宗节点上
                //如果不用pa和pb分别记录合并前find，数量合并时再次调用find，会有问题
            }
        }else
        {
            cout << "a.size: " << size[find(a)] << ",b.size: " <<size[find(b)]; 
            string str= find(a) == find(b)?"yes":"no";
            cout << str;
        }
    }
    
}