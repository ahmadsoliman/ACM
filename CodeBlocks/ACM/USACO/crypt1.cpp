/*
ID: ahmadad1
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int nums[100];

int found[15];

int main() {
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);

    int n, i,j,k,l,r,f, a,b, pp1,pp2, pr, tpp1,tpp2, tpr, dig, cnt=0;

    scanf("%d", &n);
    memset(found, 0, sizeof found);
    for(i=0; i<n; i++) scanf("%d", &nums[i]), found[nums[i]]=1;

    for(i=0; i<n; i++){
    for(j=0; j<n; j++){
    for(k=0; k<n; k++){
    for(l=0; l<n; l++){
    for(r=0; r<n; r++){
        a=nums[i]*100+nums[j]*10+nums[k];
        b=nums[l]*10+nums[r];

        tpp1=pp1=nums[l]*a;
        tpp2=pp2=nums[r]*a;

        tpr=pr=a*b;

        f=1;

        dig=0;
        while(tpp1>0) {if(!found[tpp1%10]) {f=0; break;} tpp1/=10; dig++; }
        if(!f || dig!=3) continue;

        dig=0;
        while(tpp2>0) {if(!found[tpp2%10]) {f=0; break;} tpp2/=10; dig++; }
        if(!f || dig!=3) continue;

        dig=0;
        while(tpr>0) {if(!found[tpr%10]) {f=0; break;} tpr/=10; dig++; }
        if(!f || dig!=4) continue;

        cnt++;
    }}}}}
   // printf("%d %d %d %d %d\n", (*s.begin()).a, (*s.begin()).b, (*s.begin()).pp1, (*s.begin()).pp2, (*s.begin()).pr);
    printf("%d\n", cnt);
    return 0;
}

