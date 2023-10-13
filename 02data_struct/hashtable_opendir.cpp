#include<iostream>
#include<cstring>
using namespace std;
const int N = 200003; //200003是第一个＞20万的质数
int h[N];
const int null=0x3f3f3f3f;

//有点像离散化？
int find(int x){//返回下标
    int k =(x%N+N)%N;
    while (h[k]!=null && h[k]!=x) //如果被占用
    {
        k++;
        if (k==N) //到结尾都被占用，就从头开始
        {
            k=0;
        }
    }
    return k;
}

int main(){
    memset(h,0x3f,sizeof h); //memset按字节初始化，h中的元素都被初始化为0x3f3f3f3f;
    int n;
    cin >>n;
    while (n--)
    {
        char op;
        int x;
        cin >>op;
        cin >>x;
        if (op=='I')
        {
            int k = find(x);
            h[k]=x;
        }else{
            int k = find(x);
            if (h[k]!=null) //找到
            {
                puts("yes");
            }else
            {
                puts("no");
            }
        }
    }
    return 0;
}