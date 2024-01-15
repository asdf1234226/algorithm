// 输入：s = "ADOBECODEBANC", t = "ABC"
// 输出："BANC"
// 解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
// s 和 t 由英文字母组成

#include<iostream>
#include<vector>
#include<map>
using namespace std;

bool isValid(map<char, int>& mps, map<char, int>& mpt){
    for(auto it: mpt){
        if(mps[it.first]<it.second){
            return false;
        }
    }
    return true;
}
string minWindow(string s, string t) {
    map<char,int> mps;
    map<char,int> mpt;
    for(auto it: t){
        mpt[it]++;
    }
    int start = 0;
    int minLen = 0x3f3f3f3f;
    int index1=-1;
    for(int end=0;end<s.size();end++){
        mps[s[end]]++;
        while (isValid(mps, mpt))//有效的窗口
        {
            if(end-start+1<minLen){//如果长度变短，也要更新开始下标
                minLen=end-start+1;
                index1=start;
            }
            mps[s[start]]--;
            start++;
        }
    }
    return minLen==0x3f3f3f3f?"":s.substr(index1,minLen);
}

int main(){
    cout << minWindow("ADOBECODEBANC", "ABC");
    return 0;
}