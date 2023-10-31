#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int getMost(vector<int>& num){
    int n = num.size();
    unordered_map<int, int> map_count;
    for (int i = 0; i < n; i++)
    {
        auto it = map_count.find(num[i]);
        if (it!=map_count.end())
        {
            if (it->second>=n/2)
            {
                return it->first;
            }
            it->second+=1;
        }
        else
        {
            map_count.insert({num[i],1});
        }
    }   
}


int main(){
    vector<int> a = {2,2,4,5,2};
    cout << getMost(a);
    return 0;
}