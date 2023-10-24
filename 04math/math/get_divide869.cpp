//
// Created by SP on 2023/10/22.
//
//输入
//2
//6
//8
//输出
//1 2 3 6
//1 2 4 8
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;

void get_divide(int x){
    vector<int> res;
    for (int i = 1; i <= x/i ; ++i) {
        if (x%i==0){
            res.push_back(i);
            if (i!=x/i){
                res.push_back(x/i);
            }
        }
    }
    sort(res.begin(), res.end());
    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;

}

int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >>x;
        get_divide(x);
    }
    return 0;
}