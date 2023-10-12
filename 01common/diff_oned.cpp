#include<iostream>
#include<vector>
using namespace std;

//给[l,r]的每个数+c，复杂度要求O(1)
const int N = 1e5+10;
int B[N];
int A[N];

void insert(int l, int r, int c)
{
    B[l]+=c;
    B[r+1]-=c;
}

void diff(vector<int>& a, vector<vector<int>>& add)
{
    int n = a.size();
    for(int i =1;i<=n;i++){//初始化B的方式，[i,i] add a[i-1]
        insert(i,i,a[i-1]);
    }
    for (auto it: add)
    {
        int l = it[0], r =it[1], c=it[2];
        insert(l,r,c);
    }
    //计算前缀和
    for (int i = 1; i <= n; i++)
    {
        A[i]=A[i-1]+B[i];
    }
    for (int i = 0; i < n; i++)
    {
        a[i]=A[i+1];
    }
    
}

int main()
{
    vector<int> a = {1,2,3,4,5,6,7,8};
    vector<int> add1= {1,3,2};//{1,3,2}表示[1,3]的每个数+2
    vector<int> add2={1,5,1};
    vector<vector<int>> add;
    add.push_back(add1);
    add.push_back(add2);
    diff(a,add); 
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }

}