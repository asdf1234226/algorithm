//
// Created by SP on 2023/11/1.
//

#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int i=0, j=0;
    while (i<n && j<n){
        if (nums[i]!=0){//找到第一个0
            i++;
        }
        //此时nums[i]=0;
        if (nums[j]==0){//找到第一个非0
            j++;
        }
        cout << i << " " << j << endl;
        //此时nums[j]!=0;
        if(i<n && j<n && i<j){
            swap(nums[i],nums[j]);
        }
        i++;
        j++;
    }
}

int main(){
    vector<int> nums={1,0};
    moveZeroes(nums);
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    return 0;
}