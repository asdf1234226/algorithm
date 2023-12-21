
//给定两个字符串s 和t ，编写一个函数来判断t 是否是s 的字母异位词


#include<iostream>
#include<map>
using namespace std;

bool isAnagram(string s, string t){
    map<char, int> mp;
    if(s.size()!=t.size()){
        return false;
    }
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }
    for(int i=0;i<t.size();i++){
        mp[t[i]]--;
    }
    for(auto it: mp){
        if(it.second!=0){
            return false;
        }
    }
    return true;
}

int main(){
    if (isAnagram("abc","cba"))
    {
        cout << "y";
    }
    return 0;
}