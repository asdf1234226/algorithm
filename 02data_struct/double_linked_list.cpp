#include<iostream>
using namespace std;
const int N = 10010;
int e[N], l[N], r[N], idx;

void init()
{
    //初始化，下标0代表左端点，下标1代表右端点
    r[0]=1;
    l[1]=0;
    idx=2;
}

//下标为k的右边插入x
void insert(int k, int x)
{
    e[idx]=x;
    r[idx]=r[k];//右右左左，先新后旧
    l[idx]=k;
    l[r[k]]=idx;
    r[k]=idx;
    idx++;
}

void remove(int k)
{
    r[l[k]]=r[k];//左边指向右边
    l[r[k]]=l[k];//右边指向左边
}

int main()
{
    init(); 
    int m;
    cin >> m;
    int k, x;
    while(m--)
    {
        string op;
        cin>>op;
        if (op=="L")
        {
            cin>>x;
            insert(0,x);
        }
        else if (op=="R")
        {
            cin>>x;
            insert(l[1],x);
        }
        else if (op=="D")
        {
            cin>>k;
            remove(k+1); //k+1是插入的第k个数（0，1被占用）
        }
        else if (op=="IL")
        {
            cin>>k>>x;
            insert(l[k+1],x);
        }
        else if (op=="IR")
        {
            cin>>k>>x;
            insert(k+1,x);
        }
    }
    for (int i = r[0]; i !=1; i=r[i])
    {
        cout << e[i] << " ";
    }
    return 0;
}