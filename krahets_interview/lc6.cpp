// 将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
// 比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
// P   A   H   N
// A P L S I I G
// Y   I   R
// 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
// 请你实现这个将字符串进行指定行数变换的函数：
//s 由英文字母（小写和大写）、',' 和 '.' 组成

// 输入：s = "PAYPALISHIRING", numRows = 3
// 输出："PAHNAPLSIIGYIR"

#include<iostream>
#include<vector>
using namespace std;


//初始化***填满，计算s[i]在二维数组的下标并且替换，很麻烦
//2*numRows-2为一组，每组的最宽处numRows-1
string convert_err(string s, int numRows) {
    int n = s.size();
    int groupSize = 2*numRows-2;
    int groupNum = n%(groupSize)==0?n/groupSize:(n/groupSize)+1;
    int maxWidth = groupNum*(numRows-1);
    vector<vector<char>> data;
    for(int i =0;i<numRows;i++){
        vector<char> a;
        for (int i = 0; i < maxWidth; i++)
        {
            a.push_back('*');
        }
        data.push_back(a);
    }
    // for (int i = 0; i < data.size(); i++)
    // {
    //     for(int j =0;j<data[i].size();j++){
    //         cout << data[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // return "";
    bool down = true;
    for (int i = 0; i < n; i++)
    {
        int reminder = i %groupSize;//余数
        int groupIndex = i/groupSize;
        if (reminder<numRows)
        {
            int x = groupIndex*(numRows-1);
            int y = reminder;
            data[x][y]=s[i];
        }
        else
        {
            int x =groupIndex*(numRows-1)+reminder-numRows-1;
            int y = (numRows-1)-(reminder-numRows-1);
            cout << x << " " << y;
            data[x][y]=s[i];
        }
    }
    for (int i = 0; i < data.size(); i++)
    {
        for(int j =0;j<data[i].size();j++){
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
    return "";
}

// a     g
// b   f h
// c e   i
// d
//没必要初始化***, 只需要用numRows个string，需要加的时候加到对应的str
string convert(string s, int numRows){
    int n = s.size();
    if (numRows<2)
    {
        return s;
    }
    
    vector<string> res;
    for (int i = 0; i < numRows; i++)
    {
        res.push_back("");
    }
    int groupSize = 2*numRows-2;
    for(int i =0;i<n;i++){
        int reminder = i%groupSize;
        if(reminder<numRows){
            res[reminder]+=s[i];
        }else//在斜线上
        {
            //某个group倒着数第groupSize-reminder个数,刚好对应下标groupSize-reminder
            int index = groupSize-reminder;
            //cout << reminder << endl;
            res[index]+=s[i];
        }
    }
    string ans = "";
    for(auto i: res){
        ans+=i;
    }
    return ans;
}

//优化，添加顺序是先从0到n-1，到n-1后又减到0
string convert_opt(string s, int numRows){
    int n = s.size();
    if (numRows<2)
    {
        return s;
    }
    vector<string> res;
    for (int i = 0; i < numRows; i++)
    {
        res.push_back("");
    }
    int flag = -1;
    int count = 0;
    for(int i =0;i<n;i++){
        if (count==numRows-1 || count==0)
        {   
            flag=-flag;
        }
        res[count]+=s[i];
        count+=flag;
    }
    string ans = "";
    for(auto i: res){
        ans+=i;
    }
    return ans;
}
int main(){
    cout << convert_opt("abcdefghi", 4);
    return 0;
}