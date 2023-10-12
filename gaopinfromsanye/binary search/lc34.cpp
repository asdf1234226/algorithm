#include<iostream>
#include<vector>
using namespace std;

vector<int> search(vector<int>& nums, int target)
{
    vector<int> result = {-1,-1};
    int n = nums.size();
    int l = 0, r =n-1;
    while (l<r)
    {
        int mid = (l+r+1)>>1;
        if (nums.at(mid)<=target) //满足此条件，移动l,就会来到右边界
        {
            l=mid;
        }
        else{
            r=mid-1;
        }  
    }
    if (nums.at(r)==target)
    {
        result.at(1)=r;
    }
    l=0;
    r=n-1;
    while (l<r)
    {
        int mid = (l+r)>>1;
        if (nums.at(mid)>=target) //满足此条件移动r，就会来到右边界
        {
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    if (nums.at(r)==target)
    {
        result.at(0) = r;
    }    
    return result;

}
int main()
{
    vector<int> num = {5,7,7,8,8,10};
    int target = 6;
    cout << "search result1: " << search(num, target).at(0) << endl;
    cout << "search result2: " << search(num, target).at(1) << endl; 
    return 0;
}