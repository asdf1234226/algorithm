// 字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。
// 比如，字符串aabcccccaaa会变为a2b1c5a3。若“压缩”后的字符串没有变短，则返回原先的字符串
// 。你可以假设字符串中只包含大小写英文字母（a至z）。

// 示例1:
//  输入："aabcccccaaa"
//  输出："a2b1c5a3"

#include<iostream>
using namespace std;

string compressString(string S) {
    int n = S.size();
    string ans = "";
    int i = 0;
    while (i<n)
    {
        int j = i;
        int count = 0;
        while (j<n && S[j]==S[i])
        {
            count++;
            j++;
        }
        ans+=S[i];
        ans+=to_string(count);
        count = 0;//清空count
        i=j;//更新下一轮i
    }
    return ans;
}

int main(){
    cout << compressString("aabcccccaaa");
    return 0;
}