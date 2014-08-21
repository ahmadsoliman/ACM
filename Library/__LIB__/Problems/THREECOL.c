/*

DP On Trees
Tree Coloring

*/

#include <stdio.h>

#define INF 100000000
#define max(x,y) ((x>y)?x:y)
#define min(x,y) ((x<y)?x:y)

char tree[10005];
int n, kase, nchild[10005], dpmin[10005][3], dpmax[10005][3], vismax[10005][3], vismin[10005][3];

int countChild(int i){
    if(tree[i]=='0') {
        nchild[i] = 1;
    } else if(tree[i]=='1') {
        nchild[i]=1+countChild(i+1);
    } else{
        nchild[i]=1+countChild(i+1);
        nchild[i]+=countChild(i+nchild[i]);
    }
    return nchild[i];
}

int recurmax(int i, int last){
    if(i>=n || tree[i]=='0') return 0;
    if(vismax[i][last]==kase) return dpmax[i][last];
    int a=0,b=0,c=0,d=0;
    if(tree[i]=='1'){
        if(last!=0) a = recurmax(i+1, 0);
        if(last!=1) b = 1+recurmax(i+1, 1);
        if(last!=2) c = recurmax(i+1, 2);
    }else{
        if(last==0) {
            a = 1 + recurmax(i+1, 1) + recurmax(i+nchild[i+1]+1, 2);
            d = 1 + recurmax(i+1, 2) + recurmax(i+nchild[i+1]+1, 1);
            if(d>a) a=d;
        } else if(last==1) {
            b = recurmax(i+1, 0) + recurmax(i+nchild[i+1]+1, 2);
            d = recurmax(i+1, 2) + recurmax(i+nchild[i+1]+1, 0);
            if(d>b) b=d;
        } else if(last==2) {
            c = 1 + recurmax(i+1, 0) + recurmax(i+nchild[i+1]+1, 1);
            d = 1 + recurmax(i+1, 1) + recurmax(i+nchild[i+1]+1, 0);
            if(d>c) c=d;
        }
    }
    vismax[i][last]=kase;
    return dpmax[i][last] = max(a, max(b,c));
}

int recurmin(int i, int last){
    if(i>=n || tree[i]=='0') return 0;
    if(vismin[i][last]==kase) return dpmin[i][last];
    int a=INF,b=INF,c=INF,d=0;
    if(tree[i]=='1'){
        if(last!=0) a = recurmin(i+1, 0);
        if(last!=1) b = 1+recurmin(i+1, 1);
        if(last!=2) c = recurmin(i+1, 2);
    }else{
        if(last==0) {
            a = 1 + recurmin(i+1, 1) + recurmin(i+nchild[i+1]+1, 2);
            d = 1 + recurmin(i+1, 2) + recurmin(i+nchild[i+1]+1, 1);
            if(d<a) a=d;
        } else if(last==1) {
            b = recurmin(i+1, 0) + recurmin(i+nchild[i+1]+1, 2);
            d = recurmin(i+1, 2) + recurmin(i+nchild[i+1]+1, 0);
            if(d<b) b=d;
        } else if(last==2) {
            c = 1 + recurmin(i+1, 0) + recurmin(i+nchild[i+1]+1, 1);
            d = 1 + recurmin(i+1, 1) + recurmin(i+nchild[i+1]+1, 0);
            if(d<c) c=d;
        }
    }
    vismin[i][last]=kase;
    return dpmin[i][last] = min(a, min(b,c));
}

int main(){
    int t, i, a,b,c,rmax, rmin;
    scanf("%d", &t);
    kase=1;
    while(t--){
        scanf("%s", tree);
        n = strlen(tree);

        countChild(0);
        a=recurmax(0, 0);
        b=1+recurmax(0, 1);
        c=recurmax(0, 2);
        rmax = max(a, max(b,c));

        a=recurmin(0, 0);
        b=1+recurmin(0, 1);
        c=recurmin(0, 2);
        rmin = min(a, min(b,c));

        printf("%d %d\n", rmax, rmin);
        kase++;
    }
    return 0;
}
