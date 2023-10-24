//
// Created by SP on 2023/10/22.
//

//给定一个正整数 n，请你求出 1∼n 中质数的个数
////埃式筛

#include <iostream>
using namespace std;

const int N = 1e6+10;
int prime[N];//存放素数
bool st[N];
int n;

void get_prime(int x){
    int cnt =0;
    for (int i = 2; i <=x ; i++) {
        if(!st[i]){
            prime[cnt++]=i;
            for (int j = i; j <=x ; j+=i) {//仅需要对素数后面的倍数筛掉
                st[j]= true;
            }
        }
    }
    cout << cnt<<endl;
    for (int i = 0; i < cnt; ++i) {
        cout << prime[i] << " ";
    }
}


int main(){
    cin >> n;
    get_prime(n);
    return 0;
}