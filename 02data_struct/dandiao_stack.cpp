#include<iostream>
using namespace std;

//找出离x最近的，左侧的比x小的数
//输入5
//3 4 2 7 5
//输出：-1 3 -1 2 2
const int N =10010;
int s[N];
int tt = 0;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        while (tt&&s[tt]>=x) //如果当前栈顶>=x，出栈
        {
            tt--;
        }
        if (!tt){//空栈
            cout << "-1" << " ";
        }
        else
        {   //不是空栈，栈顶就是左侧离x最近且＜x的值
            cout << s[tt]<< " ";
        }
        s[++tt]=x;
    }
    return 0;
}