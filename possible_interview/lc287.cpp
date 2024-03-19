    //[1,n]的数，都放在0,1,...n-1的位置上，n位置上的数是多余的
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        for(int i=0;i<=n;i++){
            while(nums[i]!=i+1){//要用while
                if(nums[i]==nums[nums[i]-1]){//提前return
                    return nums[i];
                }else{
                    swap(nums[i], nums[nums[i]-1]);
                }
            }
        }
        return nums[n];
    }