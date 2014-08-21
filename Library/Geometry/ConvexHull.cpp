#include <stdio.h>

#include <vector>
#include <algorithm>
#include <cstdlib>
#include <complex>
#include <iostream>
using namespace std;

typedef complex<long double> point;

#define sz(a) ((int)(a).size())
#define cross(a,b) ((conj(a)*(b)).imag())
#define vec(a,b) ((b)-(a))
#define EPS 1e-9
#define X real()
#define Y imag()
#define all(n) (n).begin(),(n).end()
#define same(a,b) (lengthSqr(vec(a,b))<EPS)
#define length(v) ((long double)hypot((v).Y,(v).X))
#define lengthSqr(v) (dot(v,v))
#define dot(a,b) ((conj(a)*(b)).real())

struct cmp {
    point about;
    cmp(point c) {
            about = c;
    }
    bool operator()(const point& p, const point& q) const {
            double cr = cross(vec(about,p),vec(about,q));
            if (fabs(cr) < EPS)
                    return make_pair(p.Y, p.X) < make_pair(q.Y, q.X);
            return cr > 0;
    }
};

void sortAntiClockWise(vector<point>& pnts){
        point mn(1 / 0.0, 1 / 0.0);
        for (int i = 0; i < sz(pnts); i++)
            if (make_pair(pnts[i].Y, pnts[i].X) < make_pair(mn.Y, mn.X))
                mn = pnts[i];

        sort(all(pnts),cmp(mn));
}

void convexHull(vector<point> pnts, vector<point> &convex) {
        sortAntiClockWise(pnts);
        convex.clear();
        convex.push_back(pnts[0]);
        if (sz(pnts) == 1)
                return;
        convex.push_back(pnts[1]);
        for (int i = 2; i <= sz(pnts); i++) {
                point c = pnts[i % sz(pnts)];
                while (sz(convex) > 1) {
                        point b = convex.back();
                        point a = convex[sz(convex) - 2];
                        if (cross(vec(b,a),vec(b,c)) < -EPS)
                                break;
                        convex.pop_back();
                }
                if (i < sz(pnts))
                        convex.push_back(pnts[i]);
        }
}


bool pointOnLine(const point& a, const point& b, const point& p) {
    if(same(a,b)) return same(a,p);
    return fabs(cross(vec(a,b),vec(a,p))) < EPS;
}

vector<point> pts, convex;

int main(){
    int t, i,j, n, x, y, kase=1, minI;
    point minP;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &i, &n);
        pts.clear();
        for(i=0; i<n; i++){
            scanf("%d %d", &x, &y);
            pts.push_back(point(x,y));
        }
        if(n==2){
            convex=pts;
        }else if(n==3){
            if(pointOnLine(pts[0], pts[1], pts[2])){
                sort(pts.begin(), pts.end(), cmp(pts[0]));
                convex.clear();
                convex.push_back(pts[0]);
                convex.push_back(pts[2]);
            }else{
                convex=pts;
            }
        } else{
            convexHull(pts, convex);
            reverse(convex.begin(),convex.end());
        }
        printf("%d %d\n", kase++, convex.size());

        minP=convex[0];
        minI=0;
        for(i=1; i<convex.size(); i++){
            if(convex[i].Y>minP.Y || (convex[i].Y==minP.Y && convex[i].X<minP.X)){
                minP=convex[i];
                minI=i;
            }
        }
        for(i=0, j=minI; i<convex.size(); i++, j++) printf("%d %d\n", (int)convex[j%convex.size()].X, (int)convex[j%convex.size()].Y);
    }
    return 0;
}
