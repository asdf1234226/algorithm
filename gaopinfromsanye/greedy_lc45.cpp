//跳跃游戏
//[2,3,1,1,4],输出2，跳到最后一个位置的最小跳跃次数是2

#include<iostream>
#include<vector>
using namespace std;

int jump(vector<int> nums){
    int n = nums.size();
    int i=0;
    int ans=0;
    int nexti=0;
    while (i<n)
    {
        int maxlen =0;
        for (int j = 1; j <= nums[i]; j++)
        {
            if (i+j < n && nums[i+j]+j>maxlen)
            {
                maxlen=nums[i+j]+j;
                nexti=i+j;
            }     
        }
        if (nexti==i)
        {
            return -1;
        }
        i=nexti;
        ans++;
//        if (nexti>=n-1)
//        {
//            break;
//        }
    }   
    return ans;
}

int main(){
    vector<int> a = {2,3,1,1,4};
    cout << jump(a);
    return 0;
}
