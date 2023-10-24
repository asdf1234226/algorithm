//
// Created by SP on 2023/10/22.
//
#include<iostream>
using namespace std;

bool is_prime(int x){
    for(int i=2;i<=x/i;i++){ //i*i<=n可能会溢出，i<sqrt(x)可能计算时间较久
        if (x%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int x =11;
    if (is_prime(x)){
        cout << "x is prime";
    } else{
        cout << "x is not prime";
    }
    return 0;
}