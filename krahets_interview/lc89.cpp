//
// Created by SP on 2023/12/14.
//

// n 位格雷码序列 是一个由 2n 个整数组成的序列，其中：
// 每个整数都在范围 [0, 2n - 1] 内（含 0 和 2n - 1）
// 第一个整数是 0
// 一个整数在序列中出现 不超过一次
// 每对 相邻 整数的二进制表示 恰好一位不同 ，且
//         第一个 和 最后一个 整数的二进制表示 恰好一位不同
// 给你一个整数 n ，返回任一有效的 n 位格雷码序列

// 输入：n = 2
// 输出：[0,1,3,2]
// 解释：
// [0,1,3,2] 的二进制表示是 [00,01,11,10] 。
// - 00 和 01 有一位不同
// - 01 和 11 有一位不同
// - 11 和 10 有一位不同
// - 10 和 00 有一位不同
// [0,2,3,1] 也是一个有效的格雷码序列，其二进制表示是 [00,10,11,01] 。
// - 00 和 10 有一位不同
// - 10 和 11 有一位不同
// - 11 和 01 有一位不同
// - 01 和 00 有一位不同

#include<iostream>
#include<vector>
using namespace std;

// 00
// 01
// 11
// 10

//n=2的集合每个元素前面+0得到集合a
// 000
// 001
// 011
// 010
// 每个元素前面+1得到集合b
// 100
// 101
// 111
// 110
//找规律，只要将b的顺序翻转一下接到a后面就可以

int pow_two(int n){
        return 1<<n;
}

vector<int> grayCode(int n) {
        if (n==1)
        {
                return vector<int>{0,1};
        }
        vector<int> a = grayCode(n-1);
        vector<int> res;
        for (int i = 0; i < a.size(); i++)
        {
                res.push_back(a[i]);
        }
        for (int i = a.size()-1; i >= 0; i--)
        {
                res.push_back(a[i]+pow_two(n-1));       
        }
        return res;
}

int main(){
        vector<int> a = grayCode(3);
        for(auto i: a){
                cout << i << " ";
        }
        return 0;
}