#include<iostream>
using namespace std;

//例题：https://www.acwing.com/solution/content/3472/


const int N =100010;
int e[N], ne[N];
int head=-1,idx=0;//初始化

void insert_head(int x)
{
    e[idx]=x;//赋值
    ne[idx]=head;//插入的节点指向head
    head=idx;//更新head
    idx++;
}

//第k个插入数的位置后插入x
void insert(int k, int x)
{
    e[idx]=x;
    ne[idx]=ne[k];//指向k后的下一个节点 （1）
    ne[k]=idx;//(2)
    idx++;
}

//删除第k个插入的数
void remove(int k)
{
    ne[k]=ne[ne[k]];
}

int main()
{
    int a;
    cin >> a;
    while(a--)
    {
        string op;
        int k, x;
        cin >> op;
        if (op=="D")
        {
            cin>>k;
            if (!k)
            {
                head=ne[head];//k=0时删除头节点
            }
            remove(k-1);//下标从0开始的，所以是k-1
        }
        else if (op=="H")
        {
            cin >>x;
            insert_head(x);
        }
        else if (op=="I")
        {
            cin >> k >> x;
            insert(k-1,x);//下标从0开始的
        }
    }
    for (int i = head; i !=-1; i=ne[i])
    {
        cout << e[i] << " ";
    }
    return 0;
    
}