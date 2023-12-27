//
// Created by SP on 2023/12/14.
//

// n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。
// 你需要按照以下要求，给这些孩子分发糖果：
// 每个孩子至少分配到 1 个糖果。
// 相邻两个孩子评分更高的孩子会获得更多的糖果。
// 请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。


// 示例 1：

// 输入：ratings = [1,0,2]
// 输出：5
// 解释：你可以分别给第一个、第二个、第三个孩子分发 2、1、2 颗糖果。
// 示例 2：

// 输入：ratings = [1,2,2]
// 输出：4
// 解释：你可以分别给第一个、第二个、第三个孩子分发 1、2、1 颗糖果。
// 第三个孩子只得到 1 颗糖果，这满足题面中的两个条件。

#include<iostream>
#include<vector>
using namespace std;

//假设孩子 A, B(A在左边)
//需要满足  规则1. ratingB>ratingA时,B的糖比A的多
//         规则2. ratingA>ratingB时，A的糖比B的多

//问题转换为所有学生同时满足规则1和规则2的最少糖果
// 先从左至右遍历学生成绩 `ratings`，按照以下规则给糖，并记录在 `left` 中： 满足规则1
//        1. 先给所有学生 $1$ 颗糖；      
//        2. 若 ratings_i>ratings_i-1，则第 i 名学生糖比第 i - 1 名学生多 1 个。      
//        3. 若 ratings_i<=ratings_i-1，则第 i 名学生糖数量不变。（交由从右向左遍历时处理。）
// 同理，在此规则下从右至左遍历学生成绩并记录在 `right` 中， 满足规则2
//  最终，取以上 $2$ 轮遍历 `left` 和 `right` 对应学生糖果数的 最大值
int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> left(n,1);
    vector<int> right(n,1);
    for (int i = 1; i < n; i++)//满足规则1
    {
        if (ratings[i]>ratings[i-1])
        {
            left[i]=left[i-1]+1;
        }
    }
    for(int i = n-2;i>=0;i--){//满足规则2
        if(ratings[i]>ratings[i+1]){
            right[i]=right[i+1]+1;
        }
    }
    int count = 0;
    for(int i=0;i<n;i++){//同时满足要取交集
        count+=max(left[i], right[i]);
    }
    return count;
}

int main(){
    vector<int> a = {1,2,2};
    cout << candy(a);
    return 0;
}