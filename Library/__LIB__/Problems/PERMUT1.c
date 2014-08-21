/*

Let A = [a1,a2,...,an] be a permutation of integers 1,2,...,n. A pair of indices (i,j), 1<=i<=j<=n, is an inversion of the permutation A if ai>aj. We are given integers n>0 and k>=0. What is the number of n-element permutations containing exactly k inversions?

*/

#include <stdio.h>
#include <string.h>

int cnt[16][128];

void calc() {
	int i, j, k;
	cnt[1][0] = 1;
	for(i=1; i<12; i++) {
		for(j=0; cnt[i][j]; j++) {
			for(k=j; k<=i+j; k++) {
				cnt[i+1][k] += cnt[i][j];
			}
		}
	}
}

int main(){
    int t,n,k;
    scanf("%d", &t);
    calc();
    while(t--){
        scanf("%d %d", &n,&k);
        printf("%d\n", cnt[n][k]);
    }
    return 0;
}


