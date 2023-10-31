//1 8 6 2 5 4 8 3 7
//49   选8和7,7*7=49

#include<iostream>
#include<vector>
using namespace std;

//l在左端点，r在右端点，假设height[l]<height[r]
// 此时面积h[l] * (r-l) 
//    移动l, h[l+1]=h[l]，高度不变，长度-1，面积变小           
//           h[l+1]>h[l]，高度变大，长度-1，面积可能变大           
//           h[l+1]<h[l]，高度变小，长度-1，面积变小 
//    移动r，h[r-1]=h[r]，高度不变，长度-1，面积变小             
//           h[r-1]>h[r]，由于h[r]>h[l]，所以储水还是看h[l]，高度不变，长度-1，面积变小
//           h[r-1]<h[r]，储水看h[r-1]和h[l]的较小值，所以高度可能不变/变小，长度-1，面积变小
//------>结论是，只移动较小值，面积可能会变大
int maxArea(vector<int> height){
    int n = height.size();
    int l = 0, r = n-1;
    int ans = 0;
    while (l<r)
    {
        ans=max(ans, (r-l)*min(height[l], height[r]));
        if (height[l]>height[r])
        {
            r--;
        }
        else
        {
            l++;
        }   
    }
    return ans;
}


int main(){
    vector<int> a = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(a);
    return 0;
}