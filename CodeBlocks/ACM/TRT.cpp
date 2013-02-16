#include <stdio.h>
#include <cstdlib>

int treats[3000];
int dp[2001][2001][2001];
int N;

int treat(int i, int j, int age){
	if(i>j)
		return 0;
	if(dp[i][j][age]>-1)
		return dp[i][j][age];

	if(i==j)
		return treats[i] * age;

	int a,b;
	a = treat(i,j-1,age+1);
	b = treat(i+1,j,age+1);

    if(a>b)
    	return dp[i][j][age] = age*treats[j]+a;
     else
       	return dp[i][j][age] = age*treats[i]+b;    	
}

int main(int argc, char **argv) {
	int n, i,j,k;
	scanf("%d",&n);

	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
       		for(k=0; k<n; k++){
         		dp[i][j][k] = -1;
             }
		}
	}

	N = n;
	for(i=0; i<n; i++){
		scanf("%d",&treats[i]);
	}

	printf("%d",treat(0,n-1,1));
	
    system("PAUSE");
    return EXIT_SUCCESS;
}

