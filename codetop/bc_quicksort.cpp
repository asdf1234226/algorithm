#include<iostream>
#include<vector>
using namespace std;

void quick_sort(vector<int>& nums, int l, int r){
    if (l>=r)
    {
        return;
    }
    int base = nums[(l+r)>>1];
    int i = l, j = r;
    while (i<j)
    {
        while (i<j && nums[i]<base)
        {
            i++;
        }
        while (i<j && nums[j]>base)
        {
            j--;
        }
        if (i<j)
        {
            swap(nums[i], nums[j]);
        }
    }
    quick_sort(nums,l,j);
    quick_sort(nums,j+1,r);
}

int main(){
    vector<int> a = {1,0};
    quick_sort(a,0,a.size()-1);
    //quickSort(0,a.size()-1,a);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}