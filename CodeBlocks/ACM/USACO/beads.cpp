/*
ID: ahmadad1
PROG: beads
LANG: C++
*/
#include <string>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

char in[1000];
/*
77
rwrwrwrwrwrwrwrwrwrwrwrwbwrwbwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwr
*/
int main() {
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);

    int n, i,j,k, maxv;

    scanf("%d", &n);
    scanf("%s", in);
    strncat(in, in, n);

    maxv=0;
    for(i=0; i<n; i++){
        j=i;
        char c=in[j];
        if(c=='w') while(j<i+n && in[j]=='w') j++;
        c=in[j];
        j=i;
        while(j<i+n && (in[j]==c||in[j]=='w')) j++;

        k=i+n-1;
        c=in[k];
        if(c=='w') while(k>j && in[k]=='w') k--;
        c=in[k];
        k=i+n-1;
        while(k>=j && (in[k]==c||in[k]=='w')) k--;

        maxv=max(maxv, j-i+i+n-k-1);
    }
    printf("%d\n", maxv);

    return 0;
}
