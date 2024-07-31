// 示例 1：
// 输入：strs = ["flower","flow","flight"]
// 输出："fl"
// 示例 2：
// 输入：strs = ["dog","racecar","car"]
// 输出：""
// 解释：输入不存在公共前缀。

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
	string ans = "";
	int n = strs.size();
	if(n==1) return strs[0];
	int start = 0;
	int minLen = INT_MAX;
	for(int i=0;i<strs.size();i++){
		minLen=min(minLen, static_cast<int>(strs[i].size()));
	}
	while(start<minLen){
		for(int i=1;i<n;i++){
			if(strs[i][start]==strs[0][start]){
				if(i==n-1){
					ans+=strs[0][start];
					start++;
				}
			}else{
				return ans;//不能用break
			}
		}
	}
	return ans;
}

int main(){
    vector<string> a = {"flower","flow","flight"};
    cout << longestCommonPrefix(a);
    return 0;
}