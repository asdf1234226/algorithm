// 示例 1：
// 输入：nums = [1,2,3]
// 输出：[1,3,2]

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//TODO  看看有没有更简单的方法
// 1 5 4 3 2  --> 2 5 4 3 1 ---> 2 1 3 4 5
void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int index = n-2;//
    while (index>=0 && nums[index]>=nums[index+1])
    {
        index--;
    }
    if (index==-1)
    {
        reverse(nums.begin(),nums.end());
        return;
    }
    cout << index << endl;
    
    //从右边找第一个比nums[index]大的 index2
    int index2 = n-1;
    while (index2>=0 && nums[index2]<=nums[index])
    {
        index2--;
    }
    cout << index2 << endl;
    swap(nums[index2], nums[index]);
    reverse(nums.begin()+index+1, nums.end());
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    } 
}

int main(){
    vector<int> a ={3,1,6,4,2,1};
    nextPermutation(a);
    return 0;
}