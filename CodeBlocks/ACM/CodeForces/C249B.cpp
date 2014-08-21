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
typedef pair<int, ii> iii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

char n[100];
int maxV[100], maxI[100];

int main() {
    int k;
    scanf("%s %d", n, &k);
    int len = strlen(n);

    int last=0;
    while(k>0){
        memset(maxV, 0, sizeof maxV);

        for(int i=len-1; i>last; i--){
            if(maxV[max(i-k, last)]<=n[i]){
                maxV[max(i-k, last)]=n[i];
                maxI[max(i-k, last)]=i;
            }
        }

        int i;
        for(i=0; i<len; i++) if(maxV[i]>0) break;
        last = i;

        for(int j=maxI[i]; j>i && k>0; j--) swap(n[j],n[j-1]), k--;

    }

    printf("%s\n", n);

    return 0;
}
