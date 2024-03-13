// 给定一个字符串 s 和一个字符串数组 words。 words 中所有字符串 长度相同。
// s 中的 串联子串 是指一个包含  words 中所有字符串以任意顺序排列连接起来的子串。
// 例如，如果 words = ["ab","cd","ef"]， 那么 "abcdef"， "abefcd"，"cdabef"， 
// "cdefab"，"efabcd"， 和 "efcdab" 都是串联子串。 "acdbef" 不是串联子串，
// 因为他不是任何 words 排列的连接。
// 返回所有串联子串在 s 中的开始索引。你可以以 任意顺序 返回答案。

// 输入：s = "barfoothefoobarman", words = ["foo","bar"]
// 输出：[0,9]
// 解释：因为 words.length == 2 同时 words[i].length == 3，连接的子字符串的长度必须为 6。
// 子串 "barfoo" 开始位置是 0。它是 words 中以 ["bar","foo"] 顺序排列的连接。
// 子串 "foobar" 开始位置是 9。它是 words 中以 ["foo","bar"] 顺序排列的连接。
// 输出顺序无关紧要。返回 [9,0] 也是可以的。

#include<iostream>
#include<vector>
#include<map>
using namespace std;
//判断一个字符串能否由多个子串排列而成

map<string, int> mps;
bool canDivid(string s, int left, int lsize, vector<string>& words){
    string str = s.substr(left, lsize);
    map<string, int> mp;
    int wsize = words[0].size();
    int n = words.size();
    for(int i=0;i<str.size();i+=wsize){
        mp[str.substr(i,wsize)]++;
    }
    return mp==mps;
}

vector<int> findSubstring(string s, vector<string>& words) {
    for(auto i: words){
        mps[i]++;
    }
    vector<int> ans;
    if(words.size()==0) return ans;
    int len = words.size()*words[0].size();
    for(int i=0;i+len<s.size();i++){
        if(canDivid(s,i,len,words)){
            ans.push_back(i);
        }
    }
    return ans;

}
int main(){
    string s = "barfoothefoobarman";
    vector<string> words = {"foo","bar"};
    vector<int> a = findSubstring(s,words);
    for(auto i: a){
        cout << i << " ";
    }
    return 0;
}