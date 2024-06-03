// 给你一个字符数组 chars ，请使用下述算法压缩：
// 从一个空字符串 s 开始。对于 chars 中的每组 连续重复字符 ：
//     如果这一组长度为 1 ，则将字符追加到 s 中。
//     否则，需要向 s 追加字符，后跟这一组的长度。
// 压缩后得到的字符串 s 应该直接返回 ，需要转储到字符数组 chars 中。需要注意的是，如果组长度为 10 或 10 以上
// 则在 chars 数组中会被拆分为多个字符。

// 请在 修改完输入数组后 ，返回该数组的新长度。
// 你必须设计并实现一个只使用常量额外空间的算法来解决此问题

// 输入：chars = ["a","a","b","b","c","c","c"]
// 输出：返回 6 ，输入数组的前 6 个字符应该是：["a","2","b","2","c","3"]
// 解释："aa" 被 "a2" 替代。"bb" 被 "b2" 替代。"ccc" 被 "c3" 替代。
// chars[i] 可以是小写英文字母、大写英文字母、数字或符号

// 输入：chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
// 输出：返回 4 ，输入数组的前 4 个字符应该是：["a","b","1","2"]。
// 解释：由于字符 "a" 不重复，所以不会被压缩。"bbbbbbbbbbbb" 被 “b12” 替代。

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<char> help(int count){
    vector<char> res;
    while (count > 0)
    {
        res.push_back(count%10+'0');
        count/=10;
    }
    reverse(res.begin(), res.end());
    return res;
}

//如何优化： 不存res，只存长度就行
int compress(vector<char>& chars) {
    int n = chars.size();
    vector<char> res;//为了方便看结果
    int ans = 0;
    char prev = ' ';//指示前一个字符
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        if (chars[i]==prev)
        {
            count++; 
                       
        }else
        {
            if (prev!=' ')
            {
                res.push_back(prev);
                if (count > 1)
                {
                    vector<char> temp = help(count);
                    for (int i = 0; i < temp.size(); i++)
                    {
                        res.push_back(temp[i]);
                    }
                }
            }
            count=1;
            prev = chars[i];
        }
    }
    if (prev!=' ')//循环结束，最后还要判断一次prev和count
    {
        res.push_back(prev);
        if (count>1)
        {
            vector<char> temp = help(count);
            for (int i = 0; i < temp.size(); i++)
            {
                res.push_back(temp[i]);
            }
        }
    }
    
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    
    return res.size();

}

int main(){
    vector<char> a = {'a','b','b','b','c'};
    cout << compress(a);
    return 0;
}