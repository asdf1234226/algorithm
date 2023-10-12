#include<iostream>
#include<vector>
using namespace std;

//lc33的变体  {0,1,2,4,4,4,5,6,6,7}  ----->  {4,5,6,6,7,0,1,2,4,4}
//   _/  ----->_/  _
//  /             /
//现在并不会同时满足前半段>=nums[0]，后半段<nums[0]（当旋转点在重复值时）
//只需要去掉后半段=nums[0]的属性，恢复二段性
int search(vector<int> nums, int target)
{
    if (nums.size() == 0)
    {
        return -1;
    }
    if (nums.size()==1)
    {
        return nums.at(0) == target?0:-1;
    }
    int l=0, r = nums.size()-1;
    //恢复二段性
    while (nums.at(0)==nums.at(r) && r>0)
    {
        r--;
    }
    //寻找旋转点
    while (l<r)
    {
        int mid = (l+r+1)>>1;
        if (nums.at(mid)>=nums.at(0))
        {
            l=mid;
        }
        else{
            r=mid-1;
        }
    }
    //判断target在旋转点左边还是右边(左边满足>=num(0))
    if (target>=nums.at(0))
    {
        l=0;
    }
    else{
        l++;
        r=nums.size()-1;
    }
    //单段非降序（l,r）找target
    while (l<r)
    {
        int mid = (l+r+1)>>1;
        if (nums.at(mid)<= target)
        {
            l=mid;
        }
        else{
            r=mid-1;
        }
        
    }
    return nums.at(l)==target?l:-1;
}

int main()
{
    vector<int> nums = {4,5,6,6,7,0,1,2,4,4};
    cout << search(nums, 0);
    return 0;
}