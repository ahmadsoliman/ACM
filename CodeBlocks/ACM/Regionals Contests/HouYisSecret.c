#include <stdio.h>
#include <math.h>

#define EPS 1e-9
#define max(x, y) ((x>y)?x:y)

int compare (const void * a, const void * b)
{
  double r = ( *(double*)a - *(double*)b );
  if(r<-EPS) return -1;
  if(r>EPS) return 1;
  return 0;
}

typedef struct{
    double a,b,c;
} triangle;

typedef struct {
    int x,y;
} point;

double dist(point p1, point p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

int n, i,j,k, l, x, y, done[6000], c, maxc;
double sides[3], m1, m2, m3;
triangle tris[6000];
point pts[20];

int main(){
    while(scanf("%d", &n)>0){
        if(n==0) return 0;
        for(i=0; i<n; i++){
            scanf("%d %d", &x, &y);
            pts[i].x=x;
            pts[i].y=y;
        }
        for(i=0, l=0; i<n; i++){
            for(j=i+1; j<n; j++){
                for(k=j+1; k<n; k++){
                    if(fabs(pts[i].x-pts[j].x)<EPS) m1=1000000;
                    else m1 = (pts[i].y-pts[j].y)/(pts[i].x-pts[j].x);

                    if(fabs(pts[j].x-pts[k].x)<EPS) m2=1000000;
                    else m2 = (pts[j].y-pts[k].y)/(pts[j].x-pts[k].x);

                    if(fabs(pts[i].x-pts[k].x)<EPS) m3=1000000;
                    else m3 = (pts[i].y-pts[k].y)/(pts[i].x-pts[k].x);

                    if(fabs(m1-m2)<EPS && fabs(m2-m3)<EPS) continue;

                    sides[0] = dist(pts[i], pts[j]);
                    sides[1] = dist(pts[i], pts[k]);
                    sides[2] = dist(pts[j], pts[k]);

                    qsort(sides, 3, sizeof(double), compare);

                    tris[l].a = sides[0];
                    tris[l].b = sides[1];
                    tris[l].c = sides[2];

                    l++;
                }
            }
        }

        maxc = 1;
        memset(done, 0, sizeof done);
        for(i=0; i<l-1; i++){
            if(done[i]) continue;
            c=1;
            for(j=i+1; j<l; j++){
                if(fabs(tris[i].a/tris[j].a - tris[i].b/tris[j].b) < EPS && fabs(tris[i].c/tris[j].c - tris[i].b/tris[j].b) < EPS){
                    done[j]=1;
                    c++;
                }
            }
            maxc = max(maxc , c);
        }

        printf("%d\n", maxc);
    }
    return 0;
}

