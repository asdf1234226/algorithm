int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int cnt = 1;
    int val = INT_MIN;//初始化一个不会出现的
    int j = 0;
    for(int i=0;i<n;i++){
        if(nums[i]==val){//如果重复则看数量
            cnt++;
            if(cnt<=2){//最多两个
                nums[j++]=val;
            }else{
                continue;
            }
        }else{//不重复，就加入新的值，更新val,并且cnt重计数为1
            val=nums[i];
            cnt=1;
            nums[j++]=val;
        }
    }
    return j;
}