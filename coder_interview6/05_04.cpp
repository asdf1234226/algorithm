// 下一个数。给定一个正整数，找出与其二进制表达式中1的个数相同且大小最接近的那两个数（一个略大，一个略小）。

// 示例1:
//  输入：num = 2（或者0010）
//  输出：[4, 1] 或者（[0100, 0001]）
// num的范围在[1, 2147483647]之间；
// 如果找不到前一个或者后一个满足条件的正数，那么输出 -1。

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int help(vector<int>& a){
    int res = 0;
    int op = 1;
    for (int i = 31; i >=0; i--)
    {
        if (a[i]==1)
        {
            res+=op;
        }
        op<<=1;
    }
    return res;
}

//转成二进制数组
//找到最后一个01-->10 后面的1都往右边靠  --》大的  找不到返回-1
//找到最后一个10-->01 后面的1往左靠   ---》小的    找不到返回-1
vector<int> findClosedNumbers(int num) {
    vector<int> res = {-1,-1};
    vector<int> a(32,0);
    int cop = num;
    for (int i = 0; i < 32; i++)
    {
        if ((cop&1)==1)
        {
            a[31-i]=1;
        }
        cop>>=1;
    }
    cout << help(a) << endl;
    vector<int> backup1(a.size());//备份
    copy(a.begin(),a.end(), backup1.begin());
    int index1 = -1;
    for (int i = 31; i-1>=0; i--)
    {
        if (backup1[i-1]==0&&backup1[i]==1)
        {
            index1=i;
            break;
        }
    }
    
    if (index1!=-1)
    {
        swap(backup1[index1], backup1[index1-1]);
        int count1 = 0;//计算index1后1的个数
        for (int i = index1+1; i < 32; i++)
        {
            if (backup1[i]==1)
            {
                count1++;
            }
        }
        for (int i = 31; i>=index1+1; i--)//将count1个1放在最右边
        {
            if (count1>0)
            {
                backup1[i]=1;
                count1--;
            }else
            {
                backup1[i]=0;
            }
        }
        res[0] = help(backup1);
    }
    
    
    int index2 = -1;
    for (int i = 31; i-1>=0; i--)
    {
        if (a[i-1]==1&&a[i]==0)
        {
            index2=i;
            break;
        }
    }
    if (index2!=-1)
    {
        swap(a[index2-1],a[index2]);
        int count2 = 0;//计算index2后1的个数
        for (int i = index2+1; i < 32; i++)
        {
            if (a[i]==1)
            {
                count2++;
            }
        }
        for (int i = index2+1;i<32;i++)//将count2个1放在index2后面
        {
            if (count2>0)
            {
                a[i]=1;
                count2--;
            }else
            {
                a[i]=0;
            }
        }
        res[1]=help(a);
    }
    return res;
}

int main(){
    // 00110000
    // 00100001
    vector<int> a = findClosedNumbers(48);
    cout << a[0] << ":" << a[1];
    return 0;
}