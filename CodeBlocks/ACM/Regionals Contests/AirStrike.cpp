#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, int> di;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000
#define EPS 1e-9
#define PI 3.141

struct point {
    double x,y;
    point(double _x, double _y) { x = _x; y = _y; }
    bool operator < (point other) {
        if(fabs(x - other.x) < EPS)
            return x < other.x;
        return y < other.y;
    }
};

double dist(point p1, point p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

vector<point> pts;
vector< di > dist1, dist2;
int taken[1010];

int main(){
    int n,  i,j,k, cnt, maxcnt, kase=1;
    double x,y, x2,y2, A, r1, r2, Aleft;

    while(scanf("%d", &n)>0){
        if(n==0) return 0;
        scanf("%lf %lf %lf %lf %lf", &x, &y, &x2, &y2, &A);
        struct point c1(x,y), c2(x2,y2);

        dist1.clear();
        dist2.clear();
        pts.clear();
        for(i=0; i<n; i++){
            scanf("%lf %lf", &x, &y);
            pts.push_back(point(x,y));
            dist1.push_back(di(dist(pts[i], c1), i));
            dist2.push_back(di(dist(pts[i], c2), i));
        }
        sort(dist1.begin(), dist1.end());
        sort(dist2.begin(), dist2.end());

        maxcnt=0;
        for(i=0; i<n; i++){
            r1 = dist1[i].first;
            if((Aleft = A-r1*r1*PI+EPS)<0) break;
            r2 = sqrt(Aleft/PI)+EPS;

            memset(taken, 0, (n+1)*sizeof(int));
            for(j=0; j<=i; j++) taken[dist1[j].second]=1;
            for(j=0; j<n; j++){
                if(dist2[j].first>r2) break;
                taken[dist2[j].second]=1;
            }
            for(cnt=0, j=0; j<n; j++) cnt+=taken[j];
            if(cnt>maxcnt) maxcnt=cnt;
        }

        for(i=0; i<n; i++){
            r1 = dist2[i].first;
            if((Aleft = A-r1*r1*PI+EPS)<0) break;
            r2 = sqrt(Aleft/PI)+EPS;

            memset(taken, 0, (n+1)*sizeof(int));
            for(j=0; j<=i; j++) taken[dist2[j].second]=1;
            for(j=0; j<n; j++){
                if(dist1[j].first>r2) break;
                taken[dist1[j].second]=1;
            }
            for(cnt=0, j=0; j<n; j++) cnt+=taken[j];
            if(cnt>maxcnt) maxcnt=cnt;
        }
        printf("%d. %d\n", kase++, n-maxcnt);
    }
    return 0;
}
