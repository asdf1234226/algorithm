#include<iostream>
#include<vector>
using namespace std;

//给定数组{1,2,3,4,5,6}，求第l和第r个数之间的和
const int N = 1e5+10;
int a[N], s[N];
typedef pair<int, int> PII;
int help(int q[], int n, int l, int r)
{
    for (int i = 1; i <= n; i++)
    {
        s[i]=s[i-1]+q[i-1]; //s[i]表示前i个数，q[i]表示第i+1个数，所以要-1
    }
    return s[r]-s[l-1];
}

vector<int> help1(int q[], int n, vector<PII> range)
{
    //需要计算多次l和r时，只需要计算一次s
    for (int i = 1; i <= n; i++)
    {
        s[i]=s[i-1]+q[i-1]; //s[i]表示前i个数
    }
    vector<int> res;
    for (auto it: range)
    {
        res.push_back(s[it.second]-s[it.first-1]);
    }
    return res;
}

int main()
{
    int q[] = {1,2,3,4,5,6};
    int n = sizeof(q)/sizeof(q[0]);
    //cout << help(q,n,2,5);
    vector<PII> range;
    range.push_back(PII(1,3));
    range.push_back(PII(2,4));
    vector<int> res = help1(q,n,range);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
    
    return 0;
}