#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//大数A和B比较  A>B true
bool cmp(vector<int>& A, vector<int>& B) 
{
    if (A.size()!= B.size())
    {
        return A.size()>B.size()?true:false;
    } 
    for (int i = 0; i< A.size(); i++)
    {
        if (A[i]>B[i])
        {
            return true;
        }
    }
    return false;
}
vector<int> high_add(vector<int>& A, vector<int>& B)
{
    int i =0;
    vector<int> C;
    int t =0;
    while (i<A.size() || i<B.size())
    {
        if (i<A.size())
        {
            t+=A[i];
        }
        if (i<B.size())
        {
            t+=B[i];
        } 
        C.push_back(t%10);
        t/=10;
        i++;
    }
    if (t) //如果有进位
    {
        C.push_back(t);
    }
    return C;
}


//满足A>=B, A>=0, B>=0
// if (cmp(B,A))
// {
//     return high_sub(B,A);  //这个要加负号
// }
vector<int> high_sub(vector<int>& A, vector<int>& B)
{
    vector<int> C;
    //A>=B
    int t = 0;
    int tmp = 0;
    for (int i = 0; i < A.size(); i++)
    {
        tmp=A[i]-B[i]-t;
        if (tmp>=0)
        {
            t=0;
            C.push_back(tmp);
        }
        else
        {
            t=1;
            C.push_back(tmp+10);
        }    
    }
    //去除前导0
    while (C.size()>1 &&C.back()==0)
    {
        C.pop_back();
    }
    return C;
}

//A>0
vector<int> high_mul(vector<int>& A, int b)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || t>0; i++) //条件除了<A.size(),还要把t计算完
    {
        if (i<A.size())
        {
            t=t+A[i]*b;
        }
        C.push_back(t%10);
        t=t/10;//进位
    }
    return C;
}

//A>=0 b>0
vector<int> high_div(vector<int>& A, int b, int& t)
{
    vector<int> C;
    //从高位开始
    for (int i = A.size()-1; i >= 0; i--)
    {
        int temp = t*10+A[i];
        C.push_back(temp/b);
        t=temp%b;
    }
    //去除前导0
    while (C.size()>1 && C.back()==0)
    {
        C.pop_back();
    }
    reverse(C.begin(), C.end()); // #include <algorithm>
    return C;
}

int main()
{
    //存储
    string a = "123";
    vector<int> A;
    for (int i =a.size()-1; i >= 0; i--)
    {
        A.push_back(a[i]-'0');
    }
    string b = "24";
    vector<int> B;
    for (int i =b.length()-1; i >= 0; i--)
    {
        B.push_back(b[i]-'0');
    }
    //vector<int> C = high_add(A,B);
    //vector<int> C = high_sub(A,B);
    //vector<int> C = high_mul(A, 23);
    int r = 0;
    vector<int> C = high_div(A, 23, r);
    for (int i = C.size()-1; i >=0 ; i--)
    {
        cout << C[i] << " ";
    }
    cout << "remainder" << r << endl;
    return 0;

}
