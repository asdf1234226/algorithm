// 4
// 6 2 9 1
//输出12

#include<iostream>
#include<algorithm>
using namespace std;
int n;
const int N = 10010;
int a[N];

//奇数个点选中间
//偶数个点选中间两个点之前的任意数都可以（闭区间）
//统一为n/2
int min_dist(){
    sort(a, a+n);
    int index = a[n/2];
    int ans =0;
    for (int i = 0; i < n; i++)
    {
        ans+= abs(a[i]-index);
    }
    return ans;
}


int main(){
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << min_dist();
    return 0;
}