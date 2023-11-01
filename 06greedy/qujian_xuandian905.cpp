// 3
// -1 1
// 2 4
// 3 5
// 输出2
//N个区间，在数轴上选择尽量少的点，使每个区间至少包含一个选出的点，输出点数量

#include<iostream>
#include<algorithm>
using namespace std;
int n;
const int N = 10010;
struct Range{
    int l;
    int r;
    bool operator<(const Range &w) const{//重载运算符
        return r<w.r;
    }
} ranges[N];

int min_point(){
    int ans =0;
    int st=-1e8; //维持当前区间的右端点值
    sort(ranges,ranges+n);
    for(auto it: ranges){
        if (st<it.l)//如果当前的右端点值，小于下一个区间的左端点，
        //就需要多加一个点放在下个区间的右端点上
        {
            st=it.r;
            ans++;
        }
    }
    return ans;
}


int main(){
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ranges[i].l >> ranges[i].r;
    }
    cout << min_point();
    return 0;
}