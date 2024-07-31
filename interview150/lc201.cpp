#include<iostream>
using namespace std;

int rangeBitwiseAnd(int left, int right){
	int ans = 0;
	unsigned int a = 1<<31;
	for(int i=0;i<32;i++){
		if((left&a)==(right&a)){
            int tmp = left&a;
			ans += tmp;
            cout << left << " " << a << " " << tmp << endl;
		}else{
			break;
		}
		a>>=1;
	}
	return ans;
}

int main(){
    cout << rangeBitwiseAnd(2,2);
    return 0;
}