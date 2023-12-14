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

//有问题
// 5 6 7 4 2 1---->5 7 6 4 2 1不对，要反转后面的变成5 7 1 2 4 6
// 5 3 7 4 2 1---->5 7 3 4 2 1                    5 7 1 2 3 4--->有更合适的
// 应该是5 3 7 4 2 1 --> 5 4 7 3 2 1--->5 4 7 1 2 3
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
       reverse(nums.begin()+i,nums.end());
    }
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }   
}

// 3 1 6 4 2 1---> 3 2 6 4 1 1
// ---->3 2 1 1 4 6
void nextPermutation_final(vector<int>& nums){
    int n = nums.size();
    int index1 = -1;
    for (int i = n-1; i-1 >= 0; i--)
    {
        if (nums[i-1]<nums[i])
        {
            index1 = i-1;
            break;
        }
    }
    cout << index1 << endl;
    if (index1==-1)
    {
        reverse(nums.begin(),nums.end());
        return;
    }
    int index2 = -1;
    for (int i = n-1; i >=index1; i--)
    {
        if(nums[i]>nums[index1]){
            index2 = i;
            break;
        }
    }
    cout << index2 << endl;
    swap(nums[index1], nums[index2]);
    //index1后的（不包含index1）都要反转
    reverse(nums.begin()+index1+1, nums.end());
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }   
}
int main(){
    vector<int> a ={3,1,6,4,2,1};
    nextPermutation_final(a);
    return 0;
}

// 先找出最大的索引 k 满足 nums[k] < nums[k+1]，如果不存在，就翻转整个数组；
// 再找出另一个最大索引 l 满足 nums[l] > nums[k]；
// 交换 nums[l] 和 nums[k]；
// 最后翻转 nums[k+1:]。

// 原理： 因为“【最大的】索引 k 满足 nums[k] < nums[k+1]”，所以k位是需要变得大
// 一点点的地方。 k之后一定是递减的，因为“【最大的】索引 k 满足 nums[k] < 
// nums[k+1]” 又因为“【最大索引】 l 满足 nums[l] > nums[k]”， 所以l一定是k之后
// 所有数里面最小大于k的（最贴近k的）。 所以l和k换位置就可以让这个数组在k的位置上
// 刚好大最小的一点。 然后，因为“【最大的】索引 k 满足 nums[k] < nums[k+1]”，
// 所以l+i<k。因为如果l+i > k，那么k就会变成l+i而不是l。 所以l和k换完位置后，
// 现在l（原来k）所在位置后的所有数，依然递减。 所以只要把现在l（原来k）所在位置后
// 的所有数reverse，就可以得到答案