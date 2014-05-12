#include <vector>
#include <algorithm>
#include <cstdlib>
#include <math.h>
#include <stdio.h>

#define EPS 1e-9

using namespace std;

typedef pair<double, double> dd;
typedef pair<dd, dd> vec;


struct point{
    int index;
    double x,y;
    point(int index1, double x1, double y1){index=index1; x=x1; y=y1;}
};

vector<point> pnts;
vector<int> res;

int main(){
    int t, d, n, S, pivot, i,j,k, mini, kase=1;
    double a, x,y, minv, curv, det;

    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %d %lf", &d ,&n, &S, &pivot, &a);
        pivot--;

        pnts.clear();
        for(i=0; i<n; i++){
            scanf("%d %lf %lf", &d, &x, &y);
            pnts.push_back(point(d-1, x,y));
        }

        dd xintr;
        if(fabs(tan(a))>EPS) xintr=dd(pnts[pivot].x+pnts[pivot].y/tan(a), 0);
        else xintr=dd(1000.0, 0.0);
        vec v(dd(pnts[pivot].x, pnts[pivot].y), xintr);

        res.clear();
        for(i=0; i<S; i++){
            minv=1000;
            for(j=0; j<pnts.size(); j++){
                if(j==pivot) continue;
                det=hypot(v.second.first-v.first.first,v.second.second-v.first.second)*
                            hypot(pnts[j].x-pnts[pivot].x, pnts[j].y-pnts[pivot].y);
                curv=acos(((v.second.first-v.first.first)*(pnts[j].x-pnts[pivot].x)+
                          (v.second.second-v.first.second)*(pnts[j].y-pnts[pivot].y))/det);
                if(sin(curv)<0)curv=acos(-1)-curv;

               // printf("%d %lf %lf\n", j, (v.second.first-v.first.first)*(pnts[j].x-pnts[pivot].x)+
                 //         (v.second.second-v.first.second)*(pnts[j].y-pnts[pivot].y)/det, curv);
                if(curv<minv) minv=curv, mini=j;
                else if(fabs(curv-minv)<0 &&
                    hypot(pnts[j].x-pnts[pivot].x, pnts[j].y-pnts[pivot].y)
                    <hypot(pnts[mini].x-pnts[pivot].x, pnts[mini].y-pnts[pivot].y)) minv=curv, mini=j;
            }
            v=vec(dd(pnts[pivot].x,pnts[pivot].y),dd(pnts[mini].x,pnts[mini].y));
            pivot=mini;
            res.push_back(pivot+1);
        }
        printf("%d %d", kase++, res[0]);
        for(i=1; i<res.size(); i++) printf(" %d", res[i]);
        printf("\n");
    }
    return 0;
}
