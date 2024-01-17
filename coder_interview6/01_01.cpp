// 判定字符是否唯一
// 实现一个算法，确定一个字符串 s 的所有字符是否全都不同。
// 示例 1：
// 输入: s = "leetcode"
// 输出: false

// s[i]仅包含小写字母
// 如果你不使用额外的数据结构，会很加分

#include<iostream>
#include<set>
using namespace std;

bool isUnique(string astr) {
    set<char> st;
    for(auto it: astr){
        if(st.find(it)!=st.end()){
            return false;
        }else
        {
            st.insert(it);
        }
    }
    return true;
}

//查看num的index比特位是不是1
bool help(int num, int index){
    return (num & (1<<index))!=0;
}

//一个int有32个bit，可以用一个bit标记某个字母是否出现过
bool isUnique_opt(string astr){
    int check = 0;
    for(int i = 0;i< astr.size();i++){
        int index = astr[i] - 'a';
        if (help(check, index))
        {
            return false;
        }else
        {
            check+=(1<<index);
        }
        
    }
    return true;
}

int main(){
    if(isUnique_opt("leetcode")){
        cout << "unique";
    }else
    {
        cout << "not unique";
    }
    return 0;
}