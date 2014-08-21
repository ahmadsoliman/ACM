#include <iostream>
#include <iterator>
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

#define pb push_back

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

typedef unsigned long long ll;

#define MAXSIEVE 1000
#define MAXSIEVEHALF 500
#define MAXSQRT 23

short a[505];
int primes[500], cntp;
ll two63;

int sieve(){
    int i, j, k;
    primes[0]=2;
    for(i=1,k=1;i<MAXSQRT;i++)
        if(a[i]==0){
            primes[k++]=i+i+1;
            for(j=2*i*i+i+i;j<MAXSIEVEHALF;j+=i+i+1)
                a[j]=1;
        }
    for(; i<MAXSIEVEHALF; i++)if(a[i]==0)primes[k++]=i+i+1;
    return k;
}

set<ll> s;

void recur(int i, int p, ll n){
    if(p==0) return;

    if(n>1) s.insert(n);

    ll lastn=n;
    for(int j=1; j<=p; j++){
        n*=primes[i];
        if(n>=two63 || n<lastn) break;
        recur(i+1, j, n);
        lastn=n;
    }
}

int cntprimes[500];

map<ll, ll> m;

int main(){
    cntp=sieve();

    two63 = (1ll<<63);

    recur(0, 63, 1);

//    copy(s.begin(), s.end(), ostream_iterator<ll>(cout, "\n"));

    printf("%d\n", s.size());

    vector<int> es;
    for(set<ll>::iterator it=s.begin(); it!=s.end(); it++){
        es.clear();
        ll cur = *it;
        ll oldcur=cur;

        int sum=0;
        for(int i=0; i<cntp && cur>1 ; i++){
            int cnt=0;
            while(cur%primes[i]==0) cur/=primes[i], cnt++;
            if(cnt>0) es.push_back(cnt);
            sum+=cnt;
        }

        memset(cntprimes, 0, sizeof cntprimes);

        while(sum){
            int cur=sum;
            for(int j=0; j<cntp && cur>1 ; j++){
                int cnt=0;
                while(cur%primes[j]==0) cur/=primes[j], cnt++;
                cntprimes[j]+=cnt;
            }
            sum--;
        }

        for(int i=0; i<es.size(); i++){
            while(es[i]){
                int cur=es[i];
                for(int j=0; j<cntp && cur>1 ; j++){
                    int cnt=0;
                    while(cur%primes[j]==0) cur/=primes[j], cnt++;
                    cntprimes[j]-=cnt;
                }
                es[i]--;
            }
        }

        ll val=1;
        bool valid=true;
        for(int i=0; i<cntp && valid; i++){
            while(cntprimes[i]--){
                val*=primes[i];
                if(val>=two63) {valid=false; break;}
            }
        }

        if(valid){
            if(m.find(val)==m.end()) m[val]=oldcur;
            else m[val]=min(oldcur, m[val]);
        }
    }
//        freopen("factors.out", "w", stdout);
//printf("%d\n", m.size());
//for(map<ll, ll>::iterator it = m.begin(); it!=m.end(); it++) printf("%lld %lld\n", it->first, it->second);

    ll n;

    while(scanf("%lld", &n)>0){
        if(n==1) { printf("1 2\n"); continue; }

        printf("%llu %llu\n", n, m[n]);
    }

    return 0;
}
