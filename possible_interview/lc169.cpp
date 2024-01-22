// 输入：nums = [2,2,1,1,1,2,2]
// 输出：2

#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int n = nums.size();
    int major = nums[0];
    int count = 1;
    for(int i=1;i<n;i++){
        if(major==nums[i]){
            count++;
        }else
        {
            count--;
            if (count==0)
            {
                major=nums[i];
                count=1;
            }
        }
    }
    return major;
}

int main(){
    vector<int> a = {2,2,1,1,1,2,2};
    cout << majorityElement(a);
    return 0;
}