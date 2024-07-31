// 给你一个字符串 path ，表示指向某一文件或目录的 Unix 风格 绝对路径 （以 '/' 开头），请你将其转化为更加简洁的规范路径。
// 在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。任意多个连续的斜杠（即，'//'）都被视为单个斜杠 '/' 。 对于此问题，任何其他格式的点（例如，'...'）均被视为文件/目录名称。
// 请注意，返回的 规范路径 必须遵循下述格式：
// 始终以斜杠 '/' 开头。
// 两个目录名之间必须只有一个斜杠 '/' 。
// 最后一个目录名（如果存在）不能 以 '/' 结尾。
// 此外，路径仅包含从根目录到目标文件或目录的路径上的目录（即，不含 '.' 或 '..'）。
// 返回简化后得到的 规范路径 。
// path 由英文字母，数字，'.'，'/' 或 '_' 组成

// 示例 1：
// 输入：path = "/home/"
// 输出："/home"
// 解释：注意，最后一个目录名后面没有斜杠。 
// 示例 2：
// 输入：path = "/../"
// 输出："/"
// 解释：从根目录向上一级是不可行的，因为根目录是你可以到达的最高级。
// 示例 3：
// 输入：path = "/home//foo/"
// 输出："/home/foo"
// 解释：在规范路径中，多个连续斜杠需要用一个斜杠替换。
// 示例 4：
// 输入：path = "/a/./b/../../c/"
// 输出："/c"


#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//"."和"/"不做处理，字母或者单词入栈，".."上一级弹出栈顶元素（如果有的话），然后拼接
//special handle case  
// 输入 "/.../a/../b/c/../d/./"  输出"/.../b/d"


string simplifyPath(string path) {
	stack<string> st;
	int n = path.size();
    // 用'/'作为分隔符，放在split_path中
    vector<string> split_path;
    //path[0]='/';
    int start = 0;
    while(start<n){
        if(path[start]=='/'){
            int ed = start+1;
            while(ed<n&&path[ed]!='/'){
                ed++;
            }
            if(ed!=start+1){//确保不是连续的'/'
                split_path.push_back(path.substr(start+1, (ed-1)-(start+1)+1));
            }
            start=ed;
        }else{
            start++;
        }   
    }
    for(auto it: split_path){
        if(it == ".") continue;
        if(it == ".."){
            if(!st.empty()){
                st.pop();
            }
        }else
        {
            st.push(it);
        }
    }
    if(st.empty()) return "/";//special handle
    //栈的顺序是反的，需要反转
    stack<string> reverse_st;
    while (!st.empty())
    {
        reverse_st.push(st.top());
        st.pop();
    }
    string ans = "";
    while (!reverse_st.empty()) {
        ans += "/" + reverse_st.top();
        reverse_st.pop();
    }
    return ans;
}

int main(){
    cout << simplifyPath("/home/user/Documents/../Pictures");
    return 0;
}