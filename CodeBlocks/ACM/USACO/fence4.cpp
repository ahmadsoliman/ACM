/*j ID: ahmadad1
PROG: fence4
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
#include <complex>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;

typedef complex<long double> point;
typedef pair<point, point> edge;

#define EPS 1e-9
#define X real()
#define Y imag()
#define vec(a,b) ((b)-(a))
#define length(v) ((long double)hypot((v).Y,(v).X))
#define dot(a,b) ((conj(a)*(b)).real())
#define cross(a,b) ((conj(a)*(b)).imag())

point p, vs[205];
edge es[205];

int segIntr(edge e1, edge e2){
    point a=e1.first, b=e1.second, c=e2.first, d=e2.second;

    if(cross(vec(b,a),vec(c,a))*cross(vec(b,a),vec(d,a))<-EPS &&
       cross(vec(d,c),vec(a,c))*cross(vec(d,c),vec(b,c))<-EPS) return 1;
    return 0;
}

int rayIntrSeg(edge ray, edge seg, point &ret){
    point a=ray.first, b=ray.second, c=seg.first, d=seg.second;

    long double d1 = cross(c - a, b - a);
    long double d2 = cross(d - a, b - a);
    ret = (d1 * d - d2 * c) / (d1 - d2);

    if(cross(vec(b,a),vec(c,a))*cross(vec(b,a),vec(d,a))<EPS) {
        if(dot(vec(a,ret), vec(ray.first, ray.second))<0) return 0;
        return 1;
    }
    return 0;
}

int rayIntrSegNonTouching(edge ray, edge seg, point &ret){
    point a=ray.first, b=ray.second, c=seg.first, d=seg.second;

    long double d1 = cross(c - a, b - a);
    long double d2 = cross(d - a, b - a);
    ret = (d1 * d - d2 * c) / (d1 - d2);

    if(cross(vec(b,a),vec(c,a))*cross(vec(b,a),vec(d,a))<0) {
        if(dot(vec(a,ret), vec(ray.first, ray.second))<0) return 0;
        return 1;
    }
    return 0;
}


vector<edge> res;

int main() {
  //  freopen("fence4.in", "r", stdin);
    //freopen("fence4.out", "w", stdout);

    int n,e, i,j,k, x,y, f;

    scanf("%d", &n);
    scanf("%d %d", &x,&y);
    p=point(x,y);

    e=0;
    for(i=0; i<n; i++) {
        scanf("%d %d", &x, &y);
        vs[i]=point(x,y);
        if(i>0) es[e++]=edge(vs[i-1], vs[i]);
    }
    swap(es[e-1], es[e]);
    es[-1+e++]=edge(vs[0], vs[n-1]);

    for(i=0; i<e; i++){
        for(j=i+1; j<e; j++){
            if(segIntr(es[i], es[j])) {
                printf("NOFENCE\n");
                return 0;
            }
        }
    }

    // loop on every edge i
    for(i=0; i<e; i++){
        // get edge mid point
        point mid=(es[i].first+es[i].second)/2.0l;
        long double len=length(mid-p);
        edge ray(p, mid); // ray to midpoint

        f=1;
        // loop on other edges j to check intersection
        for(j=0; j<e; j++){
            if(i==j) continue;
            point ip;
            // ray intersect with other edge
            if(rayIntrSeg(ray, es[j], ip)){

                /* trying to find another intersection other than the midpoint around the other edge j corners*/
                point ip2, ip3;
                point p1=es[j].first, p2=es[j].second;
                point diff = (p2-p1)/length(p2-p1);
                p1-=diff*0.00001l;
                p2+=diff*0.00001l;
                edge ray2(p, p1),ray3(p, p2);

                if(length(ip-p)<len){
                    if(!rayIntrSeg(ray2, es[i], ip2) && !rayIntrSeg(ray3, es[i], ip3)){
                        f=0; break;
                    }
                }
/*
                if(rayIntrSeg(ray2, es[i], ip2)){
                    int f2=1;
                    long double len2=length(ip2-p);
                    for(k=0; k<e; k++){
                        if(k==i||k==j) continue;
                        point ip4;
                        if(rayIntrSeg(ray2, es[k], ip4)){
                            if(length(ip4-p)<len2){
                                f2=0; break;
                            }
                        }
                    }
                    if(f2) continue;
                }else if(rayIntrSeg(ray3, es[i], ip3)){
                    int f2=1;
                    long double len2=length(ip3-p);
                    for(k=0; k<e; k++){
                        if(k==i||k==j) continue;
                        point ip4;
                        if(rayIntrSeg(ray3, es[k], ip4)){
                            if(length(ip4-p)<len2){
                                f2=0; break;
                            }
                        }
                    }
                    if(f2) continue;
                }
*/
                /* End 5araaaa !!! */


            }
        }
        if(f) {res.push_back(es[i]); continue;}


    }

    printf("%d\n", res.size());
    for(i=0; i<res.size(); i++){
        printf("%d %d %d %d\n", (int)round(res[i].first.X), (int)round(res[i].first.Y)
               , (int)round(res[i].second.X), (int)round(res[i].second.Y));
    }

    return 0;
}



/*
4
5 5
0 0
0 4
2 0
-2 2
nofence
*/


