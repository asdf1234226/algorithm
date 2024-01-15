
#include<iostream>
#include<vector>
using namespace std;


// 输入: nums = [1,2,3,4]
// 输出: [24,12,8,6]
vector<int> productExceptSelf(vector<int>& nums) {
    //前缀积和后缀积
    int n = nums.size();
    vector<int> preMulti(n+1,1);
    for(int i=1;i<=n;i++){//第i个数下标i-1
        preMulti[i]=preMulti[i-1]*nums[i-1];
    }
    vector<int> postMulti(n+1,1);
    for(int i=1;i<=n;i++){
        postMulti[i]=postMulti[i-1]*nums[n-i];
    }
    vector<int> res;
    for(int i=1;i<=n;i++){
        // i左边i-1个数，右边n-i个数
        res.push_back(preMulti[i-1]*postMulti[n-i]);
    }
    return res;
}

int main(){
    vector<int> a = {1,2,3,4};
    vector<int> b = productExceptSelf(a);
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}