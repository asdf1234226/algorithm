#include<iostream>
using namespace std;
const int N = 100010;
const int P =131;
char str[N];
typedef unsigned long long ULL;
ULL h[N], p[N];  //h[k]存储前k个字母的hash值，p[k]是p^k

ULL get(int l, int r){
    return h[r]-h[l-1]*p[r-l+1];
}
void init(string s){
    p[0]=1;
    s="0"+s;
    for(int i=1;i<s.size();i++){
        h[i]=h[i-1]*P+s[i];
        p[i]=p[i-1]*P;
    }
}

// 8 3
// aabbaabb
// 1 3 5 7
// 1 3 6 8
// 1 2 1 2
void print_yn(int l1,int r1, int l2, int r2){
    if(get(l1,r1)==get(l2,r2)){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }
}
int main(){
    int n=8;
    string s ="aabbaabb";
    init(s);
    print_yn(1,3,5,7);
    print_yn(1,3,6,8);
    print_yn(1,2,1,2);
    
    return 0;
    
}


