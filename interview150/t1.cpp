#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> a = {0,0,1};
    vector<int> b = {0,0,1};
    if(a==b){
        cout << "e";
    }else{
        cout << "ne";
    }
    return 0;
}