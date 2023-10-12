#include <iostream>
using namespace std;

//check(mid)条件 左边<=x,右边>x
int bsearch_r(int q[], int t, int l, int r)
{
    while(l<r)
    {
        int mid = (l+r+1)>>1;
        if(q[mid]<=t){
            l=mid;
        }else
        {
            r=mid-1;
        }
    }
    return q[l]==t?l:-1;
}

int bsearch_l(int q[], int t, int l, int r)
{
    while (l<r)
    {
        int mid =(l+r)>>1;
        if (q[mid]>=t)
        {
            r=mid;
        }else
        {
            l=mid+1;
        }
        
    }
    return q[l]==t?l:-1;
    
}

int main()
{
    int q[] = {2,3,3,3,7,9};
    int len = sizeof(q)/sizeof(q[0]);
    cout << "l index: " << bsearch_l(q,3,0,len-1) << ",r index: " << bsearch_r(q,3,0,len-1)<< endl;
    return 0;
}