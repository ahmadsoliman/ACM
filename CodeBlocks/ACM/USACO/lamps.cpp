/*j ID: ahmadad1
PROG: lamps
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
#include <math.h>
#include <bitset>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

set<vector<int> > res;

int n, c, finals[105];

void check(vector<int> s, int num){
    if(num<=c && num%2==c%2){
        int f=1;
        for(int i=0; i<n; i++){
            if(!(finals[i]==-1 || finals[i]==s[i])) { f=0; break; }
        }
        if(f) res.insert(s);
    }
}

int main() {
    freopen("lamps.in", "r", stdin);
    freopen("lamps.out", "w", stdout);

    int i,j,k,r,l,q;

    scanf("%d", &n);
    scanf("%d", &c);

    memset(finals, -1, sizeof finals);

    while(1) {
        scanf("%d", &k);
        if(k==-1) break;
        finals[k-1]=1;
    }
    while(1) {
        scanf("%d", &k);
        if(k==-1) break;
        finals[k-1]=0;
    }

    vector<int> choices(4);
    vector<int> v(n, 1);
    check(v, 0);

    for(i=0; i<4; i++){
    for(j=0; j<4; j++){
    for(k=0; k<4; k++){
    for(l=0; l<4; l++){
        if(i==j||i==k||i==l||j==k||j==l||k==l) continue;

        choices[0]=i, choices[1]=j, choices[2]=k, choices[3]=l;
        v=vector<int>(n, 1);

        for(r=0; r<4; r++){
            switch(choices[r]){
                case 0: for(q=0; q<n; q++) v[q]=!v[q]; check(v, r+1); break;
                case 1: for(q=0; q<n; q+=2) v[q]=!v[q]; check(v, r+1); break;
                case 2: for(q=1; q<n; q+=2) v[q]=!v[q]; check(v, r+1); break;
                case 3: for(q=0; q<n; q+=3) v[q]=!v[q]; check(v, r+1); break;
            }
        }

    }}}}

    if(res.size()==0) printf("IMPOSSIBLE\n");

    for(set<vector<int> >::iterator it=res.begin(); it!=res.end(); it++) {
        for(i=0; i<n; i++) printf("%d", (*it)[i]);
        printf("\n");
    }

    return 0;
}
