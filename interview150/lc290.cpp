#include<iostream>
#include<map>
#include<vector>
using namespace std;

//aba和"dog cat cat"对于这两个写法都有问题，所以不能只建立数量的映射，要建立s的单词和pattern字母之间的映射
bool wordPattern(string pattern, string s) {
    map<char, int> mp1;
    map<string, int> mp2;
    int count = 0;
    int st=0, ed=0;
    while(ed<=s.size()){
        //为什么是<=，要考虑最后一个单词
        if (ed==s.size() || s[ed]==' ')
        {
            string word = s.substr(st, ed-st);
            cout << word << " ";
            st=ed+1;
            mp2[word]++;
            mp1[pattern[count]]++;
            if(count>=pattern.size() || mp2[word]!=mp1[pattern[count]]){
                //当前pattern字母和s的单词出现的次数要相同
                return false;
            }
            count++;
        }
        ed++; 
    }
    return count==pattern.size();
}

bool wordPattern_another(string pattern, string s) {
    map<char, int> mp1;
    map<string, int> mp2;
    int count = 0;
    int st=0, ed=0;
    while(ed<=s.size()){
        while((ed<s.size()&&s[ed]!=' ')){
            ed++;
        }
        string word = s.substr(st, ed-st);
        mp2[word]++;
        mp1[pattern[count]]++;
        if(count>=pattern.size() || mp2[word]!=mp1[pattern[count]]){
            return false;
        }
        count++;
        st=ed+1;
        ed=st;
    }
    return count==pattern.size();
}

bool wordPattern_final(string pattern, string s) {
    vector<string> strs;
    int st =0,ed=0;
    while (ed<=s.size())
    {
        if(ed==s.size()||s[ed]==' '){
            string word = s.substr(st, ed-st);
            strs.push_back(word);
            st=ed+1;
        }
        ed++;
    }
    if(pattern.size()!=strs.size()) return false;
    //要互相建立map，不然"abba", "dog cat cat fish"过不了
    map<string, char> mps;
    map<char,string> mpc;
    for(int i=0;i<strs.size();i++){
        if (mps.find(strs[i])!=mps.end() && mps[strs[i]]!=pattern[i])
        {
            return false;
        }
        if (mpc.find(pattern[i])!=mpc.end()&&mpc[pattern[i]]!=strs[i])
        {
            return false;
        }
        mps[strs[i]]=pattern[i];
        mpc[pattern[i]]=strs[i];
    }
    return true;
}
int main(){
    if(wordPattern_final("jqery", "jqery")){
        cout << "y";
    }else
    {
        cout << "no";
    }
    return 0;
}