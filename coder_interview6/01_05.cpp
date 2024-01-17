// 字符串有三种编辑操作:插入一个英文字符、删除一个英文字符或者替换一个英文字符。
//  给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑

// 示例 1:
// 输入: 
// first = "pale"
// second = "ple"
// 输出: True
 
// 示例 2:
// 输入: 
// first = "pales"
// second = "pal"

#include<iostream>
using namespace std;

//0次编辑  相同
//1次编辑  
//        a.插入/删除  长度差1  ---  等价于对短的插入
//        c.替换  长度相同
bool oneEditAway(string first, string second) {
    //first.size()==econd.size()时要保证一个shorter和longer取不同的
    string shorter = first.size()<=second.size()?first:second;
    string longer = first.size()>second.size()?first:second;
    int n1 = shorter.size();
    int n2 = longer.size();
    if (n1==n2)
    {
        if (shorter==longer)
        {
            return true;
        }else //最多只能替换一个字母
        {
            int count = 0;
            for (int i = 0; i < n1; i++)
            {
                if (shorter[i]!=longer[i])
                {
                    count++;
                }
            }
            return count <=1;
        }
    }
    if (n2-n1==1)//插入 ca和cab; cac和cabc
    {
        int i = 0, j=0;
        bool hasInsert = false;
        while (i<n1 && j <n2)
        {
            if (shorter[i]==longer[j])
            {
                i++;
                j++;
            }else
            {
                if (hasInsert)//已经添加过一次
                {
                    return false;
                }else
                {
                    hasInsert=true;
                    j++;//添加
                }
            }  
        }
        return true;
    }
    return false;
}

int main(){

    if (oneEditAway("pales", "ple"))
    {
        cout << "y";
    }else
    {
        cout << "n";
    }
    return 0;

}