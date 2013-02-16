#include <stdlib.h>
#include <stdio.h>

int dp1[60000001];

long long recur(int coins){
     if(coins<2){
       return coins;
     }
	int a = coins/2, b = coins/3, c = coins/4;
    long long x=0ll, y=0ll, z=0ll;
	if(a>60000001)
        x = recur(a);
    else if(dp1[a]==0)
		x = dp1[a] = (int)recur(a);
	else
	    x = dp1[a];
	if(b>60000001)
        y = recur(b);
    else if(dp1[b]==0)
		y = dp1[b] = (int)recur(b);
	else
	    y = dp1[b];
	if(c>60000001)
        z = recur(c);
    else if(dp1[c]==0)
		z = dp1[c] = (int)recur(c);
	else
	    z = dp1[c];
        	
	long long d = 0ll;
	d = x + y + z;
	if(d>coins)
         return d;
	return coins;     
}

int main()
{  
     int in;
     while (scanf("%d",&in)==1){
           printf("%lld\n", recur(in));
     }
    system("PAUSE");
    return EXIT_SUCCESS;
}
