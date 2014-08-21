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

#define INF 1000000000
#define EPS 1e-7

struct point {
    double x,y;
    point() { x = 0; y = 0; }
    point(double _x, double _y) { x = _x; y = _y; }
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

struct line { double a, b, c; };

void pointsToLine(point p1, point p2, line *l) {
    // vertical line is handled nicely here
    if (p1.x == p2.x) {
        l->a = 1.0; l->b = 0.0; l->c = -p1.x;
    } else {
        l->a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l->b = 1.0;
        l->c = -(double)(l->a * p1.x) - (l->b * p1.y);
    }
}

double dist(point p1, point p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

double distToLine(point p, point A, point B, point *c) {
    // formula: cp = A + (p-A).(B-A) / |B-A| * (B-A)
    double scale = (double)
        ((p.x - A.x) * (B.x - A.x) + (p.y - A.y) * (B.y - A.y)) /
        ((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
    c->x = A.x + scale * (B.x - A.x);
    c->y = A.y + scale * (B.y - A.y);
    return dist(p, *c);
}

bool areParallel(line l1, line l2) {
    // check coefficient a + b
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}

bool areSame(line l1, line l2) {
    // also check coefficient c
    return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS);
}

bool areIntersect(line l1, line l2, point *p) {
    if (areSame(l1, l2)) return false; // all points intersect
    if (areParallel(l1, l2)) return false; // no intersection

    // solve system of 2 linear algebraic equations with 2 unknowns
    p->x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if (fabs(l1.b) > EPS) // special case: test for vertical line avoid division by zero
        p->y = - (l1.a * p->x + l1.c) / l1.b;
    else
        p->y = - (l2.a * p->x + l2.c) / l2.b;
    return true;
}

int main(){
    int i,j,k, side;
    double x, y, halfhypot;

    point center, P, A,B,C,D, tmp;

    scanf("%lf %lf", &x, &y);
    center = point(x,y);
    scanf("%d", &side);
    scanf("%lf %lf", &x, &y);
    P = point(x,y);

    halfhypot = sqrt(side)/2.0;
    A = point(center.x-halfhypot, center.y+halfhypot);
    B = point(center.x+halfhypot, center.y+halfhypot);
    C = point(center.x+halfhypot, center.y-halfhypot);
    D = point(center.x-halfhypot, center.y-halfhypot);

    line a, b, c, d;

    distToLine(A, B, P, &tmp);
    pointsToLine(A, tmp, &a);
    distToLine(B, C, P, &tmp);
    pointsToLine(B, tmp, &b);
    distToLine(C, D, P, &tmp);
    pointsToLine(C, tmp, &c);
    distToLine(D, A, P, &tmp);
    pointsToLine(D, tmp, &d);

    bool bf, cf, df;
    point ab, ac, ad;

    bf = areIntersect(a, b, &ab);
    cf = areIntersect(a, c, &ac);
    df = areIntersect(a, d, &ad);

    if(!(bf&&cf&&df)) { printf("NO\n"); return 0; }

    if(!(ab==ac&&ab==ad)) { printf("NO\n"); return 0; }

    printf("YES\n");
    printf("%.1lf %.1lf\n", ab.x, ab.y);

    return 0;
}
