#include <stdio.h>
#include <math.h>

using namespace std;

#define EPS 1e-9

double PI = acos(-1.0);

struct point_i {
    int x,y;
    point_i() { x = 0; y = 0; }
    point_i(int _x, int _y) { x = _x; y = _y; }
};

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

double radToDeg(double a){
    return a * 180 / PI;
}

double degToRad(double a){
    return a * PI / 180.0;
}

double sideCosRule(double a, double b, double aAb){
    return sqrtf(a*a+b*b-2*a*b*cos(aAb));
}

double angleCosRule(double a, double b, double c){
    return acos((a*a+b*b-c*c)/(2*a*b));
}
