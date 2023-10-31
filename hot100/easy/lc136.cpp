#include<iostream>
#include<vector>
using namespace std;

int getNum(vector<int> num){
    int ans = num[0];
    int n = num.size();
    for (int i=1;i<n;i++)
    {
        ans^=num[i]; 
    }
    return ans;
    
}


int main(){
    vector<int> a ={4,1,2,1,2};
    cout << getNum(a);
    return 0;
}