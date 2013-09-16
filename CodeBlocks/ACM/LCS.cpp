#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX_N 500010
char T[MAX_N], b[250010];
int n;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N], I[MAX_N], LCP[MAX_N];
int c[MAX_N];

void countingSort(int k) {
    int i, sum, maxi = 26;
    // up to 255 ASCII chars or length of n
    memset(c, 0, sizeof c);
    // clear frequency table
    for (i = 0; i < n; i++)
        // count the frequency of each rank
        c[i + k < n ? RA[i + k] : 0]++;
    for (i = sum = 0; i < maxi; i++) {
        int t = c[i]; c[i] = sum; sum += t;
    }
    for (i = 0; i < n; i++)
        // shuffle the suffix array if necessary
        tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
    for (i = 0; i < n; i++)
        // update the suffix array SA
        SA[i] = tempSA[i];
}

void constructSA() {
    // this version can go up to 100000 characters
    int i, k, r;
    for (i = 0; i < n; i++) { RA[i] = T[i]-'a'; SA[i] = i; }
    // initial rankings
    for (k = 1; k < n; k <<= 1) {
        // repeat sorting process log n times
        countingSort(k);
        // actually radix sort: sort based on the second item
        countingSort(0);
        // then (stable) sort based on the first item
        tempRA[SA[0]] = r = 0;
        // re-ranking; start from rank r = 0
        for (i = 1; i < n; i++)
        // compare adjacent suffixes
        tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;

        // if same pair => same rank r; otherwise, increase r
        for (i = 0; i < n; i++)
            // update the rank array RA
            RA[i] = tempRA[i];
    }
}

void computeLCP() {
	// build inverse suffix array I:
	int i;
	for (i = 0; i < n; i++) I[SA[i]] = i;

	// build LCP:
	int h = 0; LCP[0] = 0;
	for (int i = 0; i < n; i++) {
	    if (I[i] != 0) {
           while (T[i+h] == T[SA[I[i]-1]+h]) h++;
        	LCP[I[i]] = h--;
        	if (h < 0) h = 0;
         }
    }
}

int main() {
    int n, i, l1, lcs=-1;

    gets(T);
    gets(b);

    l1 = strlen(T);
    strcat(T, ".");
    strcat(T, b);

    n = strlen(T);
    constructSA();
   //computeLCP();

    for(i=0; i<n; i++) printf("%d\n", SA[i]);

    //for(i=1; i<n; i++) if(LCP[i]>lcs && ((SA[i]>=l1&&SA[i-1]<l1) || (SA[i-1]>=l1&&SA[i]<l1))) lcs=LCP[i];
    printf("%d\n", lcs);

    return 0;
}
