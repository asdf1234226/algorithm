#include<iostream>
#include<vector>
using namespace std;
// 示例 1：
// 输入：version1 = "1.01", version2 = "1.001"
// 输出：0
// 解释：忽略前导零，"01" 和 "001" 都表示相同的整数 "1"
// 示例 2：
// 输入：version1 = "1.0", version2 = "1.0.0"
// 输出：0
// 解释：version1 没有指定下标为 2 的修订号，即视为 "0"
// 示例 3：
// 输入：version1 = "0.1", version2 = "1.1"
// 输出：-1
// 解释：version1 中下标为 0 的修订号是 "0"，version2 中下标为 0 的修订号是 "1" 。0 < 1，所以 version1 < version2
// 示例 4：
// 输入：version1 = "1.0.1", version2 = "1"
// 输出：1
// 示例 5：
// 输入：version1 = "7.5.2.4", version2 = "7.5.3"
// 输出：-1

vector<string> helpSplit(string s){
    vector<string> res;
    if (s=="")
    {
        return res;
    }
    size_t start = 0;
    size_t end = s.find('.');
    while(end!=string::npos){
        res.push_back(s.substr(start, end-1-start+1));
        start=end+1;
        end=s.find('.',start);
    }
    res.push_back(s.substr(start));
    return res;
}

long toNum(string s){
    long res = 0;
    for(int i=0;i<s.size();i++){
        res=res*10+s[i]-'0';
    }
    return res;
}
int compareVersion(string version1, string version2){
    vector<string> a = helpSplit(version1);
    vector<string> b = helpSplit(version2);
    // a=a.size()>=b.size()?a:b;
    // b=a.size()<b.size()?a:b;
    int size = min(a.size(), b.size());
    for (int i = 0; i <size; i++)
    {
        long num1 = toNum(a[i]);
        long num2 = toNum(b[i]);
        if (num1<num2)
        {
            return -1;
        }else if (num1>num2)
        {
            return 1;
        }
    }
    if (size<a.size())
    {
        for (int i = size; i < a.size(); i++)
        {
            if (toNum(a[i])>0)
            {
                return 1;
            }
        }
    }
    if (size<b.size())
    {
        for (int i = size; i < b.size(); i++)
        {
            if (toNum(b[i])>0)
            {
                return -1;
            }
        }
    }
    return 0;   
}

int compareVersion_opt(string version1, string version2){
    int m = version1.size();
    int n = version2.size();
    int i=0,j=0;
    while (i<m || j<n)
    {
        long num1=0, num2=0;
        while (i<m&&version1[i]!='.')
        {
            num1=num1*10+version1[i]-'0';
            i++;
        }
        while (j<n&&version2[j]!='.')
        {
            num2=num2*10+version2[j]-'0';
            j++;
        }
        if (num1<num2)
        {
            return -1;
        }else if (num1>num2)
        {
            return 1;
        }
        i++;
        j++;
    }
    return 0;
}

int main(){
    cout << compareVersion_opt("1.01", "1.001.01");
    return 0;
}