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

//多指针
//往后产生的丑数，都是已有丑数 × 质因数 2、3、5
//初始化丑数列表，首个丑数是1， a,b,c都指向这个丑数
// 下一个丑数如何产生   res[a]*2, res[b]*3, res[c]*5，这三个中的最小值
//                  被选中的丑数指针++ (a++ or b++ or c++)
int nthUglyNumber_opt(int n) {
    int a = 0, b=0, c=0;
    int idx = 0;
    vector<int> res(n,0);
    res[0]=1;
    for(int i =1;i<n;i++){
        int n2=res[a]*2;
        int n3=res[b]*3;
        int n5=res[c]*5;
        res[++idx]= min(n2, min(n3,n5));
        if (res[idx]==n2){
            a++;
        }
        if (res[idx]==n3){
            b++;
        }
        if(res[idx]==n5){
            c++;
        }
    }
    return res[n-1];
}

int main(){
    cout << nthUglyNumber_opt(10);
    return 0;    
}


