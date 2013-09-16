#include <stdio.h>
#include <math.h>

typedef struct {
    int x,y;
} point;

int n, x[1005], y[1005];
point dp[1005][2];

double dist(point p1, point p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

point recur(int i, int cur){
    if(dp[i][cur].x!=-1) return dp[i][cur];
    point p; p.x=0; p.y=0;
    if(i==n) { return dp[i][cur] = p; }
    point p3,p4;
    point p1 = p3 = recur(i+1, 0), p2 = p4 = recur(i+1, 1);
    p1.x+=x[i];
    p1.y+=y[i];
    p3.x-=x[i];
    p3.y-=y[i];
    p2.x+=x[i];
    p2.y+=y[i];
    p4.x-=x[i];
    p4.y-=y[i];
    double d1=dist(p, p1), d2=dist(p, p2), d3=dist(p, p3), d4=dist(p, p4);
    if(d1>=d2&&d1>=d3&&d1>=d4) return dp[i][cur] = p1;
    else if(d2>=d1&&d2>=d3&&d2>=d4) return dp[i][cur] = p2;
    else if(d3>=d1&&d3>=d2&&d3>=d4) return dp[i][cur] = p3;
    return dp[i][cur] = p4;
}

int main(){
    int i;
    point o, p, p1; o.x=0; o.y=0;
    double d;
    while(scanf("%d", &n)>0){
        if(n==0) return 0;
        n++;
        x[0]=0;y[0]=0;
        dp[0][0].x=-1;
        dp[0][1].x=-1;
        for(i=1; i<n; i++) {
            scanf("%d %d", &x[i], &y[i]);
            dp[i][0].x=-1;
            dp[i][1].x=-1;
        }
        dp[n][0].x=-1;
        dp[n][1].x=-1;
        p = recur(0, 0);

        d=dist(o, p);
        d=round(d*1000.0)/1000.0;
        printf("%.3lf\n", d);
    }
    return 0;
}
/*

3
1 1
0 1
-1 1
2
4 0
1 1
7
1 3
-2 -7
7 8
-2 9
-7 -3
4 -3
-2 -2
0

*/
