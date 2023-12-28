// 给定一个字符串，编写一个函数判定其是否为某个回文串的排列之一。
// 回文串是指正反两个方向都一样的单词或短语。排列是指字母的重新排列。
// 回文串不一定是字典当中的单词。

// 输入："tactcoa"
// 输出：true（排列有"tacocat"、"atcocta"，等等）

#include<iostream>
#include<vector>
using namespace std;

bool canPermutePalindrome(string s) {
    vector<int> cnt(26,0);
    for(auto it: s){
        cnt[it-'a']++;
    }
    int odd_count = 0;//统计奇数个数
    for(int i=0;i<26;i++){
        if(cnt[i]%2==1){
            odd_count++;
        }
    }
    return odd_count<=1;
}

int main(){
    string s = "tactcoa";
    if (canPermutePalindrome(s))
    {
        cout << "can";
    }else
    {
        cout << "can not";
    }
    return 0;
}