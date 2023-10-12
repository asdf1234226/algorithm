#include<iostream>
#include<vector>
using namespace std;

const int N = 1010;
int A[N][N], B[N][N];
int q[4][4];

//(x1,y1) (x2,y2)为顶点的矩形区域+c
void insert(int x1, int y1, int x2, int y2, int c)
{//右下角
    B[x1][y1]+=c;
    B[x2+1][y1]-=c;
    B[x1][y2+1]-=c;
    B[x2+1][y2+1]+=c;
}

void diff(vector<vector<int>>& add)
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            insert(i,j,i,j,q[i-1][j-1]);
        }  
    }
    for(auto it: add)
    {
        int x1 =it[0], y1=it[1], x2=it[2],y2=it[3],c=it[4];
        insert(x1,y1,x2,y2,c);
    }
    for (int i = 1; i <= 4; i++)
    {
        for(int j=1;j<=4;j++){
            A[i][j]=A[i][j-1]+A[i-1][j]-A[i-1][j-1]+B[i][j];
            q[i-1][j-1]=A[i][j];
        }
    }
    
    
}


int main()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            q[i][j] = i*4+j;
            cout << q[i][j] << " ";
        }
        cout << endl;
    }
    vector<vector<int>> add;
    vector<int> add1= {1,1,2,2,2};
    vector<int> add2= {3,3,4,4,1};
    add.push_back(add1);
    add.push_back(add2);
    diff(add);
    cout << "after add" << endl;
    for (int i = 0; i < 4; i++)
    {
        for(int j =0; j<4;j++)
        {
            cout << q[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

