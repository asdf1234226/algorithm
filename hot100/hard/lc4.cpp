//
// Created by SP on 2023/12/11.
//

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    vector<int> nums;
    int i = 0,j=0;
    while (i<n&&j<m)
    {
        if (nums1[i]<nums2[j])
        {
            nums.push_back(nums1[i]);
            i++;
        }else
        {
            nums.push_back(nums2[j]);
            j++;
        }
    }
    while (i<n)
    {
        nums.push_back(nums1[i]);
        i++;
    }
    while (j<m)
    {
        nums.push_back(nums2[j]);
        j++;
    }
    if ((n+m)%2==0)
    {
        return (nums[(n+m)/2]+nums[(n+m-1)/2])/2.0;
    }else
    {
        return nums[(n+m)/2]/2.0;
    }
}

// int find(int[] n1, int i, int[] n2, int j, int k) {
//     if (n1.length - i > n2.length - j) return find(n2, j, n1, i, k);
//     if (i >= n1.length) return n2[j + k - 1];
//     if (k == 1) {
//         return Math.min(n1[i], n2[j]);
//     } else {
//         int si = Math.min(i + (k / 2), n1.length), sj = j + k - (k / 2);
//         if (n1[si - 1] > n2[sj - 1]) {
//             return find(n1, i, n2, sj, k - (sj - j));
//         } else {
//             return find(n1, si, n2, j, k - (si - i));
//         }
//     }
// }

int help_find(vector<int>& nums1,int i, vector<int>& nums2, int j, int k){
    //默认第一个数组比第二个短，只需要对短的数组越界检查
    if(nums1.size()-i>nums2.size()-j){return help_find(nums2,j,nums1,i,k);}
    if (i>=nums1.size())
    {
        return nums2[j+k-1];
    }
    //不加k == 1的判断，当k减小到1时，下一次递归调用中的k/2将会是0（在整数除法中），
    //这将导致函数无法正确地将问题规模减小，从而无法达到递归的终止条件，形成死循环。
    if (k == 1) {
        return min(nums1[i], nums2[j]);
    } 
    int n1 = nums1.size();
    int index = i+(k/2);
    int si = min(n1,index);
    int sj= j+ k-(k/2);
    if(nums1[si-1]<nums2[sj-1]){
        return help_find(nums1,si,nums2,j,k-(si-i));
    }
    else
    {
        return help_find(nums1,i,nums2,sj,k-(sj-j));
    }
}
//二分
//从两个有序数组中找第 k ⼩的数。
double findMedianSortedArrays_final(vector<int>& nums1, vector<int>& nums2){
    int total = nums1.size()+nums2.size();
    if (total%2==0)
    {
        int left = help_find(nums1,0,nums2,0,total/2);
        int right = help_find(nums1,0,nums2,0,total/2+1);
        return (left+right)/2.0;
    }
    else
    {
        return help_find(nums1,0,nums2,0,total/2+1);
    }
}

int main(){
    vector<int> a = {1,3,5};
    vector<int> b ={2,5,9};
    cout << findMedianSortedArrays_final(a,b);
    return 0;
}



// ⾸先可以将原问题等效为：从两个有序数组中找第 k ⼩的数。
// 分两种情况讨论：
// 1. 总个数为偶数：找到 第 (total / 2) 个⼩的数 和 第 (total / 2 + 1) 个⼩的数 ，结果为两
//         者的平均值。
// 2. 总个数为奇数：结果为 第 (total / 2 + 1) 个⼩的数 。

// 默认第⼀个数组⽐第⼆个数组的有效⻓度短，如果不满⾜，则调换两个数组（这也是⼀个常⽤技
//         巧，⽬的是减少边界处理⼯作：原本需要对两个数组做越界检查，现在只需要对短的数组做越界检
//         查）
// 第⼀个数组的有效⻓度从 i 开始，第⼆个数组的有效⻓度从 j 开始，其中 [i,si - 1] 是第⼀
// 个数组的前 k / 2 个元素， [j,sj - 1] 是第⼆个数组的前 k - k / 2 个元素（为了确保 k 为
//         奇数的时候正确）
// 当 nums1[si - 1] > nums2[sj - 1] ：则表示第 k ⼩⼀定不在 [j,sj - 1] 中，即在
// [i,n] 或 [sj,m] 中
//         当 nums1[si - 1] <= nums2[sj - 1] ：则表示第 k ⼩⼀定不在 [i,si - 1] 中，即在
// [si,n] 或 [j,m] 中


// public double findMedianSortedArrays(int[] nums1, int[] nums2) {
//     int tot = nums1.length + nums2.length;
//     if (tot % 2 == 0) {
//         int left = find(nums1, 0, nums2, 0, tot / 2);
//         int right = find(nums1, 0, nums2, 0, tot / 2 + 1);
//         return (left + right) / 2.0;
//     } else {
//         return find(nums1, 0, nums2, 0, tot / 2 + 1);
//     }
// }
// int find(int[] n1, int i, int[] n2, int j, int k) {
//     if (n1.length - i > n2.length - j) return find(n2, j, n1, i, k);
//     if (i >= n1.length) return n2[j + k - 1];
//     if (k == 1) {
//         return Math.min(n1[i], n2[j]);
//     } else {
//         int si = Math.min(i + (k / 2), n1.length), sj = j + k - (k / 2);
//         if (n1[si - 1] > n2[sj - 1]) {
//             return find(n1, i, n2, sj, k - (sj - j));
//         } else {
//             return find(n1, si, n2, j, k - (si - i));
//         }
//     }
// }