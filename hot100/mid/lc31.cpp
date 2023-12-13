// 例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。
// 类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。
// 而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1] 不存在一个字典序更大的排列。
// 给你一个整数数组 nums ，找出 nums 的下一个排列

// 输入：nums = [1,1,5]
// 输出：[1,5,1]

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<stack>
using namespace std;


// 1 2 3 5 4 6
// 1 2 3 5 6 4
//存在问题，下面测试用例有问题
// 5 6 7 4 2 1
void nextPermutation_err(vector<int>& nums) {
    int n = nums.size();
    //从右向左找出第一个比nums[n-1]小的数，交换
    //如果找不到呢，反转就行了
    if(n==2)
    {
        swap(nums[0], nums[1]);
        return;
    }
    int index=-1;
    for (int i = n-2; i >= 0; i--)
    {
        if (nums[i]<nums[n-1])
        {
            index=i;
            break;
        }
    }
    if (index!=-1)
    {
        swap(nums[index], nums[n-1]);
    }else
    {
        reverse(nums.begin(),nums.end());
    }
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
}


void nextPermutation(vector<int>& nums){
    int n = nums.size();
    //从右边向左找第一个逆序对，交换就行了
    //x左边第一个比x小的元素y，交换，只需要交换一对{x,y}
    stack<int> st;
    int l[n];
    memset(l,-1,sizeof l);
    for(int i =n-1;i>=0;i--){//左边
        while (!st.empty()&&nums[i]<nums[st.top()])//比x小
        {
            l[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    int index = -1;
    for (int i = n-1; i >= 0; i--)
    {
        if (l[i]!=-1)
        {
            swap(nums[l[i]], nums[i]);
            index = i;
            break;
        }
        
    }
    if (index==-1)//没有逆序对
    {
        reverse(nums.begin(), nums.end());
    }
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }   
}


void nextPermutation_opt(vector<int>& nums){
    int n = nums.size();
    //从右边向左找第一个逆序对，交换就行了
    int i = n-1;
    while (i-1>=0 && nums[i]<=nums[i-1])
    {
        i--;
    }
    // 5 4 3 2 1
    if (i==0)//没有逆序对，反转数组
    {
        reverse(nums.begin(), nums.end());
    }else
    {
       swap(nums[i], nums[i-1]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }   
}
int main(){
    vector<int> a ={5,6,7,4,2,1};
    nextPermutation_opt(a);
    return 0;
}