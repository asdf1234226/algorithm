// 7
// 3 6 1 4 2 5 7
//输出56

#include<iostream>
#include<algorithm>
using namespace std;
int n;
const int N = 10010;
int a[N];

//(n-1)*t1 + ... + t(n-1)
int min_wait(){
    //sort(a+1, a+1+n);
    sort(a, a+n);
    int ans =0;
    for (int i = 0; i < n-1; i++)
    //for (int i = 1; i < n; i++)
    {
        //ans+=(n-i)*a[i];
        ans+=(n-i-1)*a[i];
    }
    return ans;
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++)
    //for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cout << min_wait();
    return 0;
}