#include<iostream>
#include<vector>
#include<set>
using namespace std;
//这种实现的复杂度O(n1)，固定结尾，枚举开头,结尾i往右走时，j不可能往左走，具有单调性
//最长不重复子序列
//1 2 2 3 5  ---> output is 3 {2, 3, 5}

set<int> s;
int help(vector<int> a)
{
    int res = 0;
    int j =0;
    for (int i = 0; i < a.size(); i++)
    {     
        while (s.count(a[i])&&j<a.size())
        {
            s.erase(a[j]);
            j++;   
        }
        s.insert(a[i]);//加入set
        res=max(res,i-j+1);
        
    }
    return res;
}

int main()
{
    vector<int> nums = {1,2,2,3,5};
    cout << help(nums) << endl;
}