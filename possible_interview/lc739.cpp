// 其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后
// 输入: temperatures = [73,74,75,71,69,72,76,73]
// 输出: [1,1,4,2,1,1,0,0]


#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//单调栈，找x右边第一个比x大的元素
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
	vector<int> res(n,0);
	stack<int> st;
	for(int i=0;i<n;i++){
		while(!st.empty()&& temperatures[st.top()]<temperatures[i]){
			res[st.top()]=i-st.top();
			st.pop();
		}
        st.push(i);//TODO 这个要记得
	}
	return res;
}

int main(){
    vector<int> a = {73,74,75,71,69,72,76,73};
    vector<int> res = dailyTemperatures(a);
    for(int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }
    return 0;
}