// 给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
// 输入：nums = [4,1,2,1,2]


int singleNumber(vector<int>& nums) {
    int res = 0;
    for(auto num: nums){
        res^=num;
    }
    return res;
}