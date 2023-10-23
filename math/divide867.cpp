//
// Created by SP on 2023/10/22.
//

#include<iostream>
using namespace std;
int n;

void divide(int x){
    for (int i = 2; i <= x/i ; i++) { //i一定是质数，如果i是合数，则i可以分解成多个质因子相乘，存在质因子a比i小，而比i小的在之前已经被除完了
        if (x%i==0){//计算质因子个数
            int cnt=0;
            while (x%i==0){
                x/=i;
                cnt++;
            }
            cout << i << " " << cnt <<endl;
        }
    }
    if (x>1){//最多存在一个大于sqrt(x)的质因子
        cout << x << " " << 1 << endl;
    }
}

int main(){
    cin >> n;
    while (n--){
        int x;
        cin >> x;
        divide(x);
        cout << endl;
    }
    return 0;
}