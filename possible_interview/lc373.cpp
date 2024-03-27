// 给定两个以 非递减顺序排列 的整数数组 nums1 和 nums2 , 以及一个整数 k 。
// 定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2 。
// 请找到和最小的 k 个数对 (u1,v1),  (u2,v2)  ...  (uk,vk) 。
 
// 示例 1:
// 输入: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
// 输出: [1,2],[1,4],[1,6]
// 解释: 返回序列中的前 3 对数：
//      [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
	 
// 输入: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
// 输出: [1,1],[1,1]
// 解释: 返回序列中的前 2 对数：
//      [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef pair<int,int> PII;

//假设nums1[x],nums2[y]是第k小的对数，第k+1小的对数，只会是下面二者之一{nums1[x+1], nums2[y]}或{nums1[x], nums2[y+1]}
//小顶堆来存放，{nums1[x]+nums2[y],x,y},为了避免重复添加，需要用set记录（x,y）
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<vector<int>> ans;
    if(nums1.size()==0 || nums2.size()==0) return ans;
    //默认是大顶堆，这里要声明为小顶堆
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({nums1[0]+nums2[0],0,0});
    set<PII> st;
    st.insert({0,0});
    while(!pq.empty()&&k>0){
        auto a = pq.top();
        ans.push_back({nums1[a[1]], nums2[a[2]]});
        pq.pop();
        k--;
        int nx=a[1]+1;
        int ny=a[2];
        if(nx<nums1.size()&&st.find({nx,ny})==st.end()){
            pq.push({nums1[nx]+nums2[ny],nx,ny});
            st.insert({nx,ny});
        }
        nx=a[1];
        ny=a[2]+1;
        if(ny<nums2.size()&&st.find({nx,ny})==st.end()){
            pq.push({nums1[nx]+nums2[ny],nx,ny});
            st.insert({nx,ny});
        }
    }
    return ans;
}

int main(){
    return 0;
}