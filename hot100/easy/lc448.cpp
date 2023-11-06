//有些出现两次，有些一次，有的没出现，找出没出现的
// 4,3,2,7,8,2,3,1
//输出5,6
//不使用额外空间，复杂度O(n)

#include<iostream>
#include<vector>
using namespace std;

void find(vector<int>& num){
    int n = num.size();
    for(int i=0;i<n;i++){
        int index = num[i]-1;//一定要用index，否则可能重复修改num的某个元素+2n后又-2n
        while (index>=2*n)
        {
            index-=2*n;
        }
        num[index]+=2*n;
        //cout << num[i]-1 << ":" << num[num[i]-1] << " ";
    }
    for (int i = 0; i < n; i++)
    {
        if (num[i]<2*n)
        {
            cout << i+1 << " ";
        }
        
    }
    
}

int main(){
    vector<int> a = {4,3,2,7,8,2,3,1};
    find(a);
    return 0;
}