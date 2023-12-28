// 给定两个由小写字母组成的字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。
// 示例 1：
// 输入: s1 = "abc", s2 = "bca"
// 输出: true 

#include<iostream>
#include<vector>
using namespace std;

bool CheckPermutation(string s1, string s2) {
    vector<int> a(26,0);
    vector<int> b(26,0);
    for(auto it: s1){
        a[it-'a']++;
    }
    for(auto it: s2){
        b[it-'a']++;
    }
    for(int i =0;i<26;i++){
        if(a[i]!=b[i]){
            return false;
        }
    }
    return true;

}

int main(){
    if (CheckPermutation("abc","bca"))
    {
        cout << "true";
    }else
    {
        cout << "false";
    }
    return 0;
}