// 输入: nums = [1,2,3,4,5,6,7], k = 3
// 输出: [5,6,7,1,2,3,4]
// 解释:
// 向右轮转 1 步: [7,1,2,3,4,5,6]
// 向右轮转 2 步: [6,7,1,2,3,4,5]
// 向右轮转 3 步: [5,6,7,1,2,3,4]

#include<iostream>
#include<vector>
using namespace std;

void reverse(vector<int>& nums, int l , int r){
    while (l<r)
    {
        swap(nums[l], nums[r]);
        l++;
        r--;
    }
}
//通过整体反转把后面k个反转到前面
//然后分别反转这两段
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k=k%n;
    reverse(nums, 0, n-1);
    reverse(nums,0,k-1);//k个
    reverse(nums,k,n-1);
    for(int i=0;i<n;i++){
        cout << nums[i] << " ";
    }
}
int main(){
    vector<int> a ={1,2,3,4,5,6,7};
    rotate(a,2);
    return 0;
}