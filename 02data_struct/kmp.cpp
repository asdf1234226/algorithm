#include<iostream>
using namespace std;

const int N = 10010;
int next1[N];

//求next数组
void getNext(string& p)
{
    int j=0;
    next1[0]=0;
    for (int i = 1; i < p.size(); i++)
    {
        while (j>0 && p[i]!=p[j]) //不等
        {
            j=next1[j-1];//更新j
        }
        if (p[i]==p[j])//相等,j++
        {
            j++;
        }
        next1[i]=j;
    }
}

int strStr(string s, string p)
{
    if (p=="")
    {
        return 0;
    }
    getNext(p);//计算next数组
    int j = 0;
    for (int i = 0; i < s.size(); i++) //i从0开始
    {
        while(j>0 && s[i]!=p[j]){
            j=next1[j-1];
        }
        if (s[i]==p[j])
        {
            j++;
        }
        if (j==p.size()) //满足条件return
        {
            return i-p.size()+1;
        }
    }
    return -1;
}
int main()
{
    string s = "aabaabaaf";
    string p = "aabaaf";
    cout << strStr(s, p);
    return 0;
}