#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

char s1[8005], s2[8005];
string s;

char T[MAXN], P[MAXN];
int zfn[MAXN], n, m, occ, occI[MAXN];

/* P , pattern preprocess */
void kmpPreprocess() {
    int i=0, j=-1;
    zfn[0]=-1;
    while(i<m){
        while(j>=0 && P[i]!=P[j]) j=zfn[j];
        i++; j++;
        zfn[i]=j;
    }
}

void kmp(){
    occ=0;
    int i=0, j=0;
    while(i<n) {
        while(j>=0 && T[i]!=P[j]) j=zfn[j];
        i++; j++;
        if(j==m) {
            occI[occ++]=i-j;
            j=zfn[j];
        }
    }
}

int main(){
    int t, i,j,k, n, l1, l2, cnt, kase=1;
    scanf("%d", &t);
    while(t--){
        scanf("%s", s1);
        scanf("%s", s2);
        scanf("%d", &k);

        l1 = strlen(s1);
        l2 = strlen(s2);

        for(i=0; i<l2; i++){
            s="";
            for(j=i; j<l2; j++){
                s.push_back(s2[j]);
                if((it=m.find(s))==m.end()) m[s]=1;
                else it->second++;
            }
        }

        printf("Case #%d:\n%d\n", kase++, cnt);
    }
    return 0;
}
