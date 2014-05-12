/*
ID: ahmadad1
PROG: palsquare
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

using namespace std;

typedef vector<int> vi;

vi convert(int n, int b){
    vi r;
    while(n>0) r.push_back(n%b), n/=b;
    reverse(r.begin(), r.end());
    return r;
}

int isPalin(vi v){
    for(int i=0; i<v.size(); i++) if(v[i]!=v[v.size()-1-i]) return 0;
    return 1;
}

int main() {
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);

    int b, i,j;

    scanf("%d", &b);

    for(j=1; j<=300; j++){
        vi numb, numnumb=convert(j*j, b);
        if(isPalin(numnumb)) {
            numb=convert(j, b);

            for(i=0; i<numb.size(); i++) {
                if(numb[i]<10) printf("%d", numb[i]);
                else printf("%c", (char)('A'+(numb[i]-10)));
            }
            printf(" ");
            for(i=0; i<numnumb.size(); i++) {
                if(numnumb[i]<10) printf("%d", numnumb[i]);
                else printf("%c", (char)('A'+(numnumb[i]-10)));
            }
            printf("\n");
        }
    }

    return 0;
}
