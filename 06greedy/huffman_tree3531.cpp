// 5
// 1 2 2 5 9
//输出37

#include<iostream>
#include<queue>
using namespace std;
int n;
const int N = 10010;
int node[N];


int huffman_tree(){
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(node[i]);
    }
    int ans=0;
    while (pq.size())
    {
        if (pq.size()>=2)
        {
            int p1=pq.top();
            pq.pop();
            int p2=pq.top();
            pq.pop();
            int newp = p1+p2;
            ans+=newp;
            pq.push(newp);
        }
        else
        {
            pq.pop();
        }
    }
    return ans;
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> node[i];
    }
    cout << huffman_tree();
    return 0;
}