// 1 <= s.length <= 3 * 105
// s 由数字、'+'、'-'、'('、')'、和 ' ' 组成
// s 表示一个有效的表达式
// '+' 不能用作一元运算(例如， "+1" 和 "+(2 + 3)" 无效)
// '-' 可以用作一元运算(即 "-1" 和 "-(2 + 3)" 是有效的)
// 输入中不存在两个连续的操作符
// 每个数字和运行的计算将适合于一个有符号的 32位 整数

// 输入：s = "(1+(4+5+2)-3)+(6+8)"
// 输出：23

#include<iostream>
#include<stack>
using namespace std;

// ops 存放操作
// nums 存放数字
// s[i] = ( 加入ops
// s[i] = )  使用num和ops计算，直到遇到最近的(，结果放在nums
// s[i] = 数字  要计算
// s[i] = +   将栈内可以算的计算，加入ops
// s[i] = -
// s[i] = ' ' continue

void calc(stack<int>& nums, stack<char>& ops){
    if (nums.size()<2||ops.empty())
    {
        return;
    }
    int a = nums.top();
    nums.pop();
    int b = nums.top();
    nums.pop();
    char op = ops.top();
    ops.pop();
    nums.push(op=='+'?a+b:b-a);//b-a而不是a-b，后入栈的要被先入栈的减去
}

string trim_str(string s){
    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]==' ')
        {
            continue;
        }else
        {
            res+=s[i];
        }
    }
    return res;
}
int calculate(string s) {
    s=trim_str(s);
    int res = 0;
    stack<int> nums;
    stack<char> ops;
    nums.push(0);//第一个数可能是负数，如-3,往nums添加0可以避免边界计算
    for(int i=0;i<s.size();i++){
        char c = s[i];
        if(c=='('){
            ops.push(c);
        }else if (c==')')
        {
            while (!ops.empty())
            {
                char op = ops.top();
                if(op=='('){
                    ops.pop();
                    break;
                }else
                {
                    calc(nums,ops);
                }
            }
        }else if(c>='0'&&c<='9'){
            int number = 0;
            while(i<s.size() && s[i]>='0' && s[i]<='9') {
                number = number*10 + s[i] - '0';
                i++;
            }
            nums.push(number);
            number = 0;
            i--;  // 因为外层循环还会再执行一次i++，所以这里需要i--
        }else{//'+' or '-'
            if (i>0&&s[i-1]=='(')
            {
                nums.push(0);
            }
            //将栈内可以计算的计算  5+3-2
            while (!ops.empty() && ops.top()!='(')
            {
                calc(nums,ops);
            }
            ops.push(c);  
        }
    }
    while(!ops.empty())
    {
        calc(nums,ops);
    }
    return nums.top();
}

int main(){
    //cout << calculate("(1+(4+5+2)-3)+(6+8)");
    cout << calculate("1-(     -2)");
    return 0;
}