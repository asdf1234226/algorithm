// 示例 1：
// 输入：nums = [1,2,3]
// 输出：[1,3,2]

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 3 6 3 5 4---> 3 6 4 3 5
void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    //1.从右到左找nums[index1]<nums[index2]，找不到就反转
    //2. 从右（n-1）边到左(index2)找一个大于index1的index3，交换index1和index3，反转index2后面的
    int index1 = -1;
    for (int i = n-2; i >= 0; i--)
    {
        if (nums[i]>=nums[i+1])
        {
            continue;
        }else
        {
            index1 = i;
        }
    }
    if (index1==-1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }
    int index2=index1+1;
    int index3=index1;
    for (int i = n-1; i >= 0; i--)
    {
        if (nums[i]>nums[index1])
        {
            index3=i;
            break;
        }
    }
    swap(nums[index1], nums[index3]);
    reverse(nums.begin()+index2, nums.end());
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    } 
}

//TODO  123 --> 132
int main(){
    vector<int> a ={3,1,6,4,2,1};
    nextPermutation(a);
    return 0;
}