// 给定一个非负整数，你至多可以交换一次数字中的任意两位。返回你能得到的最大值。

// 示例 1 :
// 输入: 2736
// 输出: 7236
// 解释: 交换数字2和数字7。

// 示例 2 :
// 输入: 9973
// 输出: 9973
// 解释: 不需要交换

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//本质是，从左找到一个小的值，和右边的一个大的值置换
//如果找到这个小的值，如果这个位上的数字是从n-1到这个位遍历（从右往左）最大的，那么不需要置换；
//                  反之，如果这个位上的数字不是最大的，那么就要和右边最大的置换
//所以要有个数组idx存储从右往左数的最大值下标
int maximumSwap_1(int num) {
    vector<int> digits;
    while (num != 0)
    {
        digits.push_back(num%10);
        num /= 10;
    }
    int ans = 0;
    reverse(digits.begin(), digits.end());
    int n = digits.size();
    int maxIdx = n-1;
    vector<int> idx(n);
    for(int i=n-1;i>=0;i--){
        if (digits[i]>digits[maxIdx])
        {
            maxIdx = i;
        }
        idx[i] = maxIdx;
    }
    for (int i = 0; i < n; i++)
    {
        if (digits[i]!=digits[idx[i]])
        {
            swap(digits[i], digits[idx[i]]);
            break;
        }
    }
    
    for(auto it : digits){
        ans=ans*10+it;
    }
    return ans;
}

// 12345
// 54321
// 34125
// 43215
// 52314
int main(){
    cout << maximumSwap_1(2736);
    return 0;
}

