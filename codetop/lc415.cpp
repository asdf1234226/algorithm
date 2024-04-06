//给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。
//你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。
//
//示例 1：
//输入：num1 = "11", num2 = "123"
//输出："134"
//示例 2：
//输入：num1 = "456", num2 = "77"
//输出："533"

#include <iostream>
#include <algorithm>
using namespace std;

string addStrings(string num1, string num2){
	int m = num1.size();
	int n = num2.size();
	int i = m-1,j=n-1;
	string ans;
	int add = 0;
	while(i>=0|| j>=0){
		int a = i>=0?num1[i]-'0':0;
		int b = j>=0?num2[j]-'0':0;
		int num = a+b+add;
		add=num/10;
		ans+=to_string(num%10);
		i--;
		j--;
	}
	if(add){
		ans+=to_string(add);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main(){
    cout << addStrings("456","77");
    return 0;
}