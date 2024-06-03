// 给定一个包含非负整数的数组，你的任务是统计其中可以组成三角形三条边的三元组个数。

// 示例 1:
// 输入: [2,2,3,4]
// 输出: 3
// 解释:
// 有效的组合是:
// 2,3,4 (使用第一个 2)
// 2,3,4 (使用第二个 2)
// 2,2,3
// 注意:
// 数组长度不超过1000。
// 数组里整数的范围为 [0, 1000]。

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//需要保证有序a<b<c
bool isTriangle(int a, int b, int c){
    return a+b>c;
}

//直接遍历 O(n3)
int triangleNumber(vector<int>& nums){
    int n = nums.size();
    int ans = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i+2 < n; i++)
    {
        int l = i+1;
        int r = n-1;
        while (l<r && isTriangle(nums[i], nums[l], nums[r]))
        {
            ans++;
        }
        
    }
    
}

int main(){
    vector<int> a = {2,2,3,4};
    cout << triangleNumber(a);
    return 0;
}