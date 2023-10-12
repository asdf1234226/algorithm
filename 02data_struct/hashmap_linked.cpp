#include<iostream>
#include<cstring>
using namespace std;

const int N = 100003; //大于10000的第一个质数
int h[N]; //作为单链表头节点，初始化-1
int e[N],ne[N], idx;//单链表的结构

void insert(int x){
    int k = (x%N+N)%N;
    e[idx]=x; //头插法
    ne[idx]=h[k];
    h[k]=idx;
    idx++;
}

bool find(int x){
    int k =(x%N+N)%N;
    for(int i=h[k];i!=-1;i=ne[i]){
        if (e[i]==x)
        {
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    cin >>n;
    memset(h,-1,sizeof(h));
    while (n--)
    {
        char op;
        int x;
        cin >>op;
        cin >>x;
        if (op=='I')
        {
            insert(x);
        }else{
            if (find(x))
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