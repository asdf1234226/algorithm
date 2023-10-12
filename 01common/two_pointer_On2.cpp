#include<iostream>
#include<vector>
#include<set>
using namespace std;
//这种实现的复杂度O(n2)，固定开头，枚举结尾
//最长不重复子序列
//1 2 2 3 5  ---> output is 3 {2, 3, 5}

set<int> s;
int help(vector<int> a)
{
    int res = 0;
    for (int i = 0; i < a.size(); i++)
    {     
        for (int j = i; j<a.size(); j++)
        {
            if (s.count(a[j]))
            {
                break;//有重复的，跳出循环
            }
            s.insert(a[j]);//加入set
            res=max(res,j-i+1);
        }
        s.clear();  //为下一轮循环使用
    }
    return res;
}

int main()
{
    vector<int> nums = {1,2,2,3,5};
    cout << help(nums) << endl;
}