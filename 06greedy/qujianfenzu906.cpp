#include <iostream>
#include <algorithm>  
using namespace std;   
const int N = 100100;   
int n;  
int b[2 * N], idx; 
int main()  
{      	
    scanf ("%d", &n);      	
    for(int i = 0; i < n; i ++)      	
    {          		
        int l, r;          		
        scanf("%d %d", &l, &r);          		
        b[idx ++] = l * 2; //标记左端点为偶数。          		
        b[idx ++] = r * 2 + 1;// 标记右端点为奇数。      	
    }       	
    sort(b, b + idx);       	
    int res = 1, t = 0;      	
    for(int i = 0; i < idx; i ++)      	
    {          		
        if(b[i] % 2 == 0) t ++;          			
        else t --;          			
        res = max(res, t);     	
    }	 	
    printf ("%d\n", res);      	
    return 0;  
}