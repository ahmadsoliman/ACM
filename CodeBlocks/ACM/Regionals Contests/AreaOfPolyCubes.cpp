#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

#define x first
#define y second.first
#define z second.second

int dx[6]={1,-1,0,0,0,0},dy[6]={0,0,1,-1,0,0},dz[6]={0,0,0,0,1,-1};

iii triples[105];
short space[205][205][205];

int main(){
    int t, n, i,j, xp,yp,zp, kase=1, valid, firstfail, found, maxx, maxy, maxz, minx, miny, minz, area;
    iii p;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        memset(space, 0, sizeof space);
        valid=1;
        maxx=maxy=maxz=0;
        minx=miny=minz=205;
        for(i=0; i<n; i++) {
            scanf("%d,%d,%d", &xp, &yp, &zp);
            xp+=100;yp+=100;zp+=100;
            triples[i]=iii(xp,ii(yp,zp));
            if(xp>maxx) maxx=xp;
            if(yp>maxy) maxy=yp;
            if(zp>maxz) maxz=zp;
            if(xp<minx) minx=xp;
            if(yp<miny) miny=yp;
            if(zp<minz) minz=zp;
        }
        if(triples[0].x!=100||triples[0].y!=100||triples[0].z!=100){
            printf("%d NO 1\n", kase++);
            continue;
        }
        space[100][100][100]=1;
        area=0;
        for(i=1; i<n; i++){
            p = triples[i];
            if(p.x<0||p.x>200||p.y<0||p.y>200||p.z<0||p.z>200||space[p.x][p.y][p.z]){
                valid=0;
                firstfail=i+1;
                break;
            }
            space[p.x][p.y][p.z]=1;
            found=0;
            for(j=0; j<6; j++){
                if(space[p.x+dx[j]][p.y+dy[j]][p.z+dz[j]]){
                    found=1;break;
                }
            }
            if(!found){
                valid=0;
                firstfail=i+1;
                break;
            }
        }
        if(!valid){
            printf("%d NO %d\n", kase++, firstfail);
            continue;
        }
        for(i=0; i<n; i++){
            p = triples[i];
            for(j=0; j<6; j++){
                if(space[p.x+dx[j]][p.y+dy[j]][p.z+dz[j]]==0){
                    area++;
                }
            }
        }
        printf("%d %d\n", kase++, area);
    }
    return 0;
}
