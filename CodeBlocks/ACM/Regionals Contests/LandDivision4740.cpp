#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 10000000

ii avg;
int avgi;
double avgd;

int n;
vii pntsx, pntsy, xy;
vi breakx, breaky;

int gcd(int x, int y){
    if(x==0&&y==0)return 1;
    if(x==0) return y;
    return gcd(y%x, x);
}

ii simplify(ii p){
    int d=gcd(p.first, p.second);
    if(p.second==0) p.second=1;
    return ii(p.first/d, p.second/d);
}

ii add(ii p1, ii p2){
    return simplify(ii(p1.first*p2.second+p2.first*p1.second, p1.second*p2.second));
}

ii subtract(ii p1, ii p2){
    p2.first*=-1;
    return add(p1, p2);
}

ii absp(ii p){
    if(p.first<0) p.first*=-1;
    if(p.second<0) p.second*=-1;
    return p;
}

int comparep(ii p1, ii p2){
    p1=simplify(p1);p2=simplify(p2);
    if(1.0*p1.first/p1.second<1.0*p2.first/p2.second) return -1;
    return 1;
}

ii minp(ii p1, ii p2){
    if(comparep(p1, p2)<0) return p1;
    return p2;
}

double value(ii p){
    p=simplify(p);
    return 1.0*p.first/p.second;
}

int kase, vis1[100010][11], vis2[100010][11];
ii dp1[100010][11], dp2[100010][11];

ii recur1(int i, int k){
    if(i==breakx.size() && k==0) return ii(0,1);
    if(k==0) return ii(INF,1);
    if(i==breakx.size()) return simplify(ii(avg.first*k, avg.second));

    if(vis1[i][k]==kase) return dp1[i][k];

    int j=0, l=i;
    while(i<n && j+breakx[i]<avgi) j+=breakx[i++];

    ii a=add(absp(subtract(avg, ii(j,1))), recur1(i, k-1)), b(INF,1);
    if(i<n) b=add(absp(subtract(avg, ii(j+breakx[i],1))), recur1(i+1, k-1));

    vis1[l][k]=kase;
    return dp1[l][k]=simplify(minp(a,b));
}

ii recur2(int i, int k){
    if(i==breaky.size() && k==0) return ii(0,1);
    if(k==0) return ii(INF,1);
    if(i==breaky.size()) return simplify(ii(avg.first*k, avg.second));

    if(vis2[i][k]==kase) return dp2[i][k];

    int j=0, l=i;
    while(i<n && j+breaky[i]<avgi) j+=breaky[i++];

    ii a=add(absp(subtract(avg, ii(j,1))), recur2(i, k-1)), b(INF,1);
    if(i<n) b=add(absp(subtract(avg, ii(j+breaky[i],1))), recur2(i+1, k-1));

    vis2[l][k]=kase;
    return dp2[l][k]=simplify(minp(a,b));
}

int main(){
    kase=1;
    int k, i,j,l, x,y, d;
    ii a,b, res;
    while(scanf("%d %d", &n, &k)>0){
        if(n==0&&k==0) return 0;

        avg = ii(n,k); avgi=n/k; avgd=1.0*n/k;
        pntsx.clear();
        pntsy.clear();
        for(i=0; i<n; i++){
            scanf("%d %d", &x, &y);
            pntsx.push_back(ii(x,y));
            pntsy.push_back(ii(y,x));
        }
        sort(pntsx.begin(), pntsx.end());
        sort(pntsy.begin(), pntsy.end());

        breakx.clear();
        i=0;
        while(i<n){
            j=0;
            while(i+j<n-1 && pntsx[i+j].first==pntsx[i+j+1].first) j++;
            breakx.push_back(j+1);
            i+=j+1;
        }

        breaky.clear();
        i=0;
        while(i<n){
            j=0;
            while(i+j<n-1 && pntsy[i+j].first==pntsy[i+j+1].first) j++;
            breaky.push_back(j+1);
            i+=j+1;
        }


        a = recur1(0, k);
        b = recur2(0, k);

        res = minp(a,b);
        res.second*=k;
        res=simplify(res);

        printf("%d. %d/%d\n", kase++, res.first, res.second);
    }
    return 0;
}


/*

6 3
0 6
1 5
2 4
3 3
3 6
5 1


*/
