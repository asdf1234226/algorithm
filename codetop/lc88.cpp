// 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
// 说明:
// 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
// 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
// 示例:

// 输入:
// nums1 = [1,2,3,0,0,0], m = 3
// nums2 = [2,5,6],       n = 3
// 输出: [1,2,2,3,5,6]


#include<iostream>
#include<vector>
using namespace std;

//TODO 没掌握
//如果从头开始比较，需要新建一个数组，然后再赋值回来
//从nums1有数值的地方的尾部开始比较，最大的放在nums1的最后面，这样就不会需要O(m+n)的新空间
//即从nums1的3和nums2的6开始比较，将6放在[1,2,3,0,0,6]
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int index1 = m-1, index2 = n-1;
    int index = m+n-1;
    while (index1>=0 && index2>=0)
    {
        if (nums1[index1]>nums2[index2])
        {
            nums1[index--]=nums1[index1--];
        } else
        {
            nums1[index--]=nums2[index2--];
        }
    }
    while (index1>=0)
    {
        nums1[index--]=nums1[index1--];
    }
    while (index2>=0)
    {
        nums1[index--]=nums2[index2--];
    }
    for (int i = 0; i < m+n; i++)
    {
        cout << nums1[i] << " ";
    }
}

int main(){
    vector<int> a = {4,5,6,0,0,0};
    vector<int> b = {1,2,3};
    merge(a,3,b,3);
    return 0;
}