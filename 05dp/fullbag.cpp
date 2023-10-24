#include<iostream>
using namespace std;
int n, m;//个数，容量
const int N = 1010;
int v[N];
int w[N];
int f[N];

int max_value(){
    for (int i = 1; i <= n; i++)
    {
        for (int j = v[i]; j <= m; j++)
        {
                f[j]=max(f[j], f[j-v[i]]+w[i]);
            } 
        }
    return f[m];
}




int main(){
    cin >> n >>m;
    for (int i = 1; i <= n; i++)
    {
        int a,b;
        cin >> a>>b;
        v[i]=a;
        w[i]=b;
    }
    cout << max_value();
    return 0;
}