// 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// 输出：true
#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    if(m==0||n==0) return false;
    int l = 0, r = m-1;
    while (l<r)
    {
        int mid = (l+r+1)>>1;
        if(matrix[mid][0]<=target){
            l=mid;
        }else
        {
            r=mid-1;
        }
    }
    if(matrix[l][0]==target){
        return true;
    }
    int index = l;
    l=0,r=n-1;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(matrix[index][mid]<=target){
            l=mid;
        }else
        {
            r=mid-1;
        }
    }
    return matrix[index][l]==target;   
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