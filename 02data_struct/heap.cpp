#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 100010;
int h[N];
//以小堆为例
int size=0;

void down(int u)
{
    //父节点应该是最小的
    int min = u;
    if(u * 2 <= size && h[2*u]<h[u]) min=2u;
    if(u * 2 + 1 <= size &&h[2*u+1]<h[min]) min=2*u+1;
    if (min!=u)
    {
        swap(h[min], h[u]);
        down(min);
    }
}

void up(int u)
{
    //子节点应该>父节点
    int max=u;
    if(u/2 &&h [u/2]>h[u]) max =u/2;
    if (max!=u)
    {
        swap(h[max], h[u]);
        up(max);
    }
}

void init(int n)
{
    //建堆的小技巧，从n/2~1，down每个节点
    for(int i=n/2;i;i--){
        down(i);
    }
}
void insert(int x)
{
    h[++size]=x;
    up(size);
}

//求最小值
int top()
{
    return h[1];
}

//删除最小值
void remove()
{
    h[1]=h[size];
    size--;
    down(1);
}

//删除任意位置元素
void remove(int k){
    h[k]=h[size];
    size--;
    down(k);
    up(k);// up和down只会执行某一个
}

//修改任意位置元素
void update(int k, int x)
{
    h[k]=x;
    up(k);
    down(k);
}

int main(){
    int num[5]={3,6,1,7,4};
    for (int i = 0; i < 5; i++)
    {
        insert(num[i]);
    }
    init(5);
    for (int i = 0; i < 5; i++)
    {
        cout << top() << " ";
        remove();
    }
    return 0;
    
}