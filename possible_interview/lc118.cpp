// 输入: numRows = 5
// 输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
//1
//1 1
//1 2 1
//1 3 3 1 
#include<iostream>
#include<vector>
using namespace std;  
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    if(numRows==0) return res;
    res.push_back({1});
    for(int i =1;i<numRows;i++){
        vector<int> row(i+1,1);
        for(int j=1;j<i;j++){
            row[j]=res[i-1][j]+res[i-1][j-1];
        }
        res.push_back(row);
    }
    return res;
}

int main(){
    vector<vector<int>> a = generate(5);
    for(auto it : a){
        for(auto it1: it){
            cout << it1 << " ";
        }
        cout << endl;
    }
    return 0;
}