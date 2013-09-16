#include <stdio.h>

int n, x[35], y[35], score[35], dp[36][36];
char in[1000], name[100];

int recur(int i, int last){
    if(i==n){
        if(last!=-1 && hypot(x[last], y[last])-d>=0) return 0;
        return -10000;
    }
    //if(last!=-1 && dp[i][last][d]!=-1) return dp[i][last][d];
    int a=recur(i+1, last, d), b=-10000;
    double d2;
    if(last!=-1) d2 = hypot(x[i]-x[last], y[i]-y[last]);
    else d2 = hypot(x[last], y[last]);

    if(d>=d2) b=recur(i+1, i, d-d2);
    //if(last!=-1)
      //  dp[i][last][d]=(a>b)?a:b;
    return (a>b)?a:b;
}

int main(){
    int i, r, d, kase=1;
    while(sscanf(gets(in), "%d", &n)>0){
        if(n==0) return 0;
        for(i=0; i<n; i++) sscanf(gets(in), "%d %d %d", &x[i], &y[i], &score[i]);
        gets(in);
        r=0;
        printf("Race %d\n", kase++);
        while(strcmp(in, "# 0")!=0){
            sscanf(in, "%s %d", name, &d);
            printf("%s: %d\n", name, recur(0, -1, d));
            do{ gets(in); } while(strcmp(in, "")==0);
        }
    }
    return 0;
}

/*
5
750 -800 30
1500 0 50
750 750 60
-1250 750 70
-1000 -500 50
Chris 7000
Karl 6500
Tania 5000
# 0
4
500 0 10
0 500 10
-500 0 10
0 -500 10
Hanny 2100
Lizzie 1800
# 0
0
*/
