#include<iostream>
#include<vector>
#include<set>
using namespace std;
//这种实现的复杂度O(n3)，固定结尾，枚举开头
//最长不重复子序列
//1 2 2 3 5  ---> output is 3 {2, 3, 5}
set<int> s;
// bool check(int l, int r, vector<int> a)
// {
//     set<int> s;
//     for(int i =l;i<=r;i++){
//         if (s.count(a[i]))
//         {
//             return false;
//         }
//         else
//         {
//             s.insert(a[i]);
//         }
//     }
//     return true;
// }
int help(vector<int> a)
{
    
    int res = 0;
    for (int i = 0; i < a.size(); i++)
    {     
        for (int j = i; j>=0; j--)
        {
            if (s.count(a[j]))
            {
                break;
            }
            s.insert(a[j]);
            res=max(res,i-j+1);
        }  
        s.clear();
    }
    return res;
}

//TODO enhance

int main()
{
    vector<int> nums = {1,2,2,3,5};
    cout << help(nums) << endl;
}