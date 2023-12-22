//
// Created by SP on 2023/12/21.
//

// 你是产品经理，目前正在带领一个团队开发新的产品。不幸的是，你的产品的最新版本没有
//通过质量检测。由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的。
// 假设你有 n 个版本 [1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。
// 你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version 是否在单元
//测试中出错。实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。


// 示例 1：

// 输入：n = 5, bad = 4
// 输出：4
// 解释：
// 调用 isBadVersion(3) -> false
// 调用 isBadVersion(5) -> true
// 调用 isBadVersion(4) -> true
// 所以，4 是第一个错误的版本。

//前段满足false，后半段满足true
int firstBadVersion(int n) {
    int l = 1;
    int r = n;
    while (l<r)
    {
        int mid = (l+r+1)>>1;
        if(!isBadVersion(mid)){//满足条件的在左边，分段的点就在右边，就要移动l缩小到右边查找
            l=mid;
        }else
        {
            r=mid-1;
        }
    }
    return l;

}
//顺带看下287 原地hash k神的题解