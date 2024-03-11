#include<iostream>
using namespace std;

// 输入: num = 58
// 输出: "LVIII"
// 解释: L = 50, V = 5, III = 3.
// 输入: num = 1994
// 输出: "MCMXCIV"
// 解释: M = 1000, CM = 900, XC = 90, IV = 4.
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
// X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
// C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。

#include<vector>
using namespace std;
// 1 <= num <= 3999
string intToRoman(int num) {
    vector<int> values = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    vector<string> symbols = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    string res = "";
    for(int i=0;i<values.size()&&num>0;i++){
        num -= values[i];
        res+=symbols[i];
    }
    return res;
}

int main(){
    return 0;
}