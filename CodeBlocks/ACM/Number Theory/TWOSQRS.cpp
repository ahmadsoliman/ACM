#include <stdio.h>
#include <math.h>
#include <stdlib.h>

unsigned int root(unsigned int x){
    unsigned int a,b;
    b = x;
    a = x = 0x3f;
    x = b/x;
    a = x = (x+a)>>1;
    x = b/x;
    a = x = (x+a)>>1;
    x = b/x;
    x = (x+a)>>1;
    return(x); 
}

int main2aa()
{
    int t ,i,j, sqrtV, entered, rest;
    scanf("%d", &t);
	
	
	long long len = 10000LL;
    int *pData = (int *)calloc(12, sizeof(int));
	for (j = 0; j <= 1000000; j++) {
		pData[j*j] = 1;
	}
	
	long long inI = 0LL, k = 0LL;;
		
	for(i =0; i<t; i++){
        scanf("%lld", &inI);
    	sqrtV = (int) sqrt(inI);
		
		if(sqrtV*sqrtV==inI){
			printf("Yes\n");
			continue;
		}
        		
		entered = 0;
		for (j = 1; j <= sqrtV; j++) {
			rest = root(inI - j*j;
			if(){
                entered = 1;
                break;
            }
		}
		if (entered) {
			printf("Yes\n");
		}else{
			printf("No\n");
		}
    }
}
