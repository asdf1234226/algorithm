// 3
// 10 3
// 2 5
// 3 3
// 输出2

#include<iostream>
#include<algorithm>
using namespace std;
int n;
const int N = 10010;
struct Cow
{
    int w;
    int s;
    bool operator<(const Cow &c) const{
        return w+s<c.w+c.s;
    };
} cows[N];



int help(){
    sort(cows, cows+n);
    int ans = -1e9, sum = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, sum-cows[i].s);//更新最大风险系数
        sum +=cows[i].w;//为下一只牛更新重量；
    }
    return ans;
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin>>cows[i].w>>cows[i].s;
    }
    cout << help();
    return 0;
}