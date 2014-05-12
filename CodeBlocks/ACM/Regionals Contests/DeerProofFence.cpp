#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <algorithm>
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
#define normalize(p) ((p)/length(p))

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

vector<point> calcConvex(vector<point> pts){
    vector<point> convex;
    if(pts.size()==2){
        return pts;
    }else if(pts.size()==3){
        if(pointOnLine(pts[0], pts[1], pts[2])){
            sort(pts.begin(), pts.end(), cmp(pts[0]));
            convex.push_back(pts[0]);
            convex.push_back(pts[2]);
        }else{
            convex=pts;
        }
    } else{
        convexHull(pts, convex);
        reverse(convex.begin(),convex.end());
    }
    return convex;
}

double calcLenConvex(vector<point> convex){
    double val=0;
    for(int i=1; i<convex.size(); i++){
        val += length(vec(convex[i-1], convex[i]));
    }
    val += length(vec(convex.back(), convex[0]));
    return val;
}

double PI = acos(-1);
int n,margin;
vector<point> allpts;

double calcFence(vector<point> pts){
    vector<point> convex = calcConvex(pts);

    if(convex.size()==1){
        return 2*PI*margin;
    }
    if(convex.size()==2){
        return 2*length(vec(convex[0], convex[1]))+2*PI*margin;
    }
    double val = calcLenConvex(convex) + 2*PI*margin;

//    for(int i=0; i<convex.size(); i++){
//        point p = convex[i];
//        point p1 = (i>0)?convex[i-1]:convex.back();
//        point p2 = (i<convex.size()-1)?convex[i+1]:convex[0];
//
//        double ang = PI-fabs(asin(cross(normalize(vec(p, p1)), normalize(vec(p, p2)))));
//
//        val += ang * margin;
//    }
    return val;
}

double dp[1030];
int vis[1030];

double recur(int bm){
    if(bm == (1<<n)-1){
        return 0;
    }

    if(vis[bm]){
        return dp[bm];
    }

    vector<int> left;
    for(int i=0; i<n; i++){
        if(!(bm&(1<<i))) left.push_back(i);
    }
    vector<point> pts;

    double minV=1000000000;
    for(int i=1; i<(1<<left.size()); i++){
        int bm2 = bm;
        pts.clear();
        for(int j=0; j<left.size(); j++){
            if(i&(1<<j)) {
                bm2 |= (1<<left[j]);
                pts.push_back(allpts[left[j]]);
            }
        }
        minV = min(minV, calcFence(pts)+recur(bm2));
    }
    vis[bm]=1;
    return dp[bm]=minV;
}

int main(){
//    freopen("fence.in","r",stdin);

    int x,y, kase=1;
    while(scanf("%d %d", &n, &margin)>0){
        if(!n && !margin) break;

        allpts.clear();
        for(int i=0; i<n; i++){
            scanf("%d %d", &x, &y);
            allpts.push_back(point(x,y));
        }

        memset(vis, 0, sizeof vis);
        printf("Case %d: length = %.2lf\n", kase++, recur(0));
    }


    return 0;
}





/*
3 2
0 0
2 0
10 0
3 4
0 0
2 0
10 0
0 0
*/


