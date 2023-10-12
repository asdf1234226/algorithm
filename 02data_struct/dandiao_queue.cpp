#include<iostream>
using namespace std;
const int N =1e5+10;
int q[N], a[N];//q[N]存储的是下标，通过比较下标判断元素是否在窗口内
int hh=0,tt=-1; //tt-head+1=0


int main()
{
    int n,k;
    cin>>n>>k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; 
    }
    
    for (int i = 0; i < n; i++)
    {
        while(tt-hh+1>0 && i-k+1 >q[hh]) hh++; //i-k+1表示当前窗口的第一个元素下标，如果>队列头部下标q[hh]，该元素不在窗口需要删除
        while (tt-hh+1>0 && a[q[tt]]>=a[i])
        {
            tt--;//删除逆序对 "\"
        }
        q[++tt]=i;//入队
        if (i-k+1>=0) //窗口形成后打印
        {
            cout << a[q[hh]] << " ";
        }
    }
    cout << "--------------"<<endl;
    hh=0,tt=-1;
    for (int i = 0; i < n; i++)
    {
        while(tt-hh+1>0 && i-k+1 >q[hh]) hh++; 
        while (tt-hh+1>0 && a[q[tt]]<=a[i])
        {
            tt--;
        }
        q[++tt]=i;
        if (i-k+1>=0)
        {
            cout << a[q[hh]] << " ";
        }
    }
    return 0;
}

