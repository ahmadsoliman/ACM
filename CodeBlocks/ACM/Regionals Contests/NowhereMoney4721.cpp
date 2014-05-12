#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vi;

ll val[100];
vi r1, r2;

ll recur1(int n){
    if(n==0||n==1) return val[n]=1;
    if(val[n]!=-1) return val[n];
    return val[n]=recur1(n-1)+recur1(n-2);
}

int main(){
    int i,j,k;
    ll n;
    memset(val, -1, sizeof val);
    for(i=0; i<91; i++){
        recur1(i);
    }
    while(scanf("%lld", &n)>0){
        printf("%lld\n", n);
        i=90;
        r1.clear();r2.clear();
        while(n>0 && i>0){
            if(val[i]>n) {i--; continue;}
            n-=val[i];
            r1.push_back(i);
            r2.push_back(val[i]);
            i-=2;
        }
        for(i=0; i<r1.size(); i++) {
            printf("%lld ", r1[i]);
            //if(i<r1.size()-1) printf(" ");
        }
        printf("\n");

        for(i=0; i<r2.size(); i++) {
            printf("%lld ", r2[i]);
            //if(i<r2.size()-1) printf(" ");
        }
        printf("\n\n");
    }
    return 0;
}
