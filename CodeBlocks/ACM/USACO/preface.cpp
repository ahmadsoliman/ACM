/*j ID: ahmadad1
PROG: preface
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

int v[10]={1000, 500, 100, 50, 10, 5, 1, 0, 0};
char c[10]={'M', 'D', 'C', 'L', 'X', 'V', 'I', 'x', 'x'};

int freq[10];

void gen(int n){
    int f;
    while(n){
        int tmpn=n, cnt=1;
        while(tmpn>9) tmpn/=10, cnt*=10;
        tmpn*=cnt;

        for(int i=0; i<7 && n; i++){
            if(tmpn==v[i]-v[i+2] && tmpn!=v[i+2]) { n-=v[i]-v[i+2], freq[i]++, freq[i+2]++; break; }
            if(tmpn==v[i]-v[i+1] && tmpn!=v[i+1]) { n-=v[i]-v[i+1], freq[i]++, freq[i+1]++; break; }
            f=0;
            while(tmpn>=v[i]) { f=1, tmpn-=v[i], n-=v[i], freq[i]++; }
            if(f) break;
        }

    }
}

int main() {
    freopen("preface.in", "r", stdin);
    freopen("preface.out", "w", stdout);

    int n;

    scanf("%d", &n);

    memset(freq, 0, sizeof freq);
    for(int i=1; i<=n; i++) gen(i);

    for(int i=6; i>=0; i--){
        if(freq[i]>0) printf("%c %d\n", c[i], freq[i]);
    }

    return 0;
}
