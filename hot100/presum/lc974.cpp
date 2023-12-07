
// 给定一个整数数组 A，返回其中元素之和可被 K 整除的（连续、非空）子数组的数目。

// 输入：A = [4,5,0,-2,-3,1], K = 5
// 输出：7
// 有 7 个子数组满足其元素之和可被 K = 5 整除：
// [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]


#include <iostream>
#include<vector>
#include<map>
using namespace std;

//构造前缀和 (preSum_j - preSum_i)%k==0
//当前遍历是preSum_j===> preSum_i%k = preSum_j%k

int subarraysDivByK(vector<int>& A, int K){
    int n = A.size();
    map<int, int> mp;
    mp[0]=1;
    int count = 0;
    int preSum = 0;
    for (int i = 0; i < n; i++)
    {
        preSum+=A[i];
        int key = (preSum%K+K)%K;//A[i]%K已经是求余数，但是可能是负值，所以就再+K
        if (mp.find(key)!=mp.end())
        {
            count +=mp[key];
        }
        mp[key]++;
    }
    return count;
}

int main(){
    vector<int> a = {4,5,0,-2,-3,1};
    cout << subarraysDivByK(a,5);
    return 0;
}