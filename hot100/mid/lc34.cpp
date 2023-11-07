//
// Created by SP on 2023/11/6.
//

//一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
//如果数组中不存在目标值 target，返回 [-1, -1]

//输入：nums = [5,7,7,8,8,10], target = 8
//输出：[3,4]


#include<iostream>
#include<vector>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target) {
	int n = nums.size();
	int l=0,r=n-1;
	while(l<r){
		int mid =(l+r+1)>>1;
		if(nums[mid]<=target){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	if(nums[l]!=target){
		return vector<int>{-1,-1};
	}
	int index_r=l;
	l=0,r=n-1;
	while(l<r){
		int mid =(l+r)>>1;
		if(nums[mid]>=target){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	int index_l=l;
	return vector<int>{index_l,index_r};
}

int main(){
    vector<int> a ={5,7,7,8,8,10};
    vector<int> ans = searchRange(a,9);
    cout << ans[0] << ":" << ans[1];
    return 0;
}