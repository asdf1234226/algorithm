//
// Created by SP on 2023/10/22.
//

#include<iostream>
using namespace std;

int gcd(int a, int b){
    return b? gcd(b,a%b):a;
}

int main(){
    cout << gcd(5,10);
    return 0;
}
