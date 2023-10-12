#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 无限长数组，每个坐标上数据初始为0
// 首先进行n次操作，每次操作将位置x的数加c
// 接下来m次询问，包含l和r，求出[l,r]之间的所有数之和
//1<=n,m<=10^5
//-10^9<x<10^9
typedef pair<int, int> PII;
vector<PII> add; //存add操作的(x,c)
vector<PII> query;
vector<int> all;//所有访问的位置(add的下标，查询的下标)
const int N = 3e5+10;
int presum[N];
int a[N];

//二分求出x对应的离散化值（x在排序数组的下标位置）
int find(int x)
{
    int l = 0;
    int r = all.size()-1;
    while(l<r)
    {
        int mid = (l+r+1)>>1;
        if(all[mid]<=x){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    return l;
}

int main()
{
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x,c;
        cin >> x >> c;
        add.push_back({x,c});
        all.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int l,r;
        cin >> l >> r;
        query.push_back({l,r});
        all.push_back(l);
        all.push_back(r);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(),all.end()), all.end()); //unique会将相邻的重复元素移动到容器尾部
    //erase将所有移动的重复元素删除
    
    for (auto it : add)
    {
        int index = find(it.first);
        a[index]+=it.second;
    }
    for (int i = 1; i <= all.size(); i++)
    {
        presum[i]=presum[i-1]+a[i-1];//a[i-1]是第i个数
    }
    for (auto it: query)
    {
        int l = find(it.first);
        int r = find(it.second);
        cout << presum[r+1]-presum[l] << " "; //下标为l和r分别对应第l+1和r+1个数
    }
    return 0;
    
}

