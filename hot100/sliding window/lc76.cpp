// 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。
// 如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
// s 和 t 由英文字母组成

// 输入：s = "ADOBECODEBANC", t = "ABC"
// 输出："BANC"
// 解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
//你能设计一个在 o(m+n) 时间内解决此问题的算法吗


#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

bool iSValid(vector<int>& s, vector<int>& t){//s要包含t
    for(int i =0;i<52;i++){
        if(s[i]<t[i]){
            return false;
        }
    }
    return true;
}

int convertInt(char c){
    if (c>='a'&& c<='z')
    {
        return c-'a';
    }else if (c>='A' && c<='Z')
    {
        return 26+c-'A';
    }
    return -1;
}
string minWindow(string s, string t) {
    vector<int> cntt(52,0);
    vector<int> cnts(52,0);
    for(int i =0;i<t.size();i++){
        char c = t[i];
        cntt[convertInt(c)]++;
    }
    int minLen = 0x3f3f3f3f;
    int res[2];//存储最后结果的开始和结束下标
    int start = 0;
    for (int end = 0; end < s.size(); end++)
    {
        char c = s[end];
        cnts[convertInt(c)]++;
        while (iSValid(cnts, cntt))//有效的窗口
        {
            if (end-start+1<minLen)//如果更新窗口长度，也要更新存储结果的开始和结束下标
            {
                minLen=end-start+1;
                res[0]=start;
                res[1]=end;
            }
            cnts[convertInt(s[start])]--;
            start++;
        }
    }
    if (minLen==0x3f3f3f3f){
        return "";
    }else{
        return s.substr(res[0],minLen);
    }
}

// 步骤一
// 不断增加j使滑动窗口增大，直到窗口包含了T的所有元素

// 步骤二
// 不断增加i使滑动窗口缩小，将不必要的元素排除在外，直到不能满足窗口包含T所有元素。



int main(){
    cout << minWindow("a", "aa");
    return 0;
}