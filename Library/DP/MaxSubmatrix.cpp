#include <iostream>
#include <climits>

using namespace std;

int a[101][101];


#define MIN -2000000000
int columnSum[105];
int kadane2D(int R, int C){
    int s=MIN,S=MIN,t, row, x, i;
    for(row = 0; row<R; row++) {
        for(i=0; i<C; i++) columnSum[i] = 0;
        for(x = row; x<R; x++) {
            s = MIN;
            t = 0;
            for(i=0; i<C; i++) {
                columnSum[i]+=a[x][i];
                t+=columnSum[i];
                if(t>s) s = t;
                if(t<0) t = 0;
            }
            if(s>S) S = s;
        }
    }
    return S;
}

int main( void )
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<kadane2D(n)<<endl;
    return 0;
}
