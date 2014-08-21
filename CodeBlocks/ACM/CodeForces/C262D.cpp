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

#define pb push_back

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

#define lld I64d

int main() {
    ll l,r,k;
    scanf("%lld %lld %lld", &l, &r, &k);

    if(l==r){
        printf("%lld\n1\n%lld\n", l, l);
        return 0;
    }

    bool f=false;

    int tmpl=l, tmpr=r, cl=0, cr=0;
    while(tmpl>0) tmpl/=2, cl++;
    while(tmpr>0) tmpr/=2, cr++;

    cr = min(cr, (int)k);

    vector<ll> res;
    for(int n=cl; n<=cr && !f; n++){
        if(n%2==0){
            if((n/2)%2==0){
                vvi t(n, vi(n, 0));
                int cnt=n/2, last=0;
                for(int j=n-1; j>=0; j--){
                    for(int l=0; l<cnt; last=(last+1)%n, l++){
                        t[l][last]=1;
                    }
                }
                ll num;
                for(int i=0; i<n; i++){
                    num=0;
                    for(int j=0; j<n; j++){
                        num += pow(2,j)*t[i][j];
                    }
                    res.push_back(num);
                }
                sort(res.begin(), res.end());
                if(res[0]>=l && res.back()<=r) f=true;
                else res.clear();
            }
        }else{
            vvi t(n, vi(n, 0));
            int cnt=2, last=0;
            for(int j=n-1; j>=0; j--){
                for(int l=0; l<cnt; last=(last+1)%n, l++){
                    t[l][last]=1;
                }
            }
            ll num;
            for(int i=0; i<n; i++){
                num=0;
                for(int j=0; j<n; j++){
                    num += pow(2,j)*t[i][j];
                }
                res.push_back(num);
            }
            sort(res.begin(), res.end());
            if(res[0]>=l && res.back()<=r) f=true;
            else res.clear();
        }
    }

    if(f){
        printf("0\n");
        printf("%lld\n", res.size());
        printf("%lld", res[0]);
        for(int i=1; i<res.size(); i++) printf(" %lld", res[i]);
        printf("\n");
    }else{
        printf("1\n2\n%lld %lld\n",l, l+1);
        return 0;
    }

    return 0;

}
