// 7
// 3 1 2 1 8 5 6
// 输出4    1，2，5，6

#include<iostream>
using namespace std;
int n;
const int N = 1e6+10;
int nums[N];
int f[N]; //f[i]表示以i个数字为结尾最长的子序列

int max_v(){
    int res=0;
    for (int i = 1; i <=n; i++)
    {
        f[i]=1;
        for (int j= 1; j < i; j++) 
        {
            if (nums[i]>nums[j])
            {
                f[i]=max(f[i], f[j]+1); 
            }
        }
    }
    for (int i = 1; i <= n; i++) //f[i]是第i个数字为结尾的长度，但是最长子序列不一定是第n个数字为结尾
    {
        res=max(res, f[i]);
    }
    return res;

}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }
    cout << max_v();
    return 0;
}