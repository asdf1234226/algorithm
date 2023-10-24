//
// Created by SP on 2023/10/22.
//
//给定一个正整数 n，请你求出 1∼n 中质数的个数

#include <iostream>
using namespace std;
const int N = 1e6+10;
int n;
bool st[N];//true是被筛去的数，剩余的则是质数
int prime[N];

void get_prime(int x){
    int cnt =0;
    for (int i = 2; i <=x ; i++) {
        if (!st[i]){
            prime[cnt++]=i; //把素数存起来
        }
        for (int j = i; j <=x ; j+=i) {//不管素数还是合数，筛去后面它们的倍数
            st[j]=true;
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < cnt; ++i) {
        cout << prime[i] << " ";
    }
}


int main(){
    cin >> n;
    get_prime(n);
    return 0;
}