/*j ID: ahmadad1
PROG: kimbits
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
typedef pair<int, ii> iii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;

int totaln, done;
ll cnt, ind;
string res;

void recur(int n, int l){
    if(done) return;
    if(n==0){
        cnt++;
        if(cnt==ind) {
            done=1;
            printf("%s\n", res.c_str());
        }
        return;
    }
    if(l==0){
        cnt++;
        if(cnt==ind) {
            done=1;
            while(n--) res+='0';
            printf("%s\n", res.c_str());
        }
        return;
    }
    if(n==l){
        if(cnt+(1LL<<n)>ind){
            ll rest = ind-cnt;
            string r="";
            rest--;
            while(rest>0) r+=(rest&1)+'0', rest>>=1;
            for(; r.size()<n; ) r+='0';
            reverse(r.begin(), r.end());
            res+=r;
            done=1;
            printf("%s\n", res.c_str());
        }else{
            cnt+=(1LL<<n);
            if(cnt==ind) {
                done=1;
                while(n--) res+='1';
                printf("%s\n", res.c_str());
            }
        }
        return;
    }

    res+='0';
    recur(n-1, l);
    res.resize (res.size () - 1);

    res+='1';
    recur(n-1, l-1);
    res.resize (res.size () - 1);
}

int main() {
    freopen("kimbits.in", "r", stdin);
    freopen("kimbits.out", "w", stdout);

    int i,j,r, k;

    int n, l;
    scanf("%d %d %lld", &n, &l, &ind);

    cnt=0;
    done=0;
    res="";
    totaln=n;
    recur(n, l);


    return 0;
}




