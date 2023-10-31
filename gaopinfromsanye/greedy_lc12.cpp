//https://mp.weixin.qq.com/s/1RrnSNtfrqx4I-7qZLb7Zw
//整数转罗马数字
#include<iostream>
#include<string>
using namespace std;

int val[13]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
string str[13]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

//优先减大的
string intToRoman(int num){
    string ans = "";

    for (int i = 0; i < 13&&num>0; i++)
    {
        while (num>=val[i])
        {
            num-=val[i];
            ans+=str[i];
        }
    }
    return ans;
}


int main(){
    cout << intToRoman(1000);
    return 0;
}