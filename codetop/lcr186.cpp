// 展览馆展出来自 13 个朝代的文物，每排展柜展出 5 个文物。某排文物的摆放情况记录于数组 places，
// 其中 places[i] 表示处于第 i 位文物的所属朝代编号。其中，编号为 0 的朝代表示未知朝代。
// 请判断并返回这排文物的所属朝代编号是否连续（如遇未知朝代可算作连续情况）。

// 输入: places = [0, 6, 9, 0, 7]
// 输出: True
// 输入: places = [7, 8, 9, 10, 11]
// 输出: True

//斗地主？？
// 第一：只有五个数
// 第二：如果五个数是连续的 比如：1 2 3 4 5 返回true
// 第三：重复的即使连续也要返回false 比如：1 1 2 3 4
// 第四：0可以代替任何数：比如0 0 0 1 5也是返回true 因为可以变成 1 2 3 4 5

#include<iostream>
#include<vector>
#include<set>
using namespace std;

//保存0外最大值，最小值
//除了0以外有重复，直接false
//没重复，最大-最小<=5
bool checkDynasty(vector<int>& places) {
    int min_v = -1;
    int max_v = -1;
    for (int i = 0; i < places.size(); i++)
    {
        if (places[i]!=0)
        {
            min_v = places[i];
            max_v = places[i];
            break;
        }
    }
    if(min_v==-1 && max_v==-1){//全是0
        return true;
    }
    set<int> st;
    for(auto it: places){
        if (it==0)
        {
            continue;
        }else
        {
            if (st.find(it)!=st.end())
            {
                cout << "dup" << endl;
                return false;
            }else
            {
                st.insert(it);
                if (it>max_v)
                {
                    max_v = it;
                }
                if(it<min_v){
                    min_v = it;
                }
            }
        }
    }
    cout << max_v << " " << min_v;
    return max_v-min_v <=5;
}

int main(){
    vector<int> a = {0, 6, 9, 0, 7};
    if(checkDynasty(a)){
        cout << "t";
    }else
    {
        cout << "f";
    }
    return 0;
}