#include<iostream>
#include<vector>
#include<map>
using namespace std;

// 给定一个字符串 s 和一个字符串数组 words。 words 中所有字符串 "长度相同"。
//  s 中的 串联子串 是指一个包含  words 中所有字符串以任意顺序排列连接起来的子串。

// 例如，如果 words = ["ab","cd","ef"]， 那么 "abcdef"， "abefcd"，"cdabef"， "cdefab"，"efabcd"， 和 "efcdab" 都是串联子串。 "acdbef" 不是串联子串，因为他不是任何 words 排列的连接。
// 返回所有串联子串在 s 中的开始索引。你可以以 任意顺序 返回答案。
// 输入：s = "barfoothefoobarman", words = ["foo","bar"]
// 输出：[0,9]
// 解释：因为 words.length == 2 同时 words[i].length == 3，连接的子字符串的长度必须为 6。
// 子串 "barfoo" 开始位置是 0。它是 words 中以 ["bar","foo"] 顺序排列的连接。
// 子串 "foobar" 开始位置是 9。它是 words 中以 ["foo","bar"] 顺序排列的连接。
// 输出顺序无关紧要。返回 [9,0] 也是可以的。

//各个字符串长度相同，所以维护一个固定长度的窗口？
//TLE
vector<int> findSubstring_tle(string s, vector<string>& words) {
    int n = words.size();
    vector<int> ans;
    int len = n*words[0].size();
    if (s=="" || n==0)
    {
        return ans;
    }
    map<string, int> mp1;
    for(auto it: words){
        mp1[it]++;
    }
    map<string, int> mp2;
    for (int i = 0; i + len-1< s.size(); i++)
    {
        mp2.clear();
        int j = i;
        for (int k = 0; k < n; k++)
        {
            mp2[s.substr(j,words[0].size())]++;
            j+=words[0].size();
        }
        if(mp2==mp1){
            ans.push_back(i);
        }
    }
    return ans;
}

vector<int> findSubstring(string s, vector<string>& words)
{
    int n = words.size();
    vector<int> ans;
    if (s=="" || n==0)
    {
        return ans;
    }
    map<string, int> mp1;
    for(auto it: words){
        mp1[it]++;
    }
    int word_size = words[0].size();
    map<string, int> mp2;
    //遍历所有的对齐方式
    //假设 one_word 是 3，那么我们需要检查的对齐方式是：
    // 从 s[0]，s[3]，s[6]... 开始的子串
    // 从 s[1]，s[4]，s[7]... 开始的子串
    // 从 s[2]，s[5]，s[8]... 开始的子串
    // 我们不需要从 s[3] 开始一个新的外循环，因为这会和第一个对齐方式重复
    for (int i = 0; i < word_size; i++)
    {
        mp2.clear();//每个对齐方式都要清空一下mp2
        int st=i, ed=i;
        while(st <= ed && ed+word_size-1<s.size()){
            string w = s.substr(ed, word_size);
            ed+=word_size;
            if (mp1.find(w)==mp1.end())//这个单词不在words中,置位
            {
                st = ed;
                mp2.clear();
            }else
            {
                mp2[w]++;
                //如果在，数量超过了words中的，就缩短左边
                while (mp2[w]>mp1[w])
                {
                    string w2 = s.substr(st, word_size);
                    mp2[w2]--;
                    st+=word_size;
                }
                if(mp1==mp2){
                    for(auto it: mp2){
                        cout << it.first << "-" << it.second << " ";
                    }
                    cout << endl;
                    cout << st << " " << ed << endl;
                    ans.push_back(st);
                }               
            }
        }
    }
    return ans; 
}


int main(){
    vector<string> words = {"ababa","babab"};
    vector<int> res = findSubstring("ababababab", words);
    for(auto it: res){
        cout << it << " ";
    }
    return 0;
}