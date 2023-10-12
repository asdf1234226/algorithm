#include<iostream>
using namespace std;

const int N = 100010;
int p[N];

int find(int x)//x的祖宗节点
{
    if(p[x]!=x){
        p[x]=find(p[x]); //路径压缩
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
    }
    while(m--){
        char op;
        int a, b;
        cin >> op >> a >> b;
        if (op=='M')
        {
            int pa = find(a);
            int pb = find(b);
            if (pa!=pb)
            {
                p[pa]=pb;//a的祖宗节点的父节点是b的祖宗节点
            }
        }else
        {
            cout << "a: " << find(a) << ",b: " <<find(b); 
            string str= find(a) == find(b)?"yes":"no";//是否在一个集合中
            cout << str;
        }
    }
    
}