// 给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。
// 注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。
// 返回一个表示每个字符串片段的长度的列表。

// 输入：s = "ababcbacadefegdehijhklij"
// 输出：[9,7,8]
// 解释：
// 划分结果为 "ababcbaca"、"defegde"、"hijhklij" 。
// 每个字母最多出现在一个片段中。
// 像 "ababcbacadefegde", "hijhklij" 这样的划分是错误的，因为划分的片段数较少。

#include<iostream>
#include<vector>
using namespace std;

// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
// a b a b c b a c a d  e  f  e  g  d  e  h  i  j  h  k  l  i  j
// 8 5 8 5 7 5 8 7 8 ...                  19 22 23 19 20 21 22 23

// 统计每一个字符最后出现的位置
// 从头遍历字符，并更新字符的最远出现下标，如果找到字符最远出现位置下标和当前下标相等了，则找到了分割点
vector<int> partitionLabels(string s) {
    vector<int> last_index(26,-1);
    for(int i =0;i<s.size();i++){
        last_index[s[i]-'a']=i;
    }
    // for(int i =0;i<26;i++){
    //     cout << last_index[i] << " ";
    // }

    vector<int> ans;
    int farthest = -1;
    for(int i =0;i<s.size();i++){
        if (farthest==i)
        {
            ans.push_back(farthest);
            farthest=-1;
        }else
        {
            farthest=max(farthest, last_index[s[i]-'a']);
        }
    }
    //ans存储分割点下标
    if(ans.size()==0){
        return ans;
    }
    vector<int> res;
    for (int i = 0; i < ans.size(); i++)
    {
        if(i==0){
            res.push_back(ans[i]+1);
        }else
        {
            res.push_back(ans[i]-ans[i-1]);
        }
    }
    return res;
}

int main(){
    string s = "ababcbacadefegdehijhklij";
    vector<int> a = partitionLabels(s);
    for(auto i: a){
        cout << i << " ";
    }
    return 0;
}