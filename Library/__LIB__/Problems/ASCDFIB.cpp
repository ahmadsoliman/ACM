#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <functional>

using namespace std;
#define MOD 100000

int fib[1100005], nums[1000005];

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(){
    int t, a,b, i,j,k, kase=1;

    fib[1]=0; fib[2]=1;
    for(i=3; i<1100005; i++) { fib[i]=fib[i-1]+fib[i-2]; if(fib[i]>=MOD) fib[i]-=MOD; }

    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &a, &b);

        priority_queue<int, vector<int>, greater<int> > pq(fib+a, fib+a+b+1);

        k = ((100<b+1)?100:b+1);
        printf("Case %d:", kase++);
        for(i=0; i<k; i++) { printf(" %d", pq.top()); pq.pop(); }
        printf("\n");
    }
    return 0;
}
