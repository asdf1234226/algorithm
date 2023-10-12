#include<iostream>
#include<vector>
using namespace std;
//数组中心索引的「左侧所有元素相加的和」等于「右侧所有元素相加的和」
//不存在中心索引，返回-1；
//存在多个返回靠左的

int pivotIndex(vector<int> nums)
{
    int n = nums.size();
    vector<int> prefix(n+1, 0);  // prefix.at(i) means 前i个数的和

    for (int i = 1; i <= n; i++)  //1到n
    {
        prefix.at(i) = prefix.at(i-1) + nums.at(i-1); 
    }
    for (size_t i = 1; i < n; i++)
    {
        int left = prefix.at(i-1);
        int right = prefix.at(n) - prefix.at(i);
        if (left == right)
        {
            return i-1;  //i是第几个数，转下标要-1
        }
        
    }
    return -1;
}

//不适用额外数组空间
int pivotIndex_1(vector<int> nums)
{
    int n = nums.size();
    int total = 0;
    for (int i = 0; i < n; i++)  //1到n
    {
        total += nums.at(i);
    }
    int leftsum = 0;
    for (int i = 0; i < n; i++)
    {
        if (leftsum == total - nums.at(i) -leftsum) //leftsum是前i-1数之和，右边的和是total -nums.at(i) - leftsum
        {
            return i;
        }
        leftsum += nums.at(i); 
    }
    return -1;
}

int main()
{
    //1, 7, 3, 6, 5, 6
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    cout << pivotIndex_1(nums) << endl;
    return 0;
}