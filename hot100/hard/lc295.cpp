// 中位数是有序整数列表中的中间值。如果列表的大小是偶数，则没有中间值，中位数是两个中间值的平均值。

// 例如 arr = [2,3,4] 的中位数是 3 。
// 例如 arr = [2,3] 的中位数是 (2 + 3) / 2 = 2.5 。
// 实现 MedianFinder 类:

// MedianFinder() 初始化 MedianFinder 对象。
// void addNum(int num) 将数据流中的整数 num 添加到数据结构中。
// double findMedian() 返回到目前为止所有元素的中位数。与实际答案相差 10-5 以内的答案将被接受。


#include<iostream>
#include<queue>
using namespace std;

//方法一：
//最容易想的思路，初始存放数字的数组空，add可以通过二分查找插入位置(logN)
//然后插入时要O(N)要把插入位置后元素都向后移动

//方法二
// 一个大顶堆一个小顶堆，完全靠堆顶求中位数
// A存放大的一半，B存小的一半==》A小顶堆，B大顶堆
// 1 奇数个数字 N  
//    a. 存储布局：A有N/2+1个，B有N/2个；
//    b. 求中位数 A.top()；
//    c. 如何添加--从偶数个数字转移而来，应该加到A上，不能直接添加这个数，
//       要添加的数是先加入B，B堆顶的数，然后将这个数从B弹出加入A，借助B求N/2+1大的数
//  2 偶数个数字N
//    a.存储布局：A和B都有N/2个；       
//    b.求中位数 [B.top()+A.top()]/2；
//    c.如何添加--从奇数个数字转移而来，应该加到B里，要添加的数需要借助A

class MedianFinder{
public:
    priority_queue<int, vector<int>,greater<int>> A;//小顶堆
    priority_queue<int,vector<int>, less<int>> B;//大顶堆，默认也是大顶堆
    MedianFinder(){

    } 
    void addNum(int num) {
        if (A.size()==B.size())//应该加到A
        {
            B.push(num);
            A.push(B.top());
            B.pop();
        }else//应该加到B
        {
            A.push(num);
            B.push(A.top());
            A.pop();
        }
    }

    double findMedian() {
        if(A.size()==B.size()){
            return (A.top()+B.top())/2.0;
        }
        else
        {
            return A.top();
        }

    }
};
