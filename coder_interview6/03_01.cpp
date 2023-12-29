// 三合一。描述如何只用一个数组来实现三个栈。
// 你应该实现push(stackNum, value)、pop(stackNum)、isEmpty(stackNum)、peek(stackNum)方法。
// stackNum表示栈下标，value表示压入的值。
// 构造函数会传入一个stackSize参数，代表每个栈的大小。

//  输入：
// ["TripleInOne", "push", "push", "pop", "pop", "pop", "isEmpty"]
// [[1], [0, 1], [0, 2], [0], [0], [0], [0]]
//  输出：
// [null, null, null, 1, -1, -1, true]
// 说明：当栈为空时`pop, peek`返回-1，当栈满时`push`不压入元素。

#include<iostream>
#include<vector>
using namespace std;

class TripleInOne {
public:
    vector<int> nums;
    int size;//每个栈对应大小
    int index0;//每个栈的index
    int index1;
    int index2;
    TripleInOne(int stackSize) {
        size=stackSize;
        nums.resize(size*3,-1);
        index0=0;
        index1=size;
        index2=size*2;
    }
    
    void push(int stackNum, int value) {
        if (stackNum==0)
        {
            if (index0<size)//没满
            {
                nums[index0]=value;
                index0++;
            }
            else//满了
            {
                return;
            }
            
        }else if (stackNum==1)
        {
            if (index1<size*2)
            {
                nums[index1]=value;
                index1++;
            }
            else
            {
                return;
            }   
        }else
        {
            if (index2<size*3)
            {
                nums[index2]=value;
                index2++;
            }else
            {
                return;
            }
        }
    }
    
    int pop(int stackNum) {
        if (stackNum==0)
        {
            if (index0==0)//空了
            {
                return -1;
            }else
            {
                return nums[index0--];
            }
        }else if (stackNum==1)
        {
            if (index1==size)//空了
            {
                return -1;
            }else
            {
                return nums[index1--];
            }
        }else
        {
            if (index2==size*2)//空了
            {
                return -1;
            }else
            {
                return nums[index2--];
            }
        }
    }
    
    int peek(int stackNum) {
        if (stackNum==0)
        {
            if (index0==0)//空了
            {
                return -1;
            }else
            {
                return nums[index0];
            }
        }else if (stackNum==1)
        {
            if (index1==size)//空了
            {
                return -1;
            }else
            {
                return nums[index1];
            }
        }else
        {
            if (index2==size*2)//空了
            {
                return -1;
            }else
            {
                return nums[index2];
            }
        }
    }
    
    bool isEmpty(int stackNum) {
        if (stackNum==0)
        {
            return index0==0;
        }else if (stackNum==1)
        {
            return index1==size;
        }else
        {
            return index2==size*2;
        }
    }
};