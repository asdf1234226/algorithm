//
// Created by SP on 2023/11/4.
//
#include<iostream>
#include <cstring>
#include<vector>
using namespace std;

int lowbit(int x){//获取x二进制表示的最后一位1
    return x & -x;
}
int getNumbit(int x){
    int res=0;
    while(x){
        x-= lowbit(x);
        res++;
    }
    return res;
}
vector<int> countBits(int n) {
    vector<int> ans;
    for (int i = 0; i <=n ; ++i) {
        ans.push_back(getNumbit(i));
    }
    return ans;
}



int main(){
    vector<int> a = countBits(5);
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << " ";
    }
    return 0;
}