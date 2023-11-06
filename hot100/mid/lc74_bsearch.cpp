//
// Created by SP on 2023/11/5.
//

//m*n矩阵， 每行中的整数从左到右按非严格递增顺序排列， 每行的第一个整数大于前一行的最后一个整数。
//matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
//输出true

#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    //第一次二分找target应该插入的位置
    int l = 0, r = m-1;
    while (l<r)
    {//前面<= target，后面>target
        int mid = (l+r+1)>>1;
        if (matrix[mid][0]<=target)
        {
            l=mid;
        }else
        {
            r=mid-1;
        }
    }
    //不需要这些
//    if (matrix[l][0]==target)
//    {
//        return true;
//    }else if (matrix[l][0]<target)
//    {
//        //do nothing
//    }else {//target>matrix[l][0]，就要找上一行
//        if (l>0)
//        {
//            l--;
//            cout << "a";
//        }
//        else
//        {
//            return false;
//        }
//    }
    
    //第二次查找在l行查找
    int l1=0, r1=n-1;
    while (l1<r1)
    {
        int mid1 = (l1+r1+1)>>1;
        if (matrix[l][mid1]<=target)
        {
            l1=mid1;
        }else
        {
            r1=mid1-1;
        }  
    }
    return matrix[l][l1]==target;

}

int main(){
    vector<vector<int>> a = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    if(searchMatrix(a,3))
    {
        cout << "y";
    }else
    {
        cout << "n";
    }
    
    return 0;
}