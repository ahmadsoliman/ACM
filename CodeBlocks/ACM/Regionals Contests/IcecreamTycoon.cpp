#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <algorithm>

#define INF 1000000000

typedef long long ll;

using namespace std;

char q[100];
int len;
ll sumCost[2097162];
int sumCount[2097162], flushed[2097162];

int check(int node, int c, ll m){
    if(c==0) return 1;
    if(node>len){
        if(c>sumCount[node]) return 0;
        m-=((ll)c)*(node-len);
        return m>=0;
    }
    int l=node<<1, r=(node<<1)+1;
    if(flushed[node]){
        flushed[node]=0;
        flushed[l]=1;
        flushed[r]=1;
        sumCount[l] = 0;
        sumCost[l] = 0;
        sumCount[r] = 0;
        sumCost[r] = 0;
    }
    if(sumCount[l]>c) return check(l, c, m);

    c -= sumCount[l];
    m -= sumCost[l];

    if(m<0) return 0;

    return check(r, c, m);
}

void flush(int node, int c, ll m){
//    printf("%d %d %d\n", node, c, m);
    if(c==0) return;
    if(node>len){
        sumCount[node]-=c;
        sumCost[node]=((ll)sumCount[node])*(node-len);
        return;
    }

    int l=node<<1, r=(node<<1)+1;
    if(sumCount[l]>c) {
        flush(l, c, m);
        sumCount[node]=sumCount[l]+sumCount[r];
        sumCost[node]=sumCost[l]+sumCost[r];
        return;
    }

    c -= sumCount[l];
    m -= sumCost[l];

    flushed[l] = 1;
    sumCount[l] = 0;
    sumCost[l] = 0;

    flush(r, c, m);

    sumCount[node]=sumCount[l]+sumCount[r];
    sumCost[node]=sumCost[l]+sumCost[r];
}

void update(int node, int l, int r, int c, int p){
    if(l==r && l==p){
        sumCount[node]+=c;
        sumCost[node]=((ll)sumCount[node])*(node-len);
        return;
    }
    if(p<l || p>r) return;

    int left=node<<1, right=(node<<1)+1;
    if(flushed[node]){
        flushed[node]=0;
        flushed[left]=1;
        flushed[right]=1;
        sumCount[left] = 0;
        sumCost[left] = 0;
        sumCount[right] = 0;
        sumCost[right] = 0;
    }

    update(left, l, (l+r)/2, c, p);
    update(right, (l+r)/2+1, r, c, p);

    sumCount[node]=sumCount[left]+sumCount[right];
    sumCost[node]=sumCost[left]+sumCost[right];
}

int main(){
    freopen("icecream.in","r",stdin);
    freopen("icecream.out","w",stdout);
    len = pow(2,20)-1;
    memset(sumCost, 0, sizeof sumCost);
    memset(sumCount, 0, sizeof sumCount);
    memset(flushed, 0, sizeof flushed);

    int a;
    ll b;
    while(scanf("%s %d %lld", q, &a, &b)>0){
        if(strcmp(q, "ARRIVE")==0){
            update(1, 0, len, a, (int)(b-1));
        }else{
            if(check(1, a, b)){
                printf("HAPPY\n");
                flush(1, a, b);
                //printf("%d %d\n", sumCount[1], sumCost[1]);
            }else{
                printf("UNHAPPY\n");
            }
        }

    }

    return 0;
}
