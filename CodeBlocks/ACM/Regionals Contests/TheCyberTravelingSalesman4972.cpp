#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <complex>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000
#define EPS 1e-6

int n, c;

struct point {
    long double x,y;
    point() { x = 0; y = 0; }
    point(long double _x, long double _y) { x = _x; y = _y; }
    bool operator < (point other) {
        if(fabs(x - other.x) < EPS)
            return x < other.x;
        return y < other.y;
    }
    bool operator == (point other) {
        if(fabs(x - other.x) < EPS && fabs(y - other.y) < EPS)
            return true;
        return false;
    }
};

typedef pair<point, int> pi;

long double dist(point p1, point p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

struct line { long double a, b, c; };

void pointsToLine(point p1, point p2, line *l) {
    // vertical line is handled nicely here
    if (p1.x == p2.x) {
        l->a = 1.0; l->b = 0.0; l->c = -p1.x;
    } else {
        l->a = -(long double)(p1.y - p2.y) / (p1.x - p2.x);
        l->b = 1.0;
        l->c = -(long double)(l->a * p1.x) - (l->b * p1.y);
    }
}

bool areParallel(line l1, line l2) {
    // check coefficient a + b
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}

bool areSame(line l1, line l2) {
    // also check coefficient c
    return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS);
}

bool areIntersect(line l1, line l2, point *p, point s, point e) {
    if (areSame(l1, l2)) return false; // all points intersect
    if (areParallel(l1, l2)) return false; // no intersection

    // solve system of 2 linear algebraic equations with 2 unknowns
    p->x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if (fabs(l1.b) > EPS) // special case: test for vertical line avoid division by zero
        p->y = - (l1.a * p->x + l1.c) / l1.b;
    else
        p->y = - (l2.a * p->x + l2.c) / l2.b;

    long double d=dist(s,*p)+dist(*p,e);
    if(fabs(d-dist(s,e))<1) return true;
    return false;
}

vector< point > cities;
int g[15][15], done, minv;
line lines[15][15];

void recur(int bm, vi path){
    vi cnts;
    vector< point > s;
    vector< point > ::iterator it;
    int curv;
    point intr;
    if(bm==done){
        int last=path[path.size()-1];
        path.push_back(0);
        curv=0;
        for(int i=1; i<path.size(); i++){
            curv += g[path[i-1]][path[i]];
            for(int j=1; j<i-1; j++){
                if(!areIntersect(lines[path[j-1]][path[j]], lines[path[i-1]][path[i]], &intr, cities[path[j-1]], cities[path[j]])) continue;
                //intr = point(round(intr.x),round(intr.y));
                if(find(cities.begin(), cities.end(), point())!=cities.end()) continue;
                it = find(s.begin(), s.end(), intr);
                if(it==s.end()) { s.push_back(intr); cnts.push_back(1); }
                else cnts[it-s.begin()]++;
            }
        }

        for(int i=0; i<s.size(); i++){
           // printf("%.2lf %.2lf\n", s[i].x, s[i].y);

            curv+=cnts[i]*(cnts[i]+1)*c/2;
        }
    //printf("\n");
        if(curv<minv) minv=curv;
        return;
    }
    int last=path[path.size()-1];
    for(int i=1; i<n; i++){
        if(!(bm&(1<<i))){
            vi tmp = path;
            tmp.push_back(i);
            recur(bm|(1<<i), tmp);
        }
    }
}

int main(){
    int i,j,k, x,y, kase=1;
    while(scanf("%d %d", &n, &c)>0){
        if(n==0 && c==0) return 0;
        cities.clear();
        for(i=0; i<n; i++) { scanf("%d %d", &x, &y); cities.push_back(point(x,y)); }
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                scanf("%d", &g[i][j]);
                if(i!=j){
                    pointsToLine(cities[i], cities[j], &lines[i][j]);
                }
            }
        }
        done=(1<<n)-1;
        vi tmp;
        tmp.push_back(0);
        minv=INF;
        recur(1, tmp);
        printf("%d. %d\n", kase++, minv);
    }
    return 0;
}

/*

6 1
0 1
4 1
3 2
1 0
3 0
1 2
0    1  100  100  100   1
1    0   1   100  100  100
100  1   0    1   100  100
100 100  1    0    1   100
100 100 100   1    0    1
1   100 100  100   1    0


*/
