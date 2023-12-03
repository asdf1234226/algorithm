#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//摩尔投票法，占多数的数字可以抵消其他候选人
//初始化候选人第一个元素
//如果遍历元素和候选人相同则计数+1
//不同计数-1，如果计数为0则更换候选人
int getMost(vector<int>& nums){
    int n = nums.size();
    int target = nums[0];
    int count = 1;
    for (int i = 1; i < n; ++i) {
        if (target==nums[i]){
            count++;
        } else{
            count--;
            if (count==0){//更换候选人
                target=nums[i];
                count=1;
            }
        }
    }
    return target;
}


int main(){
    vector<int> a = {2,2,4,5,2};
    cout << getMost(a);
    return 0;
}