//
// Created by SP on 2023/11/7.
//

//candidates 中的 同一个 数字可以 无限制重复被选取
//输入：candidates = [2,3,6,7], target = 7
//输出：[[2,2,3],[7]]

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    //要去重的是同一树层上的“使用过”，同一树枝上的都是一个组合里的元素，不用去重。

}