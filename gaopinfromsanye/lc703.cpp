#include <iostream>
#include <queue>
using namespace std;
//how to run: g++ lc703.cpp -std=c++11
class KthLargest
{
public:
    KthLargest(int _k, vector<int>& nums)
    {
        k = _k; //初始化
        cout << "kth" << endl;
        for (auto i: nums)
        {
            add(i);
        }
        
    }
    void add(int val) 
    {
        if (pq.size() < k) //维护大小为k小根堆，如果元素大于堆顶，就要替换 
        {
            pq.push(val);
            cout<< "push val " << val << endl;
        }
        else if (val > pq.top())
        {
            pq.pop();
            pq.push(val);
            cout<< "push valk " << val << endl;
        }
    }
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
    //priority_queue<int> pq;
};

int main(int argc, char const *argv[])
{
    vector<int> num = {4,5,8,2,10,3};
    int k = 3;
    KthLargest kth = KthLargest(k, num);
    cout << kth.pq.top() << endl;
    return 0;
}

