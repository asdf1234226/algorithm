//
// Created by SP on 2023/11/5.
//

#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;


int trap(vector<int>& height) {
    int n = height.size();
    if (n<=2){
        return 0;
    }
    int ans =0;
    stack<int> st;
    st.push(0);
    for (int i = 0; i < n; ++i) {
        if (height[i]<height[st.top()]){
            st.push(i);
        } else if (height[i]==height[st.top()]){
            st.pop();
            st.push(i);
        } else{//height[i]>栈顶
            while (!st.empty() && height[i]>height[st.top()]){
                int mid = st.top();
                st.pop();
                if (!st.empty()){
                    int h = min(height[st.top()], height[i]) - height[mid];
                    int w = i-st.top()-1;
                    ans+=h*w;
                }
            }
            st.push(i);
        }
    }
    return ans;
}

int main(){
    vector<int> a ={0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(a);
    return 0;
}