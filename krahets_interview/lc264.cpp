// 给你一个整数 n ，请你找出并返回第 n 个丑数。 丑数就是质因子只包含 2 、 3 和 5 的正整数。 
// 示例1： 输入：n = 10 输出：12 解释：[1, 2, 3, 4, 5, 6, 8, 9,10,12]


#include<iostream>
#include<queue>
#include<set>
using namespace std;
// 将最小的丑数1入队
// 每次从队列中取出最小值，将该值分别 *2， *3， *5 放入队列
// 第n次出队就是第 n 个丑数
// 为了防止重复，用set过滤

int nthUglyNumber(int n) {
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);
    set<int> st;
    st.insert(1);
    int multi[3] = {2,3,5};
    for(int i=1;i<=n;i++)//出队n次
    {
        int x = pq.top();
        pq.pop();
        if(i==n){
            return x;
        }
        for(int j=0;j<3;j++){
            int newNum = multi[j]*x;
            if(st.find(newNum)==st.end()){
                st.insert(newNum);
                pq.push(newNum);
            }
        }
    }
    return -1;
}

int nthUglyNumber_opt(int n) {

}

int main(){
    cout << nthUglyNumber(10);
    return 0;    
}

    int nthUglyNumber(int n) {
        // 存储丑数
        int *arr = new int[n + 1];
        arr[1] = 1;
        
        for (int x = 1, y = 1, z = 1, index = 2; index <= n; index++){
            int a = arr[x] * 2, b = arr[y] * 3, c = arr[z] * 5;
            int m = min(a, min(b, c));
            if (m == a)x++;
            if (m == b)y++;
            if (m == c)z++;
            arr[index] = m;
        }
        int ans = arr[n];
        delete[] arr;
        return ans;
    }

