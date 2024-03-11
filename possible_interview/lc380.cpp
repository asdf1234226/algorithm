// 实现RandomizedSet 类：
// RandomizedSet() 初始化 RandomizedSet 对象
// bool insert(int val) 当元素 val 不存在时，向集合中插入该项，并返回 true ；否则，返回 false 。
// bool remove(int val) 当元素 val 存在时，从集合中移除该项，并返回 true ；否则，返回 false 。
// int getRandom() 随机返回现有集合中的一项（测试用例保证调用此方法时集合中至少存在一个元素）。每个元素应该有 相同的概率 被返回。
// 你必须实现类的所有函数，并满足每个函数的 平均 时间复杂度为 O(1) 。
// ["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
// [[], [1], [2], [2], [], [1], [2], []]
// 输出
// [null, true, false, true, 2, true, false, 2]

#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

// map保证insert和remove的O(1),key是值，value是下标
// 随机查找的O(1)用vector实现
//删除某个元素，如果存在，vector中需要对val对应的下标和最后一个元素交换，然后删除最后一个元素

class RandomizedSet {
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()){
            return false;
        }
        nums.push_back(val);
        mp[val]=nums.size()-1;
        return true;
    }

//首先获取nums的最后一个元素，并将其在mp中的索引更新为要删除元素的索引，
//然后再进行交换和删除操作。保证mp中索引的正确性
    bool remove(int val) {
        if (mp.find(val)==mp.end()){
            return false;
        }
        //更新最后一个元素的索引
        int last = nums.back();
        mp[last]=mp[val];
        //交换要删除的和最后一个元素
        swap(nums[mp[val]], nums[nums.size()-1]);
        nums.pop_back();
        mp.erase(val);
        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }

private:
    vector<int> nums;
    map<int, int> mp;
};

int main(){
    return 0;
}