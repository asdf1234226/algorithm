// 示例 1:
// 输入: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
//  4 2 2 7 2 4 14
// 输出:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]

#include<iostream>
#include<vector>
using namespace std;

// 如果当前行只有一个单词，特殊处理为左对齐；
// 如果当前行为最后一行，特殊处理为左对齐；
// 其余为一般情况，分别计算「当前行单词总长度」、「当前行空格总长度」和「往下取整后的单位空格长度」，
// 然后依次进行拼接。当空格无法均分时，每次往靠左的间隙多添加一个空格，直到剩余的空格能够被后面的间隙所均分


string help(vector<string>& tmp, int maxWidth, bool lastLine){
    int n = tmp.size();
    if(n==1){
        string s = tmp[0];
        for(int i=0;i+tmp[0].size()<maxWidth;i++){
            s+=" ";
        }
        return s;
    }
    int total = 0;
    for(auto it: tmp){
        total +=it.size();
    }
    int average = (maxWidth-total)/(n-1);
    int yushu = (maxWidth-total)%(n-1);
    string s = "";
    if (lastLine)
    {
        for (int i = 0; i < n; i++)
        {
            if (s=="")
            {
                s+=tmp[i];
            }else
            {
                s+=" ";
                s+=tmp[i];
            }
        }
        for(int i=s.size();i<maxWidth;i++){
            s+=" ";
        }
        return s;
    }
    
    for(int i=0;i<n;i++){
        s+=tmp[i];
        if(i==n-1){
            break;
        }
        for(int k=0;k<average;k++){
            s+=" ";
        }
        if (yushu!=0 && i+1<=yushu)
        {
            s+=" ";
        }
    }
    return s;
}

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int w = 0;
    int st = 0;
    int n = words.size();
    vector<string> ans;
    vector<string> tmp;
    while(st<n){
        if (w==0)
        {
            tmp.clear();//行开始
            w+=words[st].size();
            tmp.push_back(words[st]);
            st++;
        }else if (w+1+words[st].size()<=maxWidth)//+1是加上words[st]之前加一个空格
        {
            w+=words[st].size()+1;
            tmp.push_back(words[st]);
            st++;
        }else{
            w=0;
            //整理tmp
            ans.push_back(help(tmp, maxWidth, false));
        }
    }
    if(!tmp.empty()){//剩余的结果
        ans.push_back(help(tmp, maxWidth, true));
    }
    return ans;
}

int main(){
    // vector<string> a = {"This", "is", "an", "example", "of", "text", "justification."};
    // vector<string> res = fullJustify(a, 16);
     vector<string> tmp = {"shall", "be"};
     string s = help(tmp, 16, true);
     cout << s << "," << s.size();
    return 0;
}