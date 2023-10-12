
#include<iostream>
int search(int nums[], int target)
{
    //s1: 寻找旋转点,前半段>=nums[0]，后半段不满足这个>=nums[0]
    int n = sizeof(nums);
    std::cout << "n: " << n << std::endl;
    if (n == 0)
    {
        return -1;
    }
    if (n==1)
    {
        return nums[0] == target?0:-1;
    }
    
    int l = 0, r = n - 1;
    while(l < r)
    {
        int mid = (l + r + 1) >> 1; 
        if (nums[mid] >= nums[0]) //nums[mid] >= nums[0]时移动l
        {
            l = mid;
        }else{
            r = mid -1;
        } 
    }
    std::cout << "reverse point: " << r << std::endl;
    //此时 l = r
    if (target >= nums[0]) 
    {
        l = 0; //target在左半段，重置l
    }else{
        l = l+1; //target右半段，重置r，同时l++,因为右半段的第一个就是l+1
        r = n-1;
    }
    while (l < r)
    {
        int mid = (l+r+1) >> 1;   //有序的（l,r）中找target，前半段满足nums[mid]<=target
        if (nums[mid] <= target)  //target >= nums[mid]时移动l
        {
            l = mid;
        }else
        {
            r = mid -1;
        }   
    }
    return nums[r] == target? r:-1;

}

int main()
{
    int nums[] = {4,5,6,7,0,1,2};
    int target = 0;
    std::cout << search(nums, target) << std::endl;
    return 0;
}
