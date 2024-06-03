// num1 = "123", num2 = "456"
// 输出"56088"

#include<iostream>
#include<vector>
using namespace std;

//    1  2  3
//       5  6
//    -------
//    6 12 18
// 5 10 15
//-----------
// m位 * n 位的长度不会超过 m+n (9*9=81不会是3位数)
string multiply(string num1, string num2){
    int m = num1.size();
    int n = num2.size();
    vector<int> res(m+n, 0);
    for (int i = m-1; i>=0;i--)
    {
        for (int j = n-1; j>=0; j--)
        {
            res[i+j+1] += (num1[i]-'0')*(num2[j]-'0');
        }
    }
    for(int i=0;i<m+n;i++){
        cout << res[i] << " ";
    }
    cout << endl;
    int add = 0;
    for (int i = m+n-1; i >=0&&(add>0 || res[i]>0); i--)
    {
        int tmp = res[i]+add;
        res[i]=tmp%10;
        add=tmp/10;
    }
    for(int i=0;i<m+n;i++){
        cout << res[i] << " ";
    }
    cout << endl;
    int index = 0;
    while(res[index]==0){
        index++;
    }
    string ans = "";
    for (int i = index; i <= m+n-1; i++)
    {
        ans=ans+to_string(res[i]);
    }
    return ans;
}

int main(){
    cout << multiply("123", "56");
    return 0;
}
