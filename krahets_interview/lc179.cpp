//
// Created by SP on 2023/12/14.
//

// 给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。
// 注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。

// 示例 1：
// 输入：nums = [10,2]
// 输出："210"
// 示例 2：
// 输入：nums = [3,30,34,5,9]
// 输出："9534330"

#include<iostream>
#include<vector>
using namespace std;
//比较规则，类似运算符重载，判断x,y的大小，如果"x"+"y">"y"+"x"，则"x">"y"
void quickSort(vector<string>& strs, int l ,int r){
    if (l>=r)
    {
        return;
    }
    int i = l, j= r;
    int mid = (l+r)>>1;
    while (i<j)
    {
        while (i<j && strs[i]+strs[mid]<=strs[mid]+strs[i])
        {
            i++;
        }
        while (i<j && strs[j]+strs[mid]>=strs[mid]+strs[j])
        {
            j--;
        }

        if(i<j){
            swap(strs[i], strs[j]);
        }
    }
    //j前面的元素<=pivot;j后面的元素>=pivot
    quickSort(strs,l,j);
    quickSort(strs,j+1,r);
}
//TODO FIX
string largestNumber(vector<int>& nums) {
    int n = nums.size();
    vector<string> strs;
    for(auto it: nums){
        strs.push_back(to_string(it));
    }
    quickSort(strs,0,n-1);
    string ans = "";
    for(int i = strs.size()-1;i>=0;i--){
        ans+=strs[i];
    }
    return ans;
}

int main(){
    vector<int> a = {8308,8308,830};
    cout << largestNumber(a);
    return 0;
}