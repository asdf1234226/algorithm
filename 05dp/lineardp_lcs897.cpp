//
// Created by SP on 2023/10/29.
//

//4 5
//acbd
//abedc
//输出3， abd
//https://www.acwing.com/solution/content/8111/

#include<iostream>
using namespace std;
int n,m;
const int N = 1010;
char a[N], b[N];
int f[N][N];

int max_lcs(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if (a[i]==b[j]){
                f[i][j]=f[i-1][j-1]+1;
            }else{
                f[i][j]=max(f[i-1][j], f[i][j-1]);
            }
        }
    }
    return f[n][m];
}

int main(){
    cin >> n >> m;
    cin >> a+1 >>b+1;
    cout << max_lcs();
    return 0;
}