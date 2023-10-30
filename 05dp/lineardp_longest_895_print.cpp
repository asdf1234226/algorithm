#include<iostream>
#include<cstring>
using namespace std;
int n;
const int N = 1e6+10;
int nums[N];
int f[N]; // f[i]表示以i个数字为结尾最长的子序列
int pre[N]; // pre[i]保存了以nums[i]结尾的最长递增子序列的前一个元素的索引

int max_v(){
    int res=0;
    int max_index = 0; // 保存最长子序列的最后一个元素的索引
    memset(pre,-1,sizeof pre);
    for (int i = 1; i <=n; i++)
    {
        f[i]=1;
        for (int j= 1; j < i; j++) 
        {
            if (nums[i]>nums[j] && f[j]+1>f[i])
            {
                f[i]=f[j]+1; 
                pre[i] = j; // 保存前一个元素的索引
            }
        }
        if (f[i] > res) {
            res = f[i];
            max_index = i;
        }
    }
    for (int i = max_index; i != -1; i = pre[i]) {//*****逆序输出
        cout << nums[i] << " ";
    }
    cout << endl;
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
