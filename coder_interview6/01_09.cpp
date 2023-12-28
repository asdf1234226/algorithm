// 字符串轮转。给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成
// （比如，waterbottle是erbottlewat旋转后的字符串）。
// 示例1:
//  输入：s1 = "waterbottle", s2 = "erbottlewat"
//  输出：True

//  你能只调用一次检查子串的方法吗？

//长度不同，false
//长度相同：  拼接两个s1，判断s2是不是这个拼接字符串的子串
//"waterbottlewaterbottle"

#include<iostream>
using namespace std;

bool isFlipedString(string s1, string s2) {
    if (s1.size()!=s2.size())
    {
        return false;
    }
    if (s1.size()==0 && s2.size()==0)
    {
        return true;
    }
    
    s1+=s1;
    int n = s2.size();
    for (int i = 0; i < n; i++)
    {
        if (s1.substr(i,n)==s2)
        {
            return true;
        }
    }
    return false;
}

int main(){
    if (isFlipedString("waterbottle","erbottlewat"))
    {
        cout << "y";
    }else
    {
        cout << "n";
    }
    return 0;
}