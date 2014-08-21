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

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int a[30];

ll sums[16777220];

int nbits(int i){
     i = i - ((i >> 1) & 0x55555555);
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    sort(a, a+n);

    for(int i=0; i<(1<<n); i++){
        sums[i]=0;
        for(int j=0; j<n; j++) if(i&(1<<j)) sums[i]+=a[j];
    }

    ll avg = sums[(1<<n)-1]/3, X,Y,Z;

    ll mindiff=1000000000000000000ll, sumY, sumZ;

    for(int bm1=0, left, l1,l2; bm1<(1<<n); bm1++){
        if(sums[bm1]>avg) continue;
        X = sums[bm1];
        left = (1<<n)-1-bm1;
        int leftl = nbits(left), half=leftl/2;
        vector<iii> K,L;
        for(int bm2=0; bm2<(1<<half); bm2++){
            sumY=sumZ=0;
            for(int i=0, j=0; i<n&&j<half; i++){
                if(left&(1<<i)){
                    if(bm2&(1<<j)) sumY+=a[i];
                    else sumZ+=a[i];
                    j++;
                }
            }
            if(sumY>=sumZ) K.push_back(iii(sumY-sumZ, ii(sumY, sumZ)));
        }
        for(int bm2=0; bm2<(1<<(leftl-half)); bm2++){
            sumY=sumZ=0;
            for(int i=n-1, j=0; i>=0&&j<(leftl-half); i--){
                if(left&(1<<i)){
                    if(bm2&(1<<j)) sumY+=a[i];
                    else sumZ+=a[i];
                    j++;
                }
            }
            if(sumY<=sumZ) L.push_back(iii(sumY-sumZ, ii(sumY, sumZ)));
        }
        sort(K.begin(), K.end());
        sort(L.rbegin(), L.rend());

//        printf("%d\n", X);
//        for(int i=0; i<K.size(); i++) printf("K: %d %d\n",  K[i].second.first,K[i].second.second);
//        for(int i=0; i<L.size(); i++) printf("L: %d %d\n",  L[i].second.first,L[i].second.second);

        ll d, r=1000000000000000000ll;
        for(int i=0,j=0; i<K.size()&&j<L.size(); ){
            d = K[i].second.first+L[j].second.first-K[i].second.second-L[j].second.second;
            if(d>=0){
                if(d<r) {
                    r=d;
                    Y = K[i].second.first+L[j].second.first;
                    Z = K[i].second.second+L[j].second.second;
//                    printf("---------------------------------%d %d %d\n", X, Y, Z);
                    mindiff = min(mindiff, max(X,max(Y,Z))-min(X,min(Y,Z)));
                }
                i++;
            }else j++;
        }
    }

    printf("%lld\n", mindiff);

    return 0;
}





