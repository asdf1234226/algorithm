#include <cstdlib> // for rand() and srand()
#include<iostream>
#include <ctime>   // for time()
#include <set>
using namespace std;

int main(){
    set<int> st;
    auto result = st.insert(4);
    if (result.second)
    {
        cout << "insert success";
    }
    auto result2 = st.insert(4);
    if(!result2.second){
        cout << " 1";
    }else
    {
        cout << " 2";
    }
    return 0;
}