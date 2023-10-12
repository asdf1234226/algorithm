#include<iostream>
using namespace std;

const int N = 1e6+10;
int tmp[N];
void m_sort(int q[], int l , int r)
{
    if (l>=r)   //1.递归要判断退出条件
    {
        return;
    }
    int mid = (l+r)>>1;
    m_sort(q,l,mid);
    m_sort(q,mid+1,r);
    int k = 0;
    int i = l,j=mid+1;
    while (i<=mid &&j<=r)
    {
        if (q[i]>q[j])
        {
            tmp[k++]=q[j++]; //2.不要忘了++
        }
        else
        {
            tmp[k++]=q[i++];
        }
    }
    while (i<=mid)
    {
        tmp[k++]=q[i++];
    }
    while(j<=r){
        tmp[k++]=q[j++];
    } 
    for (int i = 0; i < k; i++)
    {
        q[i+l]=tmp[i];  //3.将tmp的0-k，复制到q(l,r)
    }  
    
}

int main()
{
    int num[] = {2,5,7,8,4};
    int len = sizeof(num)/sizeof(num[0]);
    m_sort(num,0,len-1);
    for(int i = 0;i<len;i++){
        cout<<num[i]<<endl;
    }

}