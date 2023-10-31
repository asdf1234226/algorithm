#include<iostream>
using namespace std;

//注意优先级，&优先级比 != 低，所以要加括号
int hanmin_dist(int x, int y){
    int ans =0;
    for (int i = 0; i < 32; i++)
    {
        if ((x&1)!=(y&1))
        {
            //cout << (x&1) << ":" << (y&1) <<endl;
            ans++;
        }
        x>>=1;
        y>>=1;
    }
    return ans;
    
}

int main(){
    cout << hanmin_dist(1,4);
    return 0;
}