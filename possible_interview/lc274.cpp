#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 输入：citations = [1,3,1]      --> [3,1,1]
// 输出：1
// 输入：citations = [3,0,6,1,5]  --> [6,5,3,1,0]
// 输出：3 
// 解释：给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了 3, 0, 6, 1, 5 次。
//      由于研究者有 3 篇论文每篇 至少 被引用了 3 次，其余两篇论文每篇被引用 不
//      多于 3 次，所以她的 h 指数是 3
int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end(), std::greater<int>());
    int ans = 0;
    for(int i=0;i<citations.size();i++){
        if(citations[i]<i+1){
            ans = i;
            break; 
        }
    }
    return ans;
}

int main(){
    vector<int> a = {1,3,2,2};
    cout << hIndex(a);
    return 0;
}